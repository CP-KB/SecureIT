#ifndef FRMSCRIPTEDITOR_H
#define FRMSCRIPTEDITOR_H

//(*Headers(FrmScriptEditor)
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/choice.h>
//*)
#include "wx/propgrid/propgrid.h"
#include "wx/propgrid/advprops.h"
#include <wx/stc/stc.h>
#include <wx/settings.h>
#include "../Module.h"

class FrmScriptEditor: public wxFrame
{
	public:

		FrmScriptEditor(wxWindow* parent,wxWindowID id=wxID_ANY);
		void SetModule(Module *objModule);
		void SaveModule();
		virtual ~FrmScriptEditor();

		//(*Declarations(FrmScriptEditor)
		wxChoice* choiceOS;
		wxPanel* Panel1;
		wxComboBox* comboProperty;
		wxButton* Button2;
		wxButton* Button3;
		wxPanel* Panel2;
		wxPanel* Panel4;
		wxAuiNotebook* AuiNotebook1;
		wxPanel* Panel3;
		wxButton* btnSave;
		//*)
		wxPropertyGrid *pg;
        wxStyledTextCtrl *mainStyledTextBox;
	protected:

		//(*Identifiers(FrmScriptEditor)
		static const long ID_BUTTON1;
		static const long ID_CHOICE1;
		static const long ID_BUTTON2;
		static const long ID_COMBOBOX1;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_PANEL4;
		static const long ID_AUINOTEBOOK1;
		//*)

	private:

		//(*Handlers(FrmScriptEditor)
		void OnClose(wxCloseEvent& event);
		void OnBtnSave(wxCommandEvent& event);
		//*)

        void OnPropertyGridChange(wxPropertyGridEvent& event);
        void OnPropertyGridChanging(wxPropertyGridEvent& event);

		DECLARE_EVENT_TABLE()

		Module *moduleCurrent;
};

#endif
