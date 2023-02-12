#ifndef FILE_INPUT_HPP
#define FILE_INPUT_HPP

#include "input.hpp"
#include <fstream>
#include <iostream>

namespace dt
{
class FileInput : public Input
{
public:
    explicit FileInput(std::string path);
    FileInput(FileInput const& other) = default;
    FileInput& operator=(FileInput const& other) = default;
    ~FileInput() = default;

    inline
    std::string returnAsString() const{return m_data;}

private:
    std::string m_data;
};

FileInput::FileInput(std::string path)
{   
    std::ifstream file(path);
    std::string tmp_data;
    while (std::getline(file , tmp_data))
    {
        m_data+=tmp_data+'\n';
    }
    
    file.close();
}

}//namespace dt
#endif