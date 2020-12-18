#include "Poco/Path.h"
#include "Poco/Process.h"
#include "Poco/Pipe.h"
#include "Poco/PipeStream.h"
#include "Poco/StreamCopier.h"
#include <iostream>
#include <fstream>

using Poco::Process;
using Poco::ProcessHandle;
using Poco::PipeInputStream;
void run(std::string url)
{
    Poco::Pipe outPipe;
    //Poco::Process::Args args;
    std::string cmd("ping");
    std::vector<std::string> args;
    args.push_back("-c 5");
    args.push_back(url);

    Poco::ProcessHandle ph(Poco::Process::launch(cmd, args, 0, &outPipe, 0));
    PipeInputStream istr(outPipe);
    std::ofstream ostr("ping.txt");
    Poco::StreamCopier::copyStream(istr, ostr);
    //int rc = ph.wait();
    ostr.close();
}

