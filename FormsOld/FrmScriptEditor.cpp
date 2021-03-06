///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FrmScriptEditor.h"

///////////////////////////////////////////////////////////////////////////

FormScriptEditor::FormScriptEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_auinotebook1 = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	bSizer2->SetMinSize( wxSize( 1,1 ) ); 
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	buttonSave = new wxButton( m_panel1, wxID_ANY, wxT("Save"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer8->Add( buttonSave, 0, wxALL, 5 );
	
	wxString choiceScriptTypeChoices[] = { wxT("Bash (.sh)"), wxT("Batch (.bat)"), wxT("Powershell (.ps)") };
	int choiceScriptTypeNChoices = sizeof( choiceScriptTypeChoices ) / sizeof( wxString );
	choiceScriptType = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), choiceScriptTypeNChoices, choiceScriptTypeChoices, 0 );
	choiceScriptType->SetSelection( 0 );
	bSizer8->Add( choiceScriptType, 0, wxALL, 5 );
	
	btnAddOption = new wxButton( m_panel1, wxID_ANY, wxT("Add Option"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( btnAddOption, 0, wxALL, 5 );
	
	comboOption = new wxComboBox( m_panel1, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer8->Add( comboOption, 0, wxALL, 5 );
	
	buttonRun = new wxButton( m_panel1, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( buttonRun, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer8, 0, wxEXPAND, 5 );
	
	mainStyledTextBox = new wxStyledTextCtrl( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	mainStyledTextBox->SetUseTabs( true );
	mainStyledTextBox->SetTabWidth( 4 );
	mainStyledTextBox->SetIndent( 4 );
	mainStyledTextBox->SetTabIndents( true );
	mainStyledTextBox->SetBackSpaceUnIndents( true );
	mainStyledTextBox->SetViewEOL( false );
	mainStyledTextBox->SetViewWhiteSpace( false );
	mainStyledTextBox->SetMarginWidth( 2, 0 );
	mainStyledTextBox->SetIndentationGuides( true );
	mainStyledTextBox->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	mainStyledTextBox->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	mainStyledTextBox->SetMarginWidth( 1, 16);
	mainStyledTextBox->SetMarginSensitive( 1, true );
	mainStyledTextBox->SetProperty( wxT("fold"), wxT("1") );
	mainStyledTextBox->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	mainStyledTextBox->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	mainStyledTextBox->SetMarginWidth( 0, mainStyledTextBox->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	{
		wxFont font = wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString );
		mainStyledTextBox->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	mainStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	mainStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	mainStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	mainStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	mainStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	mainStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	mainStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	mainStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	mainStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	mainStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	mainStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	mainStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	mainStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	mainStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	mainStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	mainStyledTextBox->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	mainStyledTextBox->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	mainStyledTextBox->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	bSizer2->Add( mainStyledTextBox, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	m_auinotebook1->AddPage( m_panel1, wxT("Code"), false, wxNullBitmap );
	m_panel11 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	bSizer21->SetMinSize( wxSize( 1,1 ) ); 
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	buttonSave1 = new wxButton( m_panel11, wxID_ANY, wxT("Save"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer81->Add( buttonSave1, 0, wxALL, 5 );
	
	btnAddOption1 = new wxButton( m_panel11, wxID_ANY, wxT("Add Option"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( btnAddOption1, 0, wxALL, 5 );
	
	comboOption1 = new wxComboBox( m_panel11, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer81->Add( comboOption1, 0, wxALL, 5 );
	
	buttonRun1 = new wxButton( m_panel11, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( buttonRun1, 0, wxALL, 5 );
	
	
	bSizer21->Add( bSizer81, 0, wxEXPAND, 5 );
	
	mainUnCodeStyledTextBox = new wxStyledTextCtrl( m_panel11, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	mainUnCodeStyledTextBox->SetUseTabs( true );
	mainUnCodeStyledTextBox->SetTabWidth( 4 );
	mainUnCodeStyledTextBox->SetIndent( 4 );
	mainUnCodeStyledTextBox->SetTabIndents( true );
	mainUnCodeStyledTextBox->SetBackSpaceUnIndents( true );
	mainUnCodeStyledTextBox->SetViewEOL( false );
	mainUnCodeStyledTextBox->SetViewWhiteSpace( false );
	mainUnCodeStyledTextBox->SetMarginWidth( 2, 0 );
	mainUnCodeStyledTextBox->SetIndentationGuides( true );
	mainUnCodeStyledTextBox->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	mainUnCodeStyledTextBox->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	mainUnCodeStyledTextBox->SetMarginWidth( 1, 16);
	mainUnCodeStyledTextBox->SetMarginSensitive( 1, true );
	mainUnCodeStyledTextBox->SetProperty( wxT("fold"), wxT("1") );
	mainUnCodeStyledTextBox->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	mainUnCodeStyledTextBox->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	mainUnCodeStyledTextBox->SetMarginWidth( 0, mainUnCodeStyledTextBox->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	{
		wxFont font = wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString );
		mainUnCodeStyledTextBox->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	mainUnCodeStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	mainUnCodeStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	mainUnCodeStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	mainUnCodeStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	mainUnCodeStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	mainUnCodeStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	mainUnCodeStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	mainUnCodeStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	mainUnCodeStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	mainUnCodeStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	mainUnCodeStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	mainUnCodeStyledTextBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	mainUnCodeStyledTextBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	mainUnCodeStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	mainUnCodeStyledTextBox->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	mainUnCodeStyledTextBox->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	mainUnCodeStyledTextBox->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	mainUnCodeStyledTextBox->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	bSizer21->Add( mainUnCodeStyledTextBox, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel11->SetSizer( bSizer21 );
	m_panel11->Layout();
	bSizer21->Fit( m_panel11 );
	m_auinotebook1->AddPage( m_panel11, wxT("UnCode"), true, wxNullBitmap );
	m_scrolledWindow1 = new wxScrolledWindow( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	m_auinotebook1->AddPage( m_scrolledWindow1, wxT("Options"), false, wxNullBitmap );
	m_panel2 = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_propertyGrid3 = new wxPropertyGrid(m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	bSizer6->Add( m_propertyGrid3, 0, wxALL, 5 );
	
	
	m_panel2->SetSizer( bSizer6 );
	m_panel2->Layout();
	bSizer6->Fit( m_panel2 );
	m_auinotebook1->AddPage( m_panel2, wxT("Config"), false, wxNullBitmap );
	
	bSizer1->Add( m_auinotebook1, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer1->Add( bSizer5, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

FormScriptEditor::~FormScriptEditor()
{
}
