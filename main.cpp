//  COPYRIGHTS held by Logan Thomas Bateman
//
//  Software designed to scan and secure operating systems
//  Designed with modularity in mind.
//
#include "main.h"

//(*AppHeaders
#include "Forms/MainWindow.h"
#include <wx/image.h>
//*)

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	if ( wxsOK )
	{
		MainWindow* Frame = new MainWindow(0);
		Frame->Show();
		SetTopWindow(Frame);
	}
	//*)
	return wxsOK;
}
