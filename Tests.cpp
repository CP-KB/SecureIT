#include "Tests.h"
#include <iostream>
#include <string>
#include <boost/archive/tmpdir.hpp>

#include <boost/archive/xml_oarchive.hpp>

#include "ModuleScan.h"


void Testing::SaveXMLtest()
{
    ModuleScan testms=genTestModuleScan();
    saveModuleScan(testms, "testModuleScan.xml");
}
void Testing::LoadXMLtest()
{
    ModuleScan testms;
    loadModuleScan(testms, "testModuleScan.xml");
}
void Testing::SystemExecute()
{
    system("ls");

}
void Testing::BoostExecutionTest()
{


}
void Testing::ExecutionTest()
{
    std::string outputstring;
    redi::ipstream lsExecution("ls");

    std::getline(lsExecution,outputstring);
    std::cout << lsExecution <<std:: endl;

    const redi::pstreams::pmode mode = redi::pstreams::pstdout|redi::pstreams::pstderr;
    redi::ipstream child("echo OUT1; sleep 1; echo ERR >&2; sleep 1; echo OUT2; ls", mode);
    char buf[1024];
    std::streamsize n;
    bool finished[2] = { false, false };
    while (!finished[0] || !finished[1])
    {
        if (!finished[0])
        {
            while ((n = child.err().readsome(buf, sizeof(buf))) > 0)
                std::cerr.write(buf, n).flush();
            if (child.eof())
            {
                finished[0] = true;
                if (!finished[1])
                    child.clear();
            }
        }

        if (!finished[1])
        {
            while ((n = child.out().readsome(buf, sizeof(buf))) > 0)
                std::cout.write(buf, n).flush();
            if (child.eof())
            {
                finished[1] = true;
                if (!finished[0])
                    child.clear();
            }
        }
    }

}
ModuleScan Testing::genTestModuleScan()
{
    ModuleScan ms;
    ms.Name="Test ModuleScan";
    ms.Description="This is a module used only for testing purposes.";
    ms.os.push_back("Windows XP"); ms.os.push_back("Windows Vista");
    ms.scan_variable.push_back(std::pair<std::string, std::string>("Test","test"));
    ms.Script="#!/bin/bash\necho \"hello world\\n\"";
    return ms;
}
