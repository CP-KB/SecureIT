#include "Windows.h"
#include "Constants.hpp"

MainWin::MainWin() : MainWindow(NULL)
{}

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
void MainWin::OnListRightClick(wxListEvent& ListEvent)
{
    std::cout << "Clicked R +" << ListEvent.GetText() << std::endl;

    if (MainWin::mainListCtrl->IsItemChecked(ListEvent.GetItem().GetId()))
    {
        std::cout << "Checkbox is Checked" << std::endl;
        mainStatusBar->SetStatusText("Checkbox is Checked");
    }else
    {
        std::cout << "Checkbox is NOT Checked" << std::endl;
    }
}


void MainWin::GenerateListFromScans()
{

}
