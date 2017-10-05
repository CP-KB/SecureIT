#include "ModuleScan.h"
ModuleScan::ModuleScan()
{

}
void gen_random(char *s, const int len) { //someone's code from https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}
int ModuleScan::Execute() //make and change executable bit on script -> execute it
{
    std::string sfilename;
    char *s;
    gen_random(s, 8);
    sfilename=s;
    std::ofstream ofs(sfilename + ".sh");
    ofs << this->Script;
    ofs.close();
    boost::process::ipstream pipe_stream;
    boost::process::ipstream pipe_stream2;
	//gcc --version
    //boost::process::child c("chmod +x test.sh", boost::process::std_out > pipe_stream);
    boost::process::system("chmod +x " + sfilename + ".sh");
    boost::process::system("./" + sfilename + ".sh");

    return 0;
}
ModuleScan::ModuleScan(std::string _name, std::string _description, std::vector<std::string> _os, std::vector<std::pair<std::string, std::string> > _scan_variable ) :
    Name(_name), Description(_description), os(_os), scan_variable(_scan_variable)
{}

template<class Archive> void ModuleScan::serialize(Archive & ar, const unsigned int /* file_version */)
{
        ar  & BOOST_SERIALIZATION_NVP(Name)
            & BOOST_SERIALIZATION_NVP(Description)
            & BOOST_SERIALIZATION_NVP(os)
            & BOOST_SERIALIZATION_NVP(Script)
            & BOOST_SERIALIZATION_NVP(ScriptType)
            & BOOST_SERIALIZATION_NVP(scan_variable);
            //& BOOST_SERIALIZATION_NVP(result_variable)
            //& BOOST_SERIALIZATION_NVP(result)

}

void saveModuleScanXML(const ModuleScan &s, const char * filename){ //from example code
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}
void loadModuleScanXML(ModuleScan &s, const char * filename) //from example code
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::xml_iarchive ia(ifs);
    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}
void saveModuleScanBIN(const ModuleScan &s, const char * filename){ //from example code
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::binary_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}
void loadModuleScanBIN(ModuleScan &s, const char * filename) //from example code
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::binary_iarchive ia(ifs);
    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}
