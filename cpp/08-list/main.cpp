#include <iostream>
#include "list.inl"
#include "../01-rational/rational.hpp"

void test1_long(){
    ls::List<long> list_1;
    for(long i = 0 ; i <10 ; ++i){
        list_1.insertBack(i);
    }
    list_1.display();

    for(long i = 9 ; i > -1 ; --i){
        list_1.insertFront(i);
    }
    list_1.display();


    ls::List<long> list_2(list_1);
    list_2.display();

    for(size_t i = 0 ; i <5; ++i){
        std::cout<<list_2.extractBack()<<'\n';
    }

    for(size_t i = 0 ; i <19; ++i){
        std::cout<<list_1.extractFront()<<'\n';
    }
    list_2.display();
    list_1.display();
    list_2 = list_1;
    list_2.display();
    list_1.display();
}

void test2_Rational(){
    ls::List<Rational> list_1;
    for(long i = 0 ; i <10 ; ++i){
        list_1.insertBack(Rational(i,i+8));
    }
    list_1.display();

    for(long i = 9 ; i > -1 ; --i){
        list_1.insertFront(Rational(i*2,i+7));
    }
    list_1.display();


    ls::List<Rational> list_2(list_1);
    list_2.display();

    for(size_t i = 0 ; i <5; ++i){
        std::cout<<list_2.extractBack()<<'\n';
    }

    for(size_t i = 0 ; i <19; ++i){
        std::cout<<list_1.extractFront()<<'\n';
    }
    list_2.display();
    list_1.display();
    list_2 = list_1;
    list_2.display();
    list_1.display();

}

int main(){
    test1_long();
    test2_Rational();
    return 0;
}