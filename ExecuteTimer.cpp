#include "ExecuteTimer.h"
#include "Forms/MainWindow.h"
#include <iostream>
#include <boost/thread/future.hpp>
#include <boost/process/async.hpp>
ExecuteTimer::ExecuteTimer(MainWindow *mw)
{
    this->mw=mw;
}
void ExecuteTimer::Notify()
{
    //mw->
    //std::cout << "Timer Tick\n";
    bool StillRunning;
    if (mw->bRunning)
    {
        for (unsigned int i=0; i<mw->mainSet.Modules.size(); i++)
        {
            if (mw->mainSet.Modules[i].bRunMe==true)
            {
                StillRunning=true;
                mw->mainSet.Modules[i].bRunning=true;
                mw->mainSet.Modules[i].bComplete=false;
                mw->mainSet.Modules[i].bRunMe=false;
                mw->UpdateListItem(i);
                std::cout << "Executing Module #" << i << std::endl;
                mw->mainSet.Modules[i].Execute(i);
            }else if (mw->mainSet.Modules[i].bRunning==true)
            {
                StillRunning=true;
                if (!mw->mainSet.Modules[i].process_handle->child_process.running())
                {
                    std::cout << "Done Executing Module #" << i << std::endl; //<< "Valid:" << mw->mainSet.Modules[i].process_handle->future_result2. << std::endl;
                    //std::string testStr = mw->mainSet.Modules[i].process_handle->future_result.valid()
                    mw->mainSet.Modules[i].process_handle->ios.run();
                    mw->mainSet.Modules[i].run_output=mw->mainSet.Modules[i].process_handle->future_result.get();
                    std::cout << mw->mainSet.Modules[i].run_output;
                    mw->mainSet.Modules[i].bRunning=false;
                    mw->mainSet.Modules[i].bSuccess=true;
                    mw->mainSet.Modules[i].bComplete=true;
                    mw->mainSet.Modules[i].ExecutionCleanup(i);
                    mw->UpdateListItem(i);
                }
            }
            //UpdateListItem(i);
        }
    }
    if (!StillRunning)
    {
        wxTimer::Stop();
    }
}

void ExecuteTimer::Start()
{
    wxTimer::Start(10);
}
