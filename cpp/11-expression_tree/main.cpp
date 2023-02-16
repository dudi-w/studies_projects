#include <iostream>
#include <vector>
#include "storingToExpressionTree.hpp"
// #include "ETenum.hpp"
// #include "tokens/token.hpp"
// #include "tokens/token-implementation/numToken.hpp"
// #include "tokens/token-implementation/operatorToken.hpp"

int main(void)
{
    std::vector<P_token> tokens = tokenizer("1+2");

    // tokens.push_back(&tk::NumToken(5,5, Group::NumGroup));
    // tokens.push_back(&tk::NumToken(5,5, Group::NumGroup));
    // std::cout << tokens[0].getIndex();
    // std::cout << tokens[1].getIndex();
    // std::unique_ptr<et::NumNode> right = std::make_unique<et::NumNode>(8);
    // auto right =std::make_unique<et::NumNode>(8);
    // auto left = std::make_unique<et::NumNode>(155);
    // et::AddNode rot(right,left);
    // et::NumNode* right5 = new et::NumNode(5);
    // et::NumNode* right2 = new et::NumNode(2);
    // et::MulNode* rightMull = new et::MulNode(right2,right5);
    // et::NumNode* right1 = new et::NumNode(1);
    // et::AddNode rot2(rightMull,right1);



    // std::cout<<rot2.getValue()<<std::endl;

    return 0;
}