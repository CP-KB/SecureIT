#ifndef MODULEACTION_H
#define MODULEACTION_H

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

#include <vector>
#include <string>
#include "Constants.hpp"

class ModuleAction
{

    friend class boost::serialization::access;
    friend std::ostream & operator<<(std::ostream &os, const ModuleAction &gp);
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */);

    public:
        ModuleAction();
        ModuleAction(std::string _name, std::string _description, std::vector<std::string> _os, std::vector<std::pair<std::string, std::string> > );

        std::string Name;
        std::string Description;
        std::vector<std::string> os;
        std::string Script;
        std::string UnScript;
        std::string ScriptType;

        std::vector<std::pair<std::string, std::string> > action_variable;
        std::vector<std::pair<std::string, std::string> > result_variable;
        std::string result;

        bool bComplete;

        int Execute();
        std::string GetParsedScript;
};
#endif
