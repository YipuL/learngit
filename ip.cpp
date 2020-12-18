//
// Created by piao on 2020/12/17.
//

#include "Poco/Path.h"
#include "Poco/Process.h"
#include "Poco/Pipe.h"
#include "Poco/PipeStream.h"
#include "Poco/StreamCopier.h"
#include <sstream>
#include <iostream>
#include <fstream>

using Poco::Process;
using Poco::ProcessHandle;
using Poco::PipeInputStream;
void run()
{
    Poco::Pipe outPipe;
    //Poco::Process::Args args;
    std::string cmd("ifconfig");
    std::vector<std::string> args;

    Poco::ProcessHandle ph(Poco::Process::launch(cmd, args, 0, &outPipe, 0));
    PipeInputStream istr(outPipe);
    //Poco::StreamCopier::copyStream(istr, i_str);
    //std::string name;
    char name[10];
    istr.get(name,10);

    std::cout << name << std::endl;


    //int rc = ph.wait();
}
//int main()
//{
//    run();
//    return 0;
//}