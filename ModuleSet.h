#ifndef MODULESET_H
#define MODULESET_H

#include "Module.h"

class ModuleSet
{
    friend class boost::serialization::access;
    friend std::ostream & operator<<(std::ostream &os, const Module &gp);
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */);

    public:
        std::vector<Module> Modules;
        std::string Name;
        std::string Filename;
        std::string Description;
        //std::vector<Module> Scans;
};

void saveModuleSetXML(const ModuleSet &s, const char * filename);
void loadModuleSetXML(ModuleSet &s, const char * filename);
void saveModuleSetBIN(const ModuleSet &s, const char * filename);
void loadModuleSetBIN(ModuleSet &s, const char * filename);
#endif // MODULESET_H
