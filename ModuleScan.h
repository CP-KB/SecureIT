#ifndef MODULESCAN_H
#define MODULESCAN_H

#include <iomanip>
#include <iostream>
#include <fstream>

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

#include <boost/process.hpp>

#include <vector>
#include <string>
#include "Constants.hpp"
class ModuleScan
{
    friend class boost::serialization::access;
    friend std::ostream & operator<<(std::ostream &os, const ModuleScan &gp);
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */);


    public:
        ModuleScan();
        ModuleScan(std::string _name, std::string _description, std::vector<std::string> _os, std::vector<std::pair<std::string, std::string> > );

        std::string Name;
        std::string Description;
        std::vector<std::string> os;
        std::string Script;
        std::string ScriptType;

        std::vector<std::pair<std::string, std::string> > scan_variable;
        std::vector<std::pair<std::string, std::string> > result_variable;
        std::string result;

        bool bComplete;

        int Execute();
        std::string GetParsedScript;

    private:


};

void saveModuleScanXML(const ModuleScan &s, const char * filename);
void loadModuleScanXML(ModuleScan &s, const char * filename);
void saveModuleScanBIN(const ModuleScan &s, const char * filename);
void loadModuleScanBIN(ModuleScan &s, const char * filename);
#endif
