#include <memory>
#include <unordered_map>
#include <functional>
#include "ETenum.hpp"
#include "node/binaryOperatorNode/addNode.hpp"
#include "node/binaryOperatorNode/subNode.hpp"
#include "node/binaryOperatorNode/mulNode.hpp"
#include "node/binaryOperatorNode/divNode.hpp"

namespace et
{
P_Ex bildEDD(P_Ex right ,P_Ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

P_Ex bildSUB(P_Ex right ,P_Ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

P_Ex bildMUL(P_Ex right ,P_Ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

P_Ex bildDIV(P_Ex right ,P_Ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

static std::unordered_map<char,std::function<P_Ex(P_Ex right ,P_Ex left)>> bildFunctions
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
