#ifndef TESTS_HPP
#define TESTS_HPP

#include "Module.h"
//#include "pstream.h"
#include <boost/process.hpp>
//#include <boost/process/child.hpp>
//#include <boost/process/async_system.hpp>
class Testing
{
    public:

        static void SaveXMLtest();
        static void LoadXMLtest();
        static void SystemExecute();
        static void BoostExecutionTest();
        static void ExecutionTest();
        static Module genTestModule();
};
#endif
