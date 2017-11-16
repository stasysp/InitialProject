#ifndef PROJECT_MOCKS_H
#define PROJECT_MOCKS_H

#include <gmock/gmock.h>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerRequestImpl.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerSession.h>
#include <Poco/Net/StreamSocket.h>

#include <string>

class ServerResponseMock : public Poco::Net::HTTPServerResponse {

public:

    MOCK_METHOD0(sendContinue, void());

    MOCK_METHOD0(send, std::ostream &());

    MOCK_METHOD2(sendFile, void(const std::string &path, const std::string &mediaType));

    MOCK_METHOD2(sendBuffer, void(const void *pBuffer, std::size_t length));

    MOCK_METHOD1(redirect, void(const std::string &uri));

    MOCK_METHOD1(requireAuthentication, void(const std::string &realm));

    MOCK_CONST_METHOD0(sent, bool());

    MOCK_METHOD2(redirect, void(const std::string &uri, HTTPStatus status));

};

class ServerRequestMock : public Poco::Net::HTTPServerRequest {
public:

    MOCK_METHOD0(stream, std::istream &());
    MOCK_CONST_METHOD0(expectContinue, bool());
    MOCK_CONST_METHOD0(clientAddress, const Poco::Net::SocketAddress &());

    MOCK_CONST_METHOD0(serverAddress, const Poco::Net::SocketAddress &());
    MOCK_CONST_METHOD0(serverParams, const Poco::Net::HTTPServerParams& ());
    MOCK_CONST_METHOD0(response, Poco::Net::HTTPServerResponse &());

    MOCK_CONST_METHOD0(secure, bool());
};


void setMocks(ServerRequestMock& request,
              const std::string& method,
              const std::string& uri);

void setRespHandler(ServerResponseMock& responce,
                    std::ostringstream& res);

void setReqBody(ServerRequestMock &request,
                std::istringstream &body);

#endif //PROJECT_MOCKS_H
