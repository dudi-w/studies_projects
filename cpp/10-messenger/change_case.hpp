#ifndef CHANGE_CASE_HPP
#define CHANGE_CASE_HPP
#include <iostream>
#include "transformation.hpp"
#include "input.hpp"
#include "output.hpp"

namespace dt
{

void change_case(Input const& input, Transformation const& t, Output& out);

}//namespace dt

#endif
