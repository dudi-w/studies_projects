#ifndef STRING_OUTPUT_HPP
#define STRING_OUTPUT_HPP

#include <fstream>
#include "output.hpp"

namespace dt
{
class StringOutput : public Output
{
public:
    explicit StringOutput() = default;
    StringOutput(StringOutput const& other) = default;
    StringOutput& operator=(StringOutput const& other) = default;
    ~StringOutput() = default;

    const std::string& getString() const{ return m_string;}
    void returnResulte(std::string data){m_string= data;};

private:
    std::string m_string;
};

}//namespace dt

std::ostream& operator<<(std::ostream& out , const dt::StringOutput& self )
{
    out << self.getString() << std::flush;
    return out;
}
#endif
