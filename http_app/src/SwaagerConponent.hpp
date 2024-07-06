#ifndef SwaggerComponent_hpp
#define SwaggerComponent_hpp

#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/macro/component.hpp"

class SwaggerComponent {
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)
    ([] {
        oatpp::swagger::DocumentInfo::Builder builder;

        builder.setTitle("User entity service")
            .setDescription("CRUD API Example project with swagger docs")
            .setVersion("1.0")
            .setContactName("Ivan Ovsyanochka")
            .setContactUrl("https://oatpp.io/")

            .setLicenseName("Apache License, Version 2.0")
            .setLicenseUrl("http://www.apache.org/licenses/LICENSE-2.0")
            .addServer("http://0.0.0.0:8000", "server on localhost")
            .addServer("http://192.168.31.113:8000", "Server on lan");

        return builder.build();
    }());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)
    ([] { return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH); }());
};

#endif