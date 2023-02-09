#include "change_case.hpp"

namespace dt
{
void change_case(Input const& input, Transformation const& t, std::ostream& os)
{
    std::string str = input.returnAsString();
    std::string new_str = t.transform(str);
    os << new_str << std::endl;

};

void change_case_by_stream(std::istream& is, Transformation const& t, std::ostream& os)
{
    std::string input;
    is >> input;

    std::string new_str = t.transform(input); 
    os << new_str << std::endl;
};

}//namespace dt

