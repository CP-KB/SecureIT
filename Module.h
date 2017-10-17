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

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

#include "Constants.hpp"
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
        std::string ScriptType;

        std::vector<std::pair<std::string, std::string> > scan_variable;
        std::vector<std::pair<std::string, std::string> > result_variable;
        std::string result;

        bool bSelected;
        bool bComplete;
        bool bRunning;

        int Execute();
        std::string GetParsedScript;

    private:


};

void saveModuleXML(const Module &s, const char * filename);
void loadModuleXML(Module &s, const char * filename);
void saveModuleBIN(const Module &s, const char * filename);
void loadModuleBIN(Module &s, const char * filename);
#endif
