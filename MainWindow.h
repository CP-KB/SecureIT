#include "Tests.h"
#include "Constants.hpp"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx-3.1/wx/wx.h>
#endif
#include <wx/combo.h>
class MainWindow : public wxFrame
{
    private:
        wxFrame *mainFrame;
        wxSizer *mainSizer;
        wxPanel *mainPanel;
        wxMenuBar *menuBar;




    public:
        MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
        void CreateControls();
        void CreateMenu();



    protected:
        wxDECLARE_EVENT_TABLE();
        void OnExit(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);
        void OnClose(wxCommandEvent& event);
        void OnCopy(wxCommandEvent& event);
        void OnCut(wxCommandEvent& event);
        void OnPaste(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //void OnExit(wxCommandEvent& event);
        void OnTestExecution(wxCommandEvent& event);
        void OnTestSerializationLoad(wxCommandEvent& event);
        void OnTestSerializationSave(wxCommandEvent& event);
};

class MyApp: public wxApp
{
public:
    virtual bool OnInit();

};


