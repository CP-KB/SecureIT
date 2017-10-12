#include "MainWindow.h"

//(*InternalHeaders(MainWindow)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(MainWindow)
const long MainWindow::ID_OSCHOICE = wxNewId();
const long MainWindow::ID_BUTTON1 = wxNewId();
const long MainWindow::ID_LISTCTRL1 = wxNewId();
const long MainWindow::Menu_File_Open = wxNewId();
const long MainWindow::Menu_File_Save = wxNewId();
const long MainWindow::Menu_File_SaveAs = wxNewId();
const long MainWindow::Menu_File_Exit = wxNewId();
const long MainWindow::ID_MENUITEM7 = wxNewId();
const long MainWindow::ID_MENUITEM8 = wxNewId();
const long MainWindow::Menu_Help_About = wxNewId();
const long MainWindow::ID_MENUITEM1 = wxNewId();
const long MainWindow::ID_MENUITEM2 = wxNewId();
const long MainWindow::ID_MENUITEM3 = wxNewId();
const long MainWindow::ID_MENUITEM4 = wxNewId();
const long MainWindow::ID_MENUITEM5 = wxNewId();
const long MainWindow::ID_MENUITEM6 = wxNewId();
const long MainWindow::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MainWindow,wxFrame)
	//(*EventTable(MainWindow)
	//*)
END_EVENT_TABLE()

