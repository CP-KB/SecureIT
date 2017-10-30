#include "ExecuteTimer.h"
#include <iostream>
ExecuteTimer::ExecuteTimer(MainWindow *mw)
{
    this->mw=mw;
}
void ExecuteTimer::Notify()
{
    //mw->
    std::cout << "Timer Tick\n";
}

void ExecuteTimer::Start()
{
    wxTimer::Start(10);
}
