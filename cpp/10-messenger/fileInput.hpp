#ifndef FILE_INPUT_HPP
#define FILE_INPUT_HPP

#include "input.hpp"
#include <fstream>
#include <iostream>

class FileInput : public Input
{
public:
    FileInput(std::string path);
    ~FileInput() = default;

    inline
    std::string returnAsString() const{return m_data;}

private:
    std::string m_data;
};

FileInput::FileInput(std::string path)
{   
    std::ifstream file(path);
    std::getline(file , m_data , ';');
    file.close();
}

#endif