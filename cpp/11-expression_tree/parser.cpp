#include <string>
#include <cmath>
#include "expressionTree.hpp"
#include "operatorNode.hpp"
#include "numNode.hpp"
#include "addNode.hpp"
#include "mulNode.hpp"
#include "subNode.hpp"
#include "divNode.hpp"

void parser(std::string const& expression , et::ExpressionNode* root , size_t& count){
    if(root){
        abort();
    }

    if(expression.size()==1 && isdigit(expression[0])){
        root = creatNode(static_cast <int> (expression[0]));
        ++count;
        return;
    }

    size_t i = preurity(expression);
    et::OperatorNode* pNode = creatNode(expression[i]);
    root = pNode;
    ++count;

    parser(expression.substr(0,i) ,pNode->left() ,count);
    parser(expression.substr(i+1,expression.size()) ,pNode->right() ,count);
    return;
}

size_t preurity(std::string const& expression)
{
    size_t i;
    std::string::const_iterator it = expression.cbegin();
    size_t min = INFINITY;
    while (it != expression.cend()){
        min = std::min(shrd(*it), min);///////????????
    }
        
    return i;
}

unsigned int shrd(char q)
{
    switch (q){
        case '+':
            return 1;

        case '-':
            return 1;

        case '*':
            return 2;

        case '/':
            return 2;

        default:
            return INFINITY;
    }
}
et::OperatorNode* creatNode(char preurity)
{
    switch (preurity)
    {
        case '+':
            return new et::AddNode;
        
        case '-':
            return new et::SubNode;

        case '*':
            return new et::MulNode;

        case '/':
            return new et::DivNode;

        default:
            abort();
    }
}

et::NumNode* creatNode(int num)
{
    return new et::NumNode(num);
}