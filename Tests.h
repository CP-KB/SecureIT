#ifndef TESTS_HPP
#define TESTS_HPP

#include "ModuleScan.h"
#include "pstream.h"
class Testing
{
    public:

        static void SaveXMLtest();
        static void LoadXMLtest();
        static void SystemExecute();
        static void BoostExecutionTest();
        static void ExecutionTest();
        static ModuleScan genTestModuleScan();
};
#endif
