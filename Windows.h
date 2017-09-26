#ifndef WINDOWS_H
#define WINDOWS_H

#include "Tests.h"
#include "Constants.hpp"
#include "Forms/MainWindow.h"
#include "Forms/FrmScriptEditor.h"
#include "CodeEditWin.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx-3.1/wx/wx.h>
#endif

class MainWin : public MainWindow
{
    public:
        MainWin();
    protected:
        void OnExit( wxCommandEvent& event );
        void OnAbout( wxCommandEvent& event );
        void OnTestExecution( wxCommandEvent& event );
        void OnTestSerializationSave( wxCommandEvent& event );
        void OnTestSerializationLoad( wxCommandEvent& event );

        void OnTestListCtrl(wxCommandEvent& event);
        void OnTestGenList(wxCommandEvent& event);
        void OnTestStyleText(wxCommandEvent& event);

        void OnListRightClick( wxListEvent& event );

        void GenerateListFromScans();
};
#endif
