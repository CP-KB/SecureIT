#include "CodeEditWin.h"

CodeEditWin::CodeEditWin() : FormScriptEditor(NULL)
{
    // Set the lexer to the C++ lexer
    mainStyledTextBox->SetLexer(wxSTC_LEX_BASH);
    std::cout << "Hi, is this working\n";

    // Set the color to use for various elements
    mainStyledTextBox->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColor(60, 162, 2));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColor(0, 0, 255));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_STRING, wxColor(255, 60, 10));
    mainStyledTextBox->StyleSetForeground(wxSTC_C_WORD, wxColor(0, 0, 255));

    mainUnCodeStyledTextBox->SetLexer(wxSTC_LEX_CPP);
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColor(60, 162, 2));
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColor(0, 0, 255));
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_STRING, wxColor(255, 60, 10));
    mainUnCodeStyledTextBox->StyleSetForeground(wxSTC_C_WORD, wxColor(0, 0, 255));
}
CodeEditWin::~CodeEditWin()
{
    //Maybe ask about saving???
}