MainWindow::MainWindow(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(MainWindow)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxMenuBar* mainMenuBar;

	Create(parent, id, _("SecureIT - by Logan Bateman"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER, _T("id"));
	SetClientSize(wxSize(388,193));
	SetMinSize(wxSize(-1,-1));
	SetMaxSize(wxSize(-1,-1));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	osChoice = new wxChoice(this, ID_OSCHOICE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_OSCHOICE"));
	osChoice->Append(_("Auto Detect"));
	osChoice->Append(_("Windows 7"));
	osChoice->Append(_("Windows Vista"));
	osChoice->Append(_("Ubuntu 14 x86_64"));
	osChoice->Append(_("Ubuntu 14 i386"));
	BoxSizer2->Add(osChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	Button1 = new wxButton(this, ID_BUTTON1, _("Scan/Actions"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_LEFT, 5);
	mainListCtrl = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer1->Add(mainListCtrl, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	mainMenuBar = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem3 = new wxMenuItem(Menu1, Menu_File_Open, _("Open"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem3);
	MenuItem4 = new wxMenuItem(Menu1, Menu_File_Save, _("Save"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem4);
	MenuItem5 = new wxMenuItem(Menu1, Menu_File_SaveAs, _("Save As"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem5);
	Menu1->AppendSeparator();
	MenuItem1 = new wxMenuItem(Menu1, Menu_File_Exit, _("Exit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	mainMenuBar->Append(Menu1, _("&File"));
	Menu3 = new wxMenu();
	mainMenuBar->Append(Menu3, _("Edit"));
	Menu4 = new wxMenu();
	MenuItem12 = new wxMenuItem(Menu4, ID_MENUITEM7, _("New Scan Module"), wxEmptyString, wxITEM_NORMAL);
	Menu4->Append(MenuItem12);
	MenuItem13 = new wxMenuItem(Menu4, ID_MENUITEM8, _("New Action Module"), wxEmptyString, wxITEM_NORMAL);
	Menu4->Append(MenuItem13);
	mainMenuBar->Append(Menu4, _("Module"));
	Menu2 = new wxMenu();
	MenuItem2 = new wxMenuItem(Menu2, Menu_Help_About, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	mainMenuBar->Append(Menu2, _("Help"));
	Menu5 = new wxMenu();
	MenuItem6 = new wxMenuItem(Menu5, ID_MENUITEM1, _("Execution Test"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem6);
	MenuItem7 = new wxMenuItem(Menu5, ID_MENUITEM2, _("Serialization Save"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem7);
	MenuItem8 = new wxMenuItem(Menu5, ID_MENUITEM3, _("Serialization Load"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem8);
	MenuItem9 = new wxMenuItem(Menu5, ID_MENUITEM4, _("ListCtrl Test"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem9);
	MenuItem10 = new wxMenuItem(Menu5, ID_MENUITEM5, _("Generate List Test"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem10);
	MenuItem11 = new wxMenuItem(Menu5, ID_MENUITEM6, _("Test wxStyleListCtrl"), wxEmptyString, wxITEM_NORMAL);
	Menu5->Append(MenuItem11);
	mainMenuBar->Append(Menu5, _("Test"));
	SetMenuBar(mainMenuBar);
	StatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar);
	openFileDialog = new wxFileDialog(this, _("Select files"), wxEmptyString, wxEmptyString, _("XYZ files (*.xyz)|*.xyz"), wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_MULTIPLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	saveFIleDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	SetSizer(BoxSizer1);
	Layout();
	Center();

	Connect(Menu_File_Open,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnFileOpen);
	Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnNewScanModule);
	Connect(Menu_Help_About,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnAbout);
	Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnTestGenList);
	Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnTestStyleText);
	//*)

    /*//MY own non generated CODE
    // Set the lexer to the C++ lexer
    mainStyledTextBox->SetLexer(wxSTC_LEX_BASH);
    std::cout << "Hi, is this working\n";

    // Set the color to use for various elements
    mainStyledTextBox->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColor(60, 162, 2));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColor(0, 0, 255));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_STRING, wxColor(255, 60, 10));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_WORD, wxColor(0, 0, 255));

    mainUnCodeStyledTextBox->SetLexer(wxSTC_LEX_CPP);
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColor(60, 162, 2));
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColor(0, 0, 255));
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_STRING, wxColor(255, 60, 10));
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_WORD, wxColor(0, 0, 255));*/
}

MainWindow::~MainWindow()
{
	//(*Destroy(MainWindow)
	//*)
}


void MainWindow::OnAbout(wxCommandEvent& event)
{
}

void MainWindow::OnButton1Click(wxCommandEvent& event)
{
    wxListItem testListItem;
    //testListItem->
    if (!mainListCtrl->EnableCheckboxes(true)) {std::cout << "Error: No Checkbox support.\n";}

    testListItem.SetText(wxT("Test Item #1"));
    testListItem.SetColumn(0);
    testListItem.SetId(0);
    //testListItem.
    mainListCtrl->AppendColumn("TestColumn");
    mainListCtrl->AppendColumn("TestColumn2");
    //mainListCtrl
    mainListCtrl->InsertItem(testListItem);
}
void MainWindow::GenerateList()
{
    if (!mainListCtrl->EnableCheckboxes(true)) {std::cout << "Error: No Checkbox support.\n";}
    mainListCtrl->ClearAll();
    wxListItem ListItem;
    mainListCtrl->AppendColumn("Name");
    mainListCtrl->AppendColumn("Description");

    for (int i=0; i<mainSet.Modules.size(); i++)
    {

        ListItem.SetColumn(0);
        ListItem.SetText(mainSet.Modules[i].Name);
        ListItem.SetId(i);
        mainListCtrl->InsertItem(ListItem);
        ListItem.SetColumn(1);
        ListItem.SetText(mainSet.Modules[i].Description);
        mainListCtrl->InsertItem(ListItem);
    }

}

void MainWindow::OnFileOpen(wxCommandEvent& event)
{
        //wxFileDialog openFileDialog(this, _("Open XYZ file"), "", "", "XYZ files (*.xyz)|*.xyz", wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_MULTIPLE);
    if (openFileDialog->ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
}

void MainWindow::OnTestGenList(wxCommandEvent& event)
{
    mainSet.Modules.push_back(Testing::genTestModule());
    if (!mainListCtrl->EnableCheckboxes(true)) {std::cout << "Error: No Checkbox support.\n";}
    mainListCtrl->ClearAll();
    wxListItem ListItem;
    mainListCtrl->AppendColumn("Name");
    mainListCtrl->AppendColumn("Description");

    for (int i=0; i<mainSet.Modules.size(); i++)
    {

        ListItem.SetColumn(0);
        ListItem.SetText(mainSet.Modules[i].Name);
        ListItem.SetId(i);
        mainListCtrl->InsertItem(ListItem);
        ListItem.SetColumn(1);
        ListItem.SetText(mainSet.Modules[i].Description);
        mainListCtrl->InsertItem(ListItem);
        mainListCtrl->SetItem(ListItem, 1, "18:00"); //want this for col. 2
    }


}

void MainWindow::OnTestStyleText(wxCommandEvent& event)
{
    std::cout << "Test of OnTextStyleText\n";
    FrmScriptEditor *EditWin=new FrmScriptEditor(this);
    EditWin->Show(true);
}

void MainWindow::OnNewScanModule(wxCommandEvent& event)
{
    Module newmodule;
    newmodule.Name="New Module";
    newmodule.Description="Add Description";
    mainSet.Modules.push_back(newmodule);
    GenerateList();
}
