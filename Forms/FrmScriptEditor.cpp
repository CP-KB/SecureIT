#include "FrmScriptEditor.h"

//(*InternalHeaders(FrmScriptEditor)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(FrmScriptEditor)
const long FrmScriptEditor::ID_BUTTON1 = wxNewId();
const long FrmScriptEditor::ID_CHOICE1 = wxNewId();
const long FrmScriptEditor::ID_BUTTON2 = wxNewId();
const long FrmScriptEditor::ID_CHOICEBOOK1 = wxNewId();
const long FrmScriptEditor::ID_BUTTON3 = wxNewId();
const long FrmScriptEditor::ID_PANEL1 = wxNewId();
const long FrmScriptEditor::ID_PANEL2 = wxNewId();
const long FrmScriptEditor::ID_PANEL3 = wxNewId();
const long FrmScriptEditor::ID_PANEL4 = wxNewId();
const long FrmScriptEditor::ID_AUINOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FrmScriptEditor,wxFrame)
	//(*EventTable(FrmScriptEditor)
	//*)
END_EVENT_TABLE()

FrmScriptEditor::FrmScriptEditor(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(FrmScriptEditor)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,300));
	AuiNotebook1 = new wxAuiNotebook(this, ID_AUINOTEBOOK1, wxPoint(120,144), wxDefaultSize, 0);
	Panel1 = new wxPanel(AuiNotebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	btnSave = new wxButton(Panel1, ID_BUTTON1, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(btnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	choiceOS = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	choiceOS->Append(_("Bash (.sh)"));
	choiceOS->Append(_("Batch (.bat)"));
	choiceOS->Append(_("Powershell (.ps)"));
	BoxSizer2->Add(choiceOS, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	Choicebook1 = new wxChoicebook(Panel1, ID_CHOICEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_CHOICEBOOK1"));
	BoxSizer2->Add(Choicebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);
	Panel2 = new wxPanel(AuiNotebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	Panel3 = new wxPanel(AuiNotebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	Panel4 = new wxPanel(AuiNotebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	AuiNotebook1->AddPage(Panel1, _("Code"));
	AuiNotebook1->AddPage(Panel2, _("UnCode"));
	AuiNotebook1->AddPage(Panel3, _("Options"));
	AuiNotebook1->AddPage(Panel4, _("Config"));
	//*)

    mainStyledTextBox = new wxStyledTextCtrl( Panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
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

	// Set the lexer to the C++ lexer
    mainStyledTextBox->SetLexer(wxSTC_LEX_BASH);
    std::cout << "Hi, is this working\n";

    // Set the color to use for various elements
    mainStyledTextBox->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColor(60, 162, 2));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColor(0, 0, 255));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_STRING, wxColor(255, 60, 10));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_WORD, wxColor(0, 0, 255));

	BoxSizer1->Add( mainStyledTextBox, 1, wxALL|wxEXPAND, 5 );
}

FrmScriptEditor::~FrmScriptEditor()
{
	//(*Destroy(FrmScriptEditor)
	//*)
}

