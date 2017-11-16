#include "MessageGetter.hpp"
#include "MessagesQueue.hpp"

#include <json.hpp>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/NetException.h>
#include <Poco/Logger.h>
#include <Poco/URI.h>

using json = nlohmann::json;

void MessageGetter::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Poco::Logger& logger = Poco::Logger::get("MessageGetter");

    const auto params = Poco::URI(request.getURI()).getQueryParameters();

    auto iuser = find_if(params.begin(), params.end(), [](const auto& p) {return p.first == "user";});

    if (iuser == params.end()) {
        response.setStatus(Poco::Net::HTTPResponse::HTTP_REASON_BAD_REQUEST);
        response.send() << "'user' is required";
        return;
    }

    auto user = iuser->second;

    logger.debug("Got request for user " + user);

    auto& queue = singleton<MessagesQueue>();

    if (queue.hasNext(user)) {
        response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        auto res = queue.getNext(user);

        std::ostream& ostr = response.send();
        ostr << json{{"id", res.id()}, {"dest", res.dest()}, {"message", res.message()}};
        return;
    }
    response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
    response.send() << "No message for user " << user << '\n';
}
