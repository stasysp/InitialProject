#ifndef HIGHLOADCUP_MESSAGEADDER_H
#define HIGHLOADCUP_MESSAGEADDER_H

#include <Poco/Net/HTTPRequestHandler.h>

class MessageAdder : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;
};


#endif //HIGHLOADCUP_MESSAGEADDER_H
