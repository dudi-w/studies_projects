#include "transformation.hpp"
#include "lowercase.hpp"
#include "uppercase.hpp"
#include "change_case.hpp"
#include "terminalInput.hpp"
#include "stringInput.hpp"
#include "fileInput.hpp"
#include "shiftEncryption.hpp"
#include <iostream>
#include <vector>
#include <array>

//#include <fstream>

void test_lower_through_file()
{
    FileInput filelInput("text.txt");
    dt::Lowercase p;
    dt::change_case( filelInput , p, std::cout);
}

void test_upper()
{
    StringInput stringInput("test");
    dt::Uppercase p;
    dt::change_case(stringInput, p, std::cout);
}

void test_upper_through_terminal()
{
    TerminalInput terminalInput;
    dt::Uppercase p;
    dt::change_case(terminalInput, p, std::cout);
}

void test_shift_encryption()
{
    TerminalInput terminalInput;
    dt::ShiftEncryption shiftEncryption(26+3);
    dt::change_case(terminalInput, shiftEncryption, std::cout);
}

int main()
{
    test_lower_through_file();
    test_upper_through_terminal();
    test_upper();
    test_shift_encryption();
    return 0; 
}