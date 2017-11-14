#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//(*Headers(MainWindow)
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/imaglist.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/choice.h>
//*)
#include "../ModuleSet.h"
#include "../Tests.h"
#include "FrmScriptEditor.h"
//#include "../ExecuteTimer.h"

class ExecuteTimer;
class MainWindow: public wxFrame
{
	public:

		MainWindow(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~MainWindow();

		//(*Declarations(MainWindow)
		wxMenuItem* MenuItem2;
		wxChoice* osChoice;
		wxMenu* menuEdit;
		wxMenuItem* MenuItem1;
		wxFileDialog* saveFileDialog;
		wxMenu* Menu5;
		wxFileDialog* openFileDialog;
		wxMenu* Menu1;
		wxMenuItem* MenuItem12;
		wxButton* Button1;
		wxButton* btnRun;
		wxMenuItem* MenuItem3;
		wxMenuItem* btnSaveAs;
		wxMenuItem* MenuItem9;
		wxMenu* Menu4;
		wxMenuItem* MenuItem11;
		wxMenuItem* btnSave;
		wxMenuItem* MenuItem10;
		wxMenuItem* btnOpen;
		wxMenuItem* MenuItem7;
		wxMenuItem* MenuItem6;
		wxStatusBar* StatusBar;
		wxMenuItem* MenuItem13;
		wxMenu* Menu2;
		wxImageList* m_pImageList;
		wxMenuItem* MenuItem8;
		wxMenuItem* MenuItem14;
		wxListCtrl* mainListCtrl;
		//*)
        void UpdateListItem(unsigned int i);
        long int idLastClickedListItem;
        bool bRunning;
        ModuleSet mainSet; //object containing scans and actions


	protected:

		//(*Identifiers(MainWindow)
		static const long ID_OSCHOICE;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_LISTCTRL1;
		static const long Menu_File_Open;
		static const long Menu_File_Save;
		static const long Menu_File_SaveAs;
		static const long Menu_File_Exit;
		static const long Menu_New_ScanModule;
		static const long Menu_New_ActionModule;
		static const long Menu_Module_Edit;
		static const long ID_MENU_LIST_REFRESH;
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
		void OnFileOpen(wxCommandEvent& event);
		void OnTestGenList(wxCommandEvent& event);
		void OnTestStyleText(wxCommandEvent& event);
		void OnNewScanModule(wxCommandEvent& event);
		void OnEditModule(wxCommandEvent& event);
		void OnmainListCtrlItemRClick(wxListEvent& event);
		void OnSaveAs(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnRunChecked(wxCommandEvent& event);
		void OnListItemMClick(wxListEvent& event);
		void OnRefreshList(wxCommandEvent& event);
		//*)
		ExecuteTimer *mainTimer;
		boost::asio::io_service ios;
        void OnContextMenu(wxContextMenuEvent& event);
        void OnListItemToggleCheck(wxListEvent& event);
		DECLARE_EVENT_TABLE()
        void GenerateList();


};


#endif
