#include "change_case.hpp"

namespace dt
{
void change_case(Input const& input, Transformation const& trans, Output& out)
{
    std::string str = input.returnAsString();
    std::string new_str = trans.transform(str);
    out.returnResulte(new_str);

};

}//namespace dt

