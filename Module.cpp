#include "Module.h"
Module::Module()
{

}
std::string gen_random_string(const int len) { //modified someone's code from https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
    std::string s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s+= alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return s;
}
bool gen_scanrun_directory()
{
    //boost::filesystem::path dir("run/scans");
	if(boost::filesystem::create_directories("run/scans")) {
		std::cout << "Success" << "\n";
		return true;
	}
}
int Module::Execute() //make and change executable bit on script -> execute it
{
    gen_scanrun_directory();
    std::string sfilename;
    sfilename= "run/scans/" + gen_random_string(8) + ".sh";
    if (!std::ifstream(sfilename)) //check for existence of file
    {
        std::ofstream ofs;
        ofs.open(sfilename); //open file for writing
        ofs << this->Script;
        ofs.close();
    }



    //boost::process::ipstream pipe_stream;
    //boost::process::ipstream pipe_stream2;
	//gcc --version
    //boost::process::child c("chmod +x test.sh", boost::process::std_out > pipe_stream);
    boost::process::system("chmod +x " + sfilename);
    boost::process::system("./" + sfilename);
    boost::process::system("rm ./" + sfilename);
    return 0;
}
Module::Module(std::string _name, std::string _description, std::vector<std::string> _os, std::vector<std::pair<std::string, std::string> > _input_variables ) :
    Name(_name), Description(_description), os(_os), input_variables(_input_variables)
{}

template<class Archive> void Module::serialize(Archive & ar, const unsigned int /* file_version */)
{
        ar  & BOOST_SERIALIZATION_NVP(Name)
            & BOOST_SERIALIZATION_NVP(Description)
            & BOOST_SERIALIZATION_NVP(Type)
            & BOOST_SERIALIZATION_NVP(os)
            & BOOST_SERIALIZATION_NVP(bSelected)
            & BOOST_SERIALIZATION_NVP(bComplete)
            & BOOST_SERIALIZATION_NVP(Script)
            & BOOST_SERIALIZATION_NVP(UnScript)
            & BOOST_SERIALIZATION_NVP(ScriptExtension)
            & BOOST_SERIALIZATION_NVP(input_variables)
            & BOOST_SERIALIZATION_NVP(output_variables);
            //& BOOST_SERIALIZATION_NVP(result_variable)
            //& BOOST_SERIALIZATION_NVP(result)

}

void saveModuleXML(const Module &s, const char * filename){ //from example code
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}
void loadModuleXML(Module &s, const char * filename) //from example code
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::xml_iarchive ia(ifs);
    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}
void saveModuleBIN(const Module &s, const char * filename){ //from example code
    // make an archive
    std::ofstream ofs(filename);
    assert(ofs.good());
    boost::archive::binary_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(s);
}
void loadModuleBIN(Module &s, const char * filename) //from example code
{
    // open the archive
    std::ifstream ifs(filename);
    assert(ifs.good());
    boost::archive::binary_iarchive ia(ifs);
    // restore the schedule from the archive
    ia >> BOOST_SERIALIZATION_NVP(s);
}
