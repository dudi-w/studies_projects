#ifndef MAP_BILDERS_HPP
#define MAP_BILDERS_HPP

#include <unordered_map>
#include <functional>
#include "ETenum.hpp"
#include "node/binaryOperatorNode/binaryOperatorNode-implementation/addNode.hpp"
#include "node/binaryOperatorNode/binaryOperatorNode-implementation/subNode.hpp"
#include "node/binaryOperatorNode/binaryOperatorNode-implementation/mulNode.hpp"
#include "node/binaryOperatorNode/binaryOperatorNode-implementation/divNode.hpp"

namespace et
{
P_ex bildEDD(P_ex left, P_ex right);

P_ex bildSUB(P_ex left, P_ex right);

P_ex bildMUL(P_ex left, P_ex right);

P_ex bildDIV(P_ex left, P_ex right);

static std::unordered_map<char,std::function<P_ex(P_ex right ,P_ex left)>> bildFunctions
{
    {'+', &bildEDD },
    {'-', &bildSUB },
    {'*', &bildMUL },
    {'/', &bildDIV }
};

static std::unordered_map<char, Group> preurityGroup
{
    {'+', Group::AddGroup},
    {'-', Group::AddGroup},
    {'*', Group::MulGroup},
    {'/', Group::MulGroup}
};

}//namespace et

#endif
