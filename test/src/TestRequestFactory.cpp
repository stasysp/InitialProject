#include <gtest/gtest.h>
#include <src/MessageAdder.hpp>
#include <src/MessageGetter.hpp>
#include "src/EntityRequestHandlerFactory.hpp"

#include "Mocks.hpp"


TEST(TEST_REQUEST_FACTORY, TEST_PARSE_URI) {
    EntityRequestHandlerFactory f;

    ServerRequestMock request;

    auto h = f.createRequestHandler(request);

    ASSERT_EQ(h, nullptr);
}

TEST(TEST_REQUEST_FACTORY, TEST_WRONG_URI) {
    EntityRequestHandlerFactory f;

    std::string uri("/something");

    ServerRequestMock request;

    setMocks(request, "GET", uri);

    auto h = f.createRequestHandler(request);

    ASSERT_EQ(h, nullptr);
}


TEST(TEST_REQUEST_FACTORY, TEST_GET_URI_NONEMPTY) {
    EntityRequestHandlerFactory f;

    std::string uri("/message");

    ServerRequestMock request;

    setMocks(request, "GET", uri);

    auto h = f.createRequestHandler(request);

    ASSERT_NE(h, nullptr);
    auto cp = dynamic_cast<MessageGetter*>(h);
    ASSERT_NE(cp, nullptr);
}

TEST(TEST_REQUEST_FACTORY, TEST_POST_URI_NONEMPTY) {
    EntityRequestHandlerFactory f;

    std::string uri("/message");

    ServerRequestMock request;

    setMocks(request, "POST", uri);

    auto h = f.createRequestHandler(request);

    ASSERT_NE(h, nullptr);
    auto cp = dynamic_cast<MessageAdder*>(h);
    ASSERT_NE(cp, nullptr);
}


TEST(TEST_REQUEST_FACTORY, TEST_GET_URI_WITH_PARAMS) {
    EntityRequestHandlerFactory f;

    std::string uri("/message?user=pavel");

    ServerRequestMock request;

    setMocks(request, "GET", uri);

    auto h = f.createRequestHandler(request);

    ASSERT_NE(h, nullptr);
    auto cp = dynamic_cast<MessageGetter*>(h);
    ASSERT_NE(cp, nullptr);
}

