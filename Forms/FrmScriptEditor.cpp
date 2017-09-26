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
	
	mainStyledTextBox = new wxStyledTextCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
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
	
	bSizer1->Add( mainStyledTextBox, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

FormScriptEditor::~FormScriptEditor()
{
}
