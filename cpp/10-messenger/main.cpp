#include "change_case.hpp"
#include "transformation.hpp"
#include "lowercase.hpp"
#include "uppercase.hpp"
#include "shiftEncryption.hpp"
#include "a_zEncryption.hpp"
#include "terminalInput.hpp"
#include "stringInput.hpp"
#include "fileInput.hpp"
#include "fileOutput.hpp"
#include "tarminelOutput.hpp"
#include "stringOutput.hpp"
#include <iostream>
#include <vector>
#include <array>

//#include <fstream>

void test_A_Z_case_from_file_to_terminal()
{
    dt::FileInput filelInput("text.txt");
    dt::A_Z_Encryption aaa;
    dt::TerminalOutput terminalOutput; 
    dt::change_case( filelInput , aaa, terminalOutput);
}

void test_lower_from_main_to_string()
{
    dt::StringInput stringInput("test");
    dt::Uppercase p;
    dt::StringOutput stringOutput;
    dt::change_case(stringInput, p, stringOutput);
    std::cout<<stringOutput<<std::endl;
}

void test_upper_from_terminal_to_terminal()
{
    dt::TerminalInput terminalInput;
    dt::Uppercase up;
    dt::TerminalOutput terminalOutput;
    dt::change_case(terminalInput, up, terminalOutput);
}

void test_shift_encryption_from_terminal_to_file()
{
    dt::TerminalInput terminalInput;
    dt::ShiftEncryption shiftEncryption(-30);
    dt::FileOutput fileOutput("outDAta.txt");
    dt::change_case(terminalInput, shiftEncryption, fileOutput);
}

int main()
{
    test_A_Z_case_from_file_to_terminal();
    test_lower_from_main_to_string();
    test_upper_from_terminal_to_terminal();
    test_shift_encryption_from_terminal_to_file();
    return 0; 
}