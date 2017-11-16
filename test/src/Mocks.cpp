#include "Mocks.hpp"

using ::testing::AtLeast;
using ::testing::ReturnRef;

void setMocks(ServerRequestMock& request,
              const std::string& method,
              const std::string& uri) {
    request.setMethod(method);
    request.setURI(uri);
}

void setReqBody(ServerRequestMock& request,
                std::istringstream& body) {
    EXPECT_CALL(request, stream())
            .WillRepeatedly(ReturnRef(body));
}

void setRespHandler(ServerResponseMock& responce,
                    std::ostringstream& res) {
    EXPECT_CALL(responce, send())
            .WillRepeatedly(ReturnRef(res));
}
