#include "MainWindow.h"
#include "Constants.hpp"

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{

    CreateControls();


}

bool MyApp::OnInit()
{

    MainWindow *winMain=new MainWindow( APP_NAME, wxPoint(50, 50), wxSize(450, 340) );

    winMain->Show(true);

    return true;
}

void MainWindow::OnExit(wxCommandEvent& event)
{
    Close();
}
void MainWindow::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    (void)wxMessageBox(APP_NAME + "\n(c)" + APP_DATE + " " + APP_AUTHORS,
                       APP_DESCRIPTION,
                       wxOK | wxICON_INFORMATION);
}
void MainWindow::OnTestExecution(wxCommandEvent& WXUNUSED(event))
{
    Testing::ExecutionTest();
}
void MainWindow::OnTestSerializationLoad(wxCommandEvent& WXUNUSED(event))
{
    Testing::LoadXMLtest();
}
void MainWindow::OnTestSerializationSave(wxCommandEvent& WXUNUSED(event))
{
    Testing::SaveXMLtest();
}
void MainWindow::CreateControls()
{
    wxStaticBoxSizer* groupSizer(new wxStaticBox(this,wxID_ANY,"Combo"), wxVERTICAL);
    mainSizer=new wxBoxSizer(wxVERTICAL);
    mainPanel=new wxPanel(this);
    mainSizer->Add(groupSizer,1, wxEXPAND|wxALL, 4);
    mainPanel->SetSizer(mainSizer);
    CreateMenu();
    wxComboBox osCombo(mainPanel,Combo_OS,"Operating System",wxPoint(0,0));
    groupSizer->Add(osCombo, wxSizerFlags().Border(wxALL, 4));
    groupSizer->Add
}

//Sets the events for the different menu Items
wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(Menu_File_Exit,     MainWindow::OnExit)
    //EVT_MENU(Menu_File_Open,     MainWindow::OnOpen)
    //EVT_MENU(Menu_File_Save,     MainWindow::OnSave)
    //EVT_MENU(Menu_File_SaveAs,     MainWindow::OnSaveAs)
    //EVT_MENU(Menu_File_Close,     MainWindow::OnClose)
    //EVT_MENU(Menu_Edit_Copy,     MainWindow::OnCopy)
    //EVT_MENU(Menu_Edit_Cut,     MainWindow::OnCut)
    //EVT_MENU(Menu_Edit_Paste,     MainWindow::OnPaste)
    EVT_MENU(Menu_Help_About,     MainWindow::OnAbout)

    EVT_MENU(Menu_Test_Execution, MainWindow::OnTestExecution)
    EVT_MENU(Menu_Test_Serialization_Load, MainWindow::OnTestSerializationLoad)
    EVT_MENU(Menu_Test_Serialization_Save, MainWindow::OnTestSerializationSave)
wxEND_EVENT_TABLE()

void MainWindow::CreateMenu()
{
    wxMenu *menuFile= new wxMenu();
    wxMenu *menuAction= new wxMenu();
    wxMenu *menuHelp=new wxMenu();
    wxMenu *menuTest=new wxMenu();

    menuFile->Append(Menu_File_Open, wxT("Open"), wxT("Open a preconfigured state"));
    menuFile->Append(Menu_File_Save, wxT("Save"), wxT("Save a state"));
    menuFile->Append(Menu_File_Open, wxT("Save as"), wxT("Save a state"));
    menuFile->AppendSeparator();
    menuFile->Append(Menu_File_Exit, wxT("E&xit\tAlt-X"), wxT("This closes the application"));

    menuHelp->Append(Menu_Help_About, wxT("A&bout\tAlt-A"), wxT("Show About Page"));

    menuTest->Append(Menu_Test_Execution, "Execution Test", "Do an execution test");
    menuTest->Append(Menu_Test_Serialization_Load, "Serialization Load Test", "Load an XML");
    menuTest->Append(Menu_Test_Serialization_Save, "Serialization Save Test", "Save an XML");

    menuBar=new wxMenuBar();
    menuBar->Append(menuFile,wxT("&File"));
    menuBar->Append(menuAction,wxT("&Action"));
    menuBar->Append(menuHelp,wxT("&Help"));
    menuBar->Append(menuTest, wxT("&Test"));
    //menuBar.

    SetMenuBar(menuBar);
}
