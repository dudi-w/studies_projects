#include "map_bild_functions.hpp"

namespace et
{
P_ex bildEDD(P_ex right ,P_ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

P_ex bildSUB(P_ex right ,P_ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

P_ex bildMUL(P_ex right ,P_ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

P_ex bildDIV(P_ex right ,P_ex left){
    return std::make_unique<et::AddNode>( std::move(right) , std::move(left));
}

}//namespace et
