#include "ModuleAction.h"
ModuleAction::ModuleAction()
{

}
ModuleAction::ModuleAction(std::string _name, std::string _description, std::vector<std::string> _os, std::vector<std::pair<std::string, std::string> > _scan_variable ) :
    Name(_name), Description(_description), os(_os)
{}

template<class Archive> void ModuleAction::serialize(Archive & ar, const unsigned int /* file_version */)
{
        ar  & BOOST_SERIALIZATION_NVP(Name)
            & BOOST_SERIALIZATION_NVP(Description)
            & BOOST_SERIALIZATION_NVP(os)
            & BOOST_SERIALIZATION_NVP(Script)
            & BOOST_SERIALIZATION_NVP(ScriptType)
            & BOOST_SERIALIZATION_NVP(action_variable);
            //& BOOST_SERIALIZATION_NVP(result_variable)
            //& BOOST_SERIALIZATION_NVP(result)

}

void saveModuleScanXML(const ModuleAction &s, const char * filename){ //from example code
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}
void loadModuleScanXML(ModuleAction &s, const char * filename) //from example code
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::xml_iarchive ia(ifs);
    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}
void saveModuleScanBIN(const ModuleAction &s, const char * filename){ //from example code
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::binary_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}
void loadModuleScanBIN(ModuleAction &s, const char * filename) //from example code
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::binary_iarchive ia(ifs);
    // Restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}
