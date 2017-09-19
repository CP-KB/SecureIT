///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define Menu_File_Open 1000
#define Menu_File_Save 1001
#define Menu_File_SaveAs 1002
#define Menu_File_Exit 1003
#define Menu_Edit_Copy 1004
#define Menu_Edit_Cut 1005
#define Menu_Edit_Paste 1006
#define Menu_Edit_Delete 1007
#define Menu_Edit_SortBy 1008
#define Menu_Help_About 1009
#define Menu_Test_Execution 1010
#define Menu_Test_Serialization_Save 1011
#define Menu_Test_Serialization_Load 1012
#define Menu_Test_ListCtrl 1013

///////////////////////////////////////////////////////////////////////////////
/// Class MainWindow
///////////////////////////////////////////////////////////////////////////////
class MainWindow : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* menuBar;
		wxMenu* menuFile;
		wxMenu* menuEdit;
		wxMenu* menuAction;
		wxMenu* menuHelp;
		wxMenu* menuTest;
		wxComboBox* m_comboBox1;
		wxButton* m_button1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTestExecution( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTestSerializationSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTestSerializationLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTestListCtrl( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTestGenList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnListRightClick( wxListEvent& event ) { event.Skip(); }
		
	
	public:
		wxListCtrl* mainListCtrl;
		wxStatusBar* mainStatusBar;
		
		MainWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SecureIT"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainWindow();
	
};

#endif //__MAINWINDOW_H__
