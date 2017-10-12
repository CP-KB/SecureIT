#include "FrmScriptEditor.h"

//(*InternalHeaders(FrmScriptEditor)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(FrmScriptEditor)
//*)

BEGIN_EVENT_TABLE(FrmScriptEditor,wxFrame)
	//(*EventTable(FrmScriptEditor)
	//*)
END_EVENT_TABLE()

FrmScriptEditor::FrmScriptEditor(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(FrmScriptEditor)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	//*)
}

FrmScriptEditor::~FrmScriptEditor()
{
	//(*Destroy(FrmScriptEditor)
	//*)
}

