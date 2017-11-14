#ifndef MODULESCAN_H
#define MODULESCAN_H

#include <boost/process.hpp>

#include <boost/serialization/string.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/vector.hpp>

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

//#include <boost/thread/future.hpp>
#include <future>
#include <boost/process/async.hpp>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

#include "Constants.hpp"
struct BProcess
{
//public:
//    BProcess();
    boost::asio::io_service ios;
    boost::process::child child_process;
    std::future<std::string> future_result;
    //boost::unique_future<std::string> future_result2;
};
class Module
{
    friend class boost::serialization::access;
    friend std::ostream & operator<<(std::ostream &os, const Module &gp);
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */);


    public:
        Module();
        Module(std::string _name, std::string _description, std::vector<std::string> _os, std::vector<std::pair<std::string, std::string> > );

        std::string Name;
        std::string Description;
        std::vector<std::string> os;
        std::string Script;
        std::string UnScript;
        std::string ScriptExtension;
        int Type;
        int RunOrder; //used to specify if other scripts need to run before or after

        std::vector<std::pair<std::string, std::string> > input_variables;
        std::vector<std::pair<std::string, std::string> > output_variables;


        bool bChecked;
        bool bComplete;
        bool bRunning;
        bool bRunMe; //set to true to tell the timer to start the script
        bool bSuccess;
        bool bFailure;


        int Execute(unsigned int id);
        void ExecutionCleanup(unsigned int id);
        std::string GetParsedScript;
        BProcess *process_handle;
        //std::future<std::string> future_result=std::future<std::string>();
        std::string run_output;
    private:


};

void saveModuleXML(const Module &s, const char * filename);
void loadModuleXML(Module &s, const char * filename);
void saveModuleBIN(const Module &s, const char * filename);
void loadModuleBIN(Module &s, const char * filename);
#endif
