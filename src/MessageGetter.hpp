#ifndef HIGHLOADCUP_MESSAGEGETTER_H
#define HIGHLOADCUP_MESSAGEGETTER_H

#include <Poco/Net/HTTPRequestHandler.h>

class MessageGetter  : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;
};


#endif //HIGHLOADCUP_MESSAGEGETTER_H
