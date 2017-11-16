#include "EntityRequestHandlerFactory.hpp"
#include "MessageGetter.hpp"
#include "MessageAdder.hpp"
#include "PingHandler.hpp"

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/URI.h>
#include <Poco/Logger.h>

#include <regex>

namespace {
    std::regex userPathRegex("^/message");
}

Poco::Net::HTTPRequestHandler *EntityRequestHandlerFactory::createRequestHandler(
        const Poco::Net::HTTPServerRequest &request) {

    Poco::Logger& logger = Poco::Logger::get("HTTPRequestHandler");

    std::smatch sm;
    const auto uri = Poco::URI(request.getURI());

    logger.debug("Processing request '" + request.getMethod() + " " + uri.getPath() +
                         "' with params '" + uri.getQuery() + "'");

    if (std::regex_match(uri.getPath(), sm, userPathRegex)) {
        if (request.getMethod() == "GET") {
            return new MessageGetter();
        } else if (request.getMethod() == "POST") {
            return new MessageAdder();
        }
    }

    if (uri.getPath() == "/ping") {
        return new PingHandler();
    }

    return nullptr;
}
