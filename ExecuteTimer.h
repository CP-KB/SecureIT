#ifndef EXECUTETIMER_H
#define EXECUTETIMER_H
//#include "Forms/MainWindow.h"
//#include "MainWindow.h"
#include "wx/timer.h"
class MainWindow;

class ExecuteTimer : public wxTimer
{
    MainWindow* mw;
public:
    ExecuteTimer(MainWindow *mw);
    void Notify();
    void Start();
};
#endif // EXECUTETIMER_H
