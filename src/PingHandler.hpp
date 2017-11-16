#ifndef PROJECT_PINGHANDLER_H
#define PROJECT_PINGHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>

class PingHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;

};


#endif //PROJECT_PINGHANDLER_H
