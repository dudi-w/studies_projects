#include <iostream>
#include <vector>
#include "storingToExpressionTree.hpp"

void test1()
{
    std::string exprssin("1-3+5");
    std::vector<P_token> tokens = tokenizer(exprssin);
    std::vector<P_token> orderedTokens = makePN(tokens);
    et::ExpressionTree tree1 = perser(orderedTokens);

    std::cout<<"exprssin : "<<exprssin<<std::endl;
    std::cout<<"resulte"<<'\t'<<tree1.getValue()<<std::endl;
    return;
}

void test2()
{
    std::string exprssin("1-3*5+5");
    std::vector<P_token> tokens = tokenizer(exprssin);
    std::vector<P_token> orderedTokens = makePN(tokens);
    et::ExpressionTree tree1 = perser(orderedTokens);

    std::cout<<"exprssin : "<<exprssin<<std::endl;
    std::cout<<"resulte"<<'\t'<<tree1.getValue()<<std::endl;
    return;
}

void test3()
{
    std::string exprssin("1/3+5");
    std::vector<P_token> tokens = tokenizer(exprssin);
    std::vector<P_token> orderedTokens = makePN(tokens);
    et::ExpressionTree tree1 = perser(orderedTokens);

    std::cout<<"exprssin : "<<exprssin<<std::endl;
    std::cout<<"resulte"<<'\t'<<tree1.getValue()<<std::endl;
    return;
}

void test4()
{
    std::string exprssin("013+55");
    std::vector<P_token> tokens = tokenizer(exprssin);
    std::vector<P_token> orderedTokens = makePN(tokens);
    et::ExpressionTree tree1 = perser(orderedTokens);

    std::cout<<"exprssin : "<<exprssin<<std::endl;
    std::cout<<"resulte"<<'\t'<<tree1.getValue()<<std::endl;
    return;
}
int main(void)
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}