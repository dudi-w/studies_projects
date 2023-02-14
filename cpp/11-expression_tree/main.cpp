#include <iostream>
#include "numNode.hpp"
#include "addNode.hpp"
#include "mulNode.hpp"
#include "subNode.hpp"
#include "divNode.hpp"


int main(void)
{
    et::NumNode* right = new et::NumNode(8);
    et::NumNode* left = new et::NumNode(155);
    et::AddNode rot(right,left);

    et::NumNode* right5 = new et::NumNode(5);
    et::NumNode* right2 = new et::NumNode(2);
    et::MulNode* rightMull = new et::MulNode(right2,right5);
    et::NumNode* right1 = new et::NumNode(1);
    et::AddNode rot2(rightMull,right1);



    std::cout<<rot2.getValue()<<std::endl;

    return 0;
}//1+2*5