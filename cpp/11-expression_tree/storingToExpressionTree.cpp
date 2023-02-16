#include <string>
#include <vector>
#include <assert.h>
#include "map_bild_functions.hpp"
#include "tokens/token.hpp"
#include "tokens/operatorToken.hpp"
#include "tokens/numToken.hpp"

bool isNum(char){return false;}
int extractData(std::string const& strExpr, size_t& index)
{
    size_t begin = index;
    while(std::isdigit(strExpr[index]))
    {
        ++index;
    }
    int data = std::atoi(strExpr.substr(begin, index));
    return data;
}

std::vector<tk::Token> tokenizer(std::string const& strExpr)
{
    std::vector<tk::Token> tokenExpr;
    for(size_t i = 0; i<strExpr.size() ;++i){
        if(strExpr[i] == ' ') {continue;}
        if(!isdigit(strExpr[i])){
            Group group =  et::preurityGroup[strExpr[i]];
            auto func =  et::bildFunctions[strExpr[i]];
            tk::OperatorToken oper(i, func, group);
            tokenExpr.push_back(oper);
        }else if(isNum(strExpr[i])){
            int data = extractData(strExpr, i);
            tk::NumToken num(i, data, Group::NumGroup);
            tokenExpr.push_back(num);
        }else{assert(!"invalid expressin");}
    }
    return tokenExpr;
}

void parser(std::string const& expression , et::ExpressionNode* root , size_t& count)
{
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
        min = std::min(rating(*it), min);///////????????
    }
        
    return i;
}

unsigned int rating(char q)
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