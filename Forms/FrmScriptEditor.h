#ifndef FRMSCRIPTEDITOR_H
#define FRMSCRIPTEDITOR_H

//(*Headers(FrmScriptEditor)
#include <wx/frame.h>
//*)

class FrmScriptEditor: public wxFrame
{
	public:

		FrmScriptEditor(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~FrmScriptEditor();

		//(*Declarations(FrmScriptEditor)
		//*)

	protected:

		//(*Identifiers(FrmScriptEditor)
		//*)

	private:

		//(*Handlers(FrmScriptEditor)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
