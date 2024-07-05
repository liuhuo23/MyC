#ifndef ERRORHANDLE_HPP
#define ERRORHANDLE_HPP
#include "oatpp/web/server/handler/ErrorHandler.hpp"
#include "oatpp/web/protocol/http/outgoing/ResponseFactory.hpp"
#include "oatpp/web/mime/ContentMappers.hpp"

class ErrorHandler : public oatpp::web::server::handler::DefaultErrorHandler {
private:
    typedef oatpp::web::protocol::http::outgoing::Response OutgoingResponse;
    typedef oatpp::web::protocol::http::Status Status;
    typedef oatpp::web::protocol::http::outgoing::ResponseFactory ResponseFactory;

private:
    std::shared_ptr<oatpp::web::mime::ContentMappers> m_appers;

public:
    ErrorHandler(const std::shared_ptr<oatpp::web::mime::ContentMappers>& mappers);
    std::shared_ptr<OutgoingResponse> renderError(
        const HttpServerErrorStacktrace& statcktrace) override;
};

#endif