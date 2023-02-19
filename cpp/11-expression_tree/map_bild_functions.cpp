#include "map_bild_functions.hpp"

namespace et{
    
P_ex bildEDD(P_ex left ,P_ex right)
{
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

P_ex bildSUB(P_ex left ,P_ex right)
{
    return std::make_unique<et::SubNode>( std::move(right) , std::move(left));
}

P_ex bildMUL(P_ex left ,P_ex right)
{
    return std::make_unique<et::MulNode>( std::move(right) , std::move(left));
}

P_ex bildDIV(P_ex left ,P_ex right)
{
    return std::make_unique<et::DivNode>( std::move(right) , std::move(left));
}

}//namespace et
