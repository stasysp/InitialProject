#ifndef HIGHLOADCUP_ENTITYREQUESTHANDLER_H
#define HIGHLOADCUP_ENTITYREQUESTHANDLER_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>


class EntityRequestHandlerFactory  : public Poco::Net::HTTPRequestHandlerFactory {
public:
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(
            const Poco::Net::HTTPServerRequest& request) override;
};


#endif //HIGHLOADCUP_ENTITYREQUESTHANDLER_H
