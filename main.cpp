//
//  Software designed to scan and secure operating systems
//  Designed with modularity in mind.
//
#include "main.h"

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{

    //MainWindow *winMain=new MainWindow( APP_NAME, wxPoint(50, 50), wxSize(450, 340) );
    MainWin *winMain=new MainWin();
    winMain->Show(true);

    return true;
}
