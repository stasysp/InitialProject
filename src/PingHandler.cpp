#include "PingHandler.hpp"

#include <json.hpp>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>


namespace {
    char* getPingResponce() {
        char resp[6] = "pong\n";
        char* message = resp;
        return message;
    }
}

void PingHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    std::ostream& ostr = response.send();
    ostr << getPingResponce();
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
}
