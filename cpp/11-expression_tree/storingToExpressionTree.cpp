#include <assert.h>
#include <stack>
#include "storingToExpressionTree.hpp"

bool isOperator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' );
}

float extractData(std::string const& strExpr, size_t& index)
{
    size_t begin = index;
    while(std::isdigit(strExpr[index+1]))
    {
        ++index;
    }
    float data = std::stoi(strExpr.substr(begin, index+1));
    return data;
}

std::vector<P_token> tokenizer(std::string const& strExpr)
{
    std::vector<P_token> tokenExpr;
    
    if(strExpr.empty()){
        assert(!"empty expressin");
    }

    for(size_t i = 0; i<strExpr.size() ;++i){
        
        if(strExpr[i] == ' '){
            continue;
        }
        
        if(isOperator(strExpr[i])){
            Group group =  et::preurityGroup[strExpr[i]];
            auto func =  et::bildFunctions[strExpr[i]];
            auto oper =  std::make_shared<tk::OperatorToken>(i, func, group);

            tokenExpr.push_back(std::move(oper));
        }
        
        else if(isdigit(strExpr[i])){
            float data = extractData(strExpr, i);
            auto num =  std::make_shared<tk::NumToken>(i, data, Group::NumGroup);
            tokenExpr.push_back(std::move(num));
        }

        else{
            assert(!"invalid expressin");
        }
    }

    if(tokenExpr.empty()){
        assert(!"empty expressin");
    }

    return tokenExpr;
}

void pushInPNorder(P_Vtok& orderVector, P_Vtok const& tokenEper,  P_Vtok::const_reverse_iterator begin , P_Vtok::const_reverse_iterator end)
{
    if(begin+1 == end ){
        orderVector.push_back(*begin);
        return;
    }

    auto candidate = begin;
    auto itr = begin;
    while(itr != end){
        if((*itr)->preyutiryGroup() < (*candidate)->preyutiryGroup()){
            candidate = itr;
        }
        ++itr;
    }
    orderVector.push_back(*candidate);

    pushInPNorder(orderVector, tokenEper ,begin ,candidate);
    pushInPNorder(orderVector, tokenEper , candidate+1, end);

    return;
}

P_Vtok makePN(P_Vtok const& tokenEper){
    P_Vtok newVector;

    pushInPNorder(newVector ,tokenEper ,tokenEper.crbegin() ,tokenEper.crend());
    
    return newVector;
}

et::ExpressionTree perser(P_Vtok& tokenEper)
{
    std::stack<P_ex> stack;

    while(tokenEper.size()){
        size_t lest = tokenEper.size()-1;
        tokenEper.at(lest)->creatNode(stack);
        tokenEper.pop_back();
    }
    return et::ExpressionTree(std::move(stack.top()), tokenEper.size());
}
