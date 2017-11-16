#include "MainListener.hpp"
#include "EntityRequestHandlerFactory.hpp"

#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>

using Poco::ConsoleChannel;
using Poco::FormattingChannel;
using Poco::PatternFormatter;
using Poco::Logger;
using Poco::AutoPtr;

int MainListener::main(const std::vector<std::string>& args) {

    AutoPtr<ConsoleChannel> pCons(new ConsoleChannel);
    AutoPtr<PatternFormatter> pPF(new PatternFormatter);
    pPF->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");
    AutoPtr<FormattingChannel> pFC(new FormattingChannel(pPF, pCons));

    Logger::root().setChannel(pFC);

    Logger::root().setLevel(Poco::Message::PRIO_DEBUG);

    Poco::Net::HTTPServerParams* params = new Poco::Net::HTTPServerParams();
    params->setMaxQueued(50);
    params->setMaxThreads(4);
    params->setKeepAlive(false);

    Poco::Net::ServerSocket socket(8765); // argument is a port

    Poco::Net::HTTPServer server(new EntityRequestHandlerFactory(),
                                 socket,
                                 params);

    server.start();
    waitForTerminationRequest();
    server.stop();

    return 0;
}
