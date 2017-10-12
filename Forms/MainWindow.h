#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//(*Headers(MainWindow)
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/choice.h>
//*)

class MainWindow: public wxFrame
{
	public:

		MainWindow(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~MainWindow();

		//(*Declarations(MainWindow)
		wxMenuItem* MenuItem2;
		wxChoice* osChoice;
		wxMenuItem* MenuItem1;
		wxMenu* Menu5;
		wxMenu* Menu1;
		wxStatusBar* StatusBar1;
		wxMenu* Menu3;
		wxButton* Button1;
		wxMenuItem* MenuItem3;
		wxMenuItem* MenuItem9;
		wxMenu* Menu4;
		wxMenuItem* MenuItem11;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem10;
		wxMenuItem* MenuItem7;
		wxMenuItem* MenuItem6;
		wxMenuItem* MenuItem4;
		wxMenu* Menu2;
		wxMenuItem* MenuItem8;
		wxListCtrl* mainListCtrl;
		//*)

	protected:

		//(*Identifiers(MainWindow)
		static const long ID_OSCHOICE;
		static const long ID_BUTTON1;
		static const long ID_LISTCTRL1;
		static const long Menu_File_Open;
		static const long Menu_File_Save;
		static const long Menu_File_SaveAs;
		static const long Menu_File_Exit;
		static const long Menu_Help_About;
		static const long ID_MENUITEM1;
		static const long ID_MENUITEM2;
		static const long ID_MENUITEM3;
		static const long ID_MENUITEM4;
		static const long ID_MENUITEM5;
		static const long ID_MENUITEM6;
		static const long ID_STATUSBAR1;
		//*)

	private:

		//(*Handlers(MainWindow)
		void OnAbout(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnmainListCtrlBeginDrag(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
