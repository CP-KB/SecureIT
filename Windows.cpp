#include "Windows.h"
#include "Constants.hpp"

MainWin::MainWin() : MainWindow(NULL)
{

}
void MainWin::OnFileOpen( wxCommandEvent& event )
{
    wxFileDialog
        openFileDialog(this, _("Open XYZ file"), "", "",
                       "XYZ files (*.xyz)|*.xyz", wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_MULTIPLE);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

}

void MainWin::OnExit(wxCommandEvent& event)
{
    Close();
}
void MainWin::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    (void)wxMessageBox(APP_NAME + "\n(c)" + APP_DATE + " " + APP_AUTHORS,
                       APP_DESCRIPTION,
                       wxOK | wxICON_INFORMATION);
}
void MainWin::OnTestExecution(wxCommandEvent& WXUNUSED(event))
{
    Testing::ExecutionTest();
}
void MainWin::OnTestSerializationLoad(wxCommandEvent& WXUNUSED(event))
{
    Testing::LoadXMLtest();
}
void MainWin::OnTestSerializationSave(wxCommandEvent& WXUNUSED(event))
{
    Testing::SaveXMLtest();
}
void MainWin::OnTestListCtrl(wxCommandEvent& WXUNUSED(event))
{
    wxListItem testListItem;
    //testListItem->
    if (!mainListCtrl->EnableCheckboxes(true)) {std::cout << "Error: No Checkbox support.\n";}

    testListItem.SetText(wxT("Test Item #1"));
    testListItem.SetColumn(0);
    testListItem.SetId(0);
    //testListItem.
    mainListCtrl->AppendColumn("TestColumn");
    mainListCtrl->AppendColumn("TestColumn2");
    //mainListCtrl
    mainListCtrl->InsertItem(testListItem);
}
void MainWin::OnTestGenList(wxCommandEvent& WXUNUSED(event))
{
    mainListCtrl->ClearAll();
    wxListItem testListItem;
    ModuleScan testScan= Testing::genTestModuleScan();
    mainListCtrl->AppendColumn("Name");
    mainListCtrl->AppendColumn("Description");
    testListItem.SetText(testScan.Name);
    testListItem.SetColumn(0);
    testListItem.SetId(0);
    mainListCtrl->InsertItem(testListItem);
}
void MainWin::OnTestStyleText(wxCommandEvent& WXUNUSED(event))
{
    std::cout << "test\n";
    CodeEditWin *EditWin=new CodeEditWin();
    EditWin->Show(true);

}
void MainWin::OnListRightClick(wxListEvent& ListEvent)
{
    std::cout << "Clicked R +" << ListEvent.GetText() << std::endl;

    if (MainWin::mainListCtrl->IsItemChecked(ListEvent.GetItem().GetId()))
    {
        std::cout << "Checkbox is Checked" << std::endl;
        mainStatusBar->SetStatusText("Checkbox is Checked");
        MainWin *winMain=new MainWin();
        winMain->Show(true);
    }else
    {
        std::cout << "Checkbox is NOT Checked" << std::endl;
    }
    // Show popupmenu at position
    wxMenu menu(wxT("Test"));
    menu.Append(wxID_ANY, wxT("&About"));
    PopupMenu(&menu);//, ListEvent.GetPoint());
}


void MainWin::GenerateListFromScans()
{

}
