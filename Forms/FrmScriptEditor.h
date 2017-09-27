///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FRMSCRIPTEDITOR_H__
#define __FRMSCRIPTEDITOR_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/stc/stc.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FormScriptEditor
///////////////////////////////////////////////////////////////////////////////
class FormScriptEditor : public wxFrame 
{
	private:
	
	protected:
		wxAuiNotebook* m_auinotebook1;
		wxPanel* m_panel1;
		wxButton* buttonSave;
		wxChoice* choiceScriptType;
		wxButton* btnAddOption;
		wxComboBox* comboOption;
		wxButton* buttonRun;
		wxStyledTextCtrl* mainStyledTextBox;
		wxScrolledWindow* m_scrolledWindow1;
		wxPanel* m_panel2;
	
	public:
		
		FormScriptEditor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FormScriptEditor();
	
};

#endif //__FRMSCRIPTEDITOR_H__
