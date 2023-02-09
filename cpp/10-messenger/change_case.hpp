#ifndef CHANGE_CASE_HPP
#define CHANGE_CASE_HPP
#include <iostream>
#include "transformation.hpp"
#include "input.hpp"

namespace dt
{

void change_case(Input const& input, Transformation const& t, std::ostream& os);

void change_case_by_stream(std::istream& is, Transformation const& t, std::ostream& os);

}//namespace dt

#endif
