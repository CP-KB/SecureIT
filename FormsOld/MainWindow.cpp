///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainWindow.h"

///////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	menuBar = new wxMenuBar( 0 );
	menuFile = new wxMenu();
	wxMenuItem* menuItemOpen;
	menuItemOpen = new wxMenuItem( menuFile, Menu_File_Open, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
	menuFile->Append( menuItemOpen );
	
	wxMenuItem* menuItemSave;
	menuItemSave = new wxMenuItem( menuFile, Menu_File_Save, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	menuFile->Append( menuItemSave );
	
	wxMenuItem* menuItemSaveAs;
	menuItemSaveAs = new wxMenuItem( menuFile, Menu_File_SaveAs, wxString( wxT("Save as") ) , wxEmptyString, wxITEM_NORMAL );
	menuFile->Append( menuItemSaveAs );
	
	menuFile->AppendSeparator();
	
	wxMenuItem* menuItemExit;
	menuItemExit = new wxMenuItem( menuFile, Menu_File_Exit, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	menuFile->Append( menuItemExit );
	
	menuBar->Append( menuFile, wxT("&File") ); 
	
	menuEdit = new wxMenu();
	wxMenuItem* menuItemCopy;
	menuItemCopy = new wxMenuItem( menuEdit, Menu_Edit_Copy, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	menuEdit->Append( menuItemCopy );
	
	wxMenuItem* menuItemCut;
	menuItemCut = new wxMenuItem( menuEdit, Menu_Edit_Cut, wxString( wxT("Cut") ) , wxEmptyString, wxITEM_NORMAL );
	menuEdit->Append( menuItemCut );
	
	wxMenuItem* menuItemPaste;
	menuItemPaste = new wxMenuItem( menuEdit, Menu_Edit_Paste, wxString( wxT("Paste") ) , wxEmptyString, wxITEM_NORMAL );
	menuEdit->Append( menuItemPaste );
	
	wxMenuItem* menuItemDelete;
	menuItemDelete = new wxMenuItem( menuEdit, Menu_Edit_Delete, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	menuEdit->Append( menuItemDelete );
	
	wxMenuItem* menuItemSortBy;
	menuItemSortBy = new wxMenuItem( menuEdit, Menu_Edit_SortBy, wxString( wxT("SortBy") ) , wxEmptyString, wxITEM_NORMAL );
	menuEdit->Append( menuItemSortBy );
	
	menuBar->Append( menuEdit, wxT("Edit") ); 
	
	menuAction = new wxMenu();
	menuBar->Append( menuAction, wxT("Action") ); 
	
	menuHelp = new wxMenu();
	wxMenuItem* menuItemAbout;
	menuItemAbout = new wxMenuItem( menuHelp, Menu_Help_About, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	menuHelp->Append( menuItemAbout );
	
	menuBar->Append( menuHelp, wxT("Help") ); 
	
	menuTest = new wxMenu();
	wxMenuItem* menuItemExecutionTest;
	menuItemExecutionTest = new wxMenuItem( menuTest, Menu_Test_Execution, wxString( wxT("Execution Test") ) , wxEmptyString, wxITEM_NORMAL );
	menuTest->Append( menuItemExecutionTest );
	
	wxMenuItem* menuItemSerializationSave;
	menuItemSerializationSave = new wxMenuItem( menuTest, Menu_Test_Serialization_Save, wxString( wxT("Serialization Save") ) , wxEmptyString, wxITEM_NORMAL );
	menuTest->Append( menuItemSerializationSave );
	
	wxMenuItem* menuItemSerializationLoad;
	menuItemSerializationLoad = new wxMenuItem( menuTest, Menu_Test_Serialization_Load, wxString( wxT("Serialization Load") ) , wxEmptyString, wxITEM_NORMAL );
	menuTest->Append( menuItemSerializationLoad );
	
	wxMenuItem* menuItemListCtrlTest;
	menuItemListCtrlTest = new wxMenuItem( menuTest, Menu_Test_ListCtrl, wxString( wxT("ListCtrl Test") ) , wxEmptyString, wxITEM_NORMAL );
	menuTest->Append( menuItemListCtrlTest );
	
	wxMenuItem* menuItemGenListTest;
	menuItemGenListTest = new wxMenuItem( menuTest, Menu_Test_GenList, wxString( wxT("Generate List Test") ) , wxEmptyString, wxITEM_NORMAL );
	menuTest->Append( menuItemGenListTest );
	
	wxMenuItem* menuItemTestStyleText;
	menuItemTestStyleText = new wxMenuItem( menuTest, Menu_Test_StyleText, wxString( wxT("Test wxStyleTextCtrl") ) , wxEmptyString, wxITEM_NORMAL );
	menuTest->Append( menuItemTestStyleText );
	
	menuBar->Append( menuTest, wxT("&Test") ); 
	
	this->SetMenuBar( menuBar );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer2->Add( m_comboBox1, 0, wxALL, 5 );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_button1, 0, wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	mainListCtrl = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_LIST|wxLC_REPORT );
	bSizer1->Add( mainListCtrl, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	mainStatusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( menuItemOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnFileOpen ) );
	this->Connect( menuItemExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnExit ) );
	this->Connect( menuItemAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnAbout ) );
	this->Connect( menuItemExecutionTest->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestExecution ) );
	this->Connect( menuItemSerializationSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestSerializationSave ) );
	this->Connect( menuItemSerializationLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestSerializationLoad ) );
	this->Connect( menuItemListCtrlTest->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestListCtrl ) );
	this->Connect( menuItemGenListTest->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestGenList ) );
	this->Connect( menuItemTestStyleText->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestStyleText ) );
	mainListCtrl->Connect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( MainWindow::OnListRightClick ), NULL, this );
}

MainWindow::~MainWindow()
{
	// Disconnect Events
	this->Disconnect( Menu_File_Open, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnFileOpen ) );
	this->Disconnect( Menu_File_Exit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnExit ) );
	this->Disconnect( Menu_Help_About, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnAbout ) );
	this->Disconnect( Menu_Test_Execution, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestExecution ) );
	this->Disconnect( Menu_Test_Serialization_Save, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestSerializationSave ) );
	this->Disconnect( Menu_Test_Serialization_Load, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestSerializationLoad ) );
	this->Disconnect( Menu_Test_ListCtrl, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestListCtrl ) );
	this->Disconnect( Menu_Test_GenList, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestGenList ) );
	this->Disconnect( Menu_Test_StyleText, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainWindow::OnTestStyleText ) );
	mainListCtrl->Disconnect( wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, wxListEventHandler( MainWindow::OnListRightClick ), NULL, this );
	
}
