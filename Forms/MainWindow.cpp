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
	wxMenuBar* MenuBar1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER, _T("id"));
	SetClientSize(wxSize(342,204));
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
	BoxSizer2->Add(osChoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Scan/Actions"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_LEFT, 5);
	mainListCtrl = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer1->Add(mainListCtrl, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	MenuBar1 = new wxMenuBar();
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
	MenuBar1->Append(Menu1, _("&File"));
	Menu3 = new wxMenu();
	MenuBar1->Append(Menu3, _("Edit"));
	Menu4 = new wxMenu();
	MenuBar1->Append(Menu4, _("Action"));
	Menu2 = new wxMenu();
	MenuItem2 = new wxMenuItem(Menu2, Menu_Help_About, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MenuBar1->Append(Menu2, _("Help"));
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
	MenuBar1->Append(Menu5, _("Test"));
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(Menu_Help_About,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnAbout);
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
