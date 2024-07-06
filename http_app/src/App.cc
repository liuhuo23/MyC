#include <iostream>
#include "AppComponent.hpp"
#include "controller/StaticController.hpp"
#include "controller/UserController.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp-swagger/Controller.hpp"

void run() {
    AppComponent components;
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
    oatpp::web::server::api::Endpoints docEndpoints;

    docEndpoints.append(router->addController(UserController::createShared())->getEndpoints());
    router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
    router->addController(StaticController::createShared());

    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionhandler);
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);
    oatpp::network::Server server(connectionProvider, connectionhandler);

    OATPP_LOGd("Server", "Running on port {}...",
               connectionProvider->getProperty("port").toString());
    server.run();

    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>,
                    dbConnectionProvider);
    dbConnectionProvider->stop();
}

int main() {
    oatpp::Environment::init();
    run();
    /* Print how many objects were created during app running, and what have left-probably leaked */
    /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag
     * for better performance */
    std::cout << "\nEnvironment:\n";
    std::cout << "objectsCount = " << oatpp::Environment::getObjectsCount() << "\n";
    std::cout << "objectsCreated = " << oatpp::Environment::getObjectsCreated() << "\n\n";

    oatpp::Environment::destroy();

    return 0;
}