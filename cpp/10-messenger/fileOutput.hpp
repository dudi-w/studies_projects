#ifndef FILE_OUTPUT_HPP
#define FILE_OUTPUT_HPP

#include <fstream>
#include "output.hpp"

namespace dt
{
class FileOutput : public Output
{
public:
    explicit FileOutput(std::string path) : m_path(path){}
    FileOutput(FileOutput const& other)= default;
    FileOutput& operator=(FileOutput const& other)= default;
    ~FileOutput() = default;

    void returnResulte(std::string data);

private:
    std::string m_path;
};

    void FileOutput::returnResulte(std::string data)
    {
        std::ofstream file;
        file.open(m_path);
        file<<data<<std::endl;
    };
}
#endif