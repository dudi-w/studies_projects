#include <iostream>
#include "list.inl"
#include "../01-rational/rational.hpp"
#include "../07-containers/templateFunction2.hpp"

void test1_long(){
    ls::List<long> list_1;

    for(long i = 0 ; i <10 ; ++i){
        list_1.insertBack(i);
    }
    std::cout<<list_1;

    for(long i = 9 ; i > -1 ; --i){
        list_1.insertFront(i);
    }
    std::cout<<list_1;

    ls::List<long>::iterator endIt(list_1.end());
    ls::List<long>::iterator firstIt(list_1.begin());
    // tf::getFirstDuplicates(list_1);

    ls::List<long> list_2(list_1);
    std::cout<<list_2;

    for(size_t i = 0 ; i <5; ++i){
        std::cout<<list_2.extractBack()<<'\n';
    }

    for(size_t i = 0 ; i <19; ++i){
        std::cout<<list_1.extractFront()<<'\n';
    }
    std::cout<<list_1;
    std::cout<<list_2;
    list_2 = list_1;
    std::cout<<list_1;
    std::cout<<list_2;
}

void test2_Rational(){
    ls::List<Rational> list_1;
    for(long i = 0 ; i <10 ; ++i){
        list_1.insertBack(Rational(i,i+8));
    }
    std::cout<<list_1;

    for(long i = 9 ; i > -1 ; --i){
        list_1.insertFront(Rational(i*2,i+7));
    }
    std::cout<<list_1;


    ls::List<Rational> list_2(list_1);
    std::cout<<list_2;

    for(size_t i = 0 ; i <5; ++i){
        std::cout<<list_2.extractBack()<<'\n';
    }

    for(size_t i = 0 ; i <19; ++i){
        std::cout<<list_1.extractFront()<<'\n';
    }
    std::cout<<list_2;
    std::cout<<list_1;
    list_2 = list_1;
    std::cout<<list_2;
    std::cout<<list_1;

}

int main(){
    test1_long();
    test2_Rational();
    return 0;
}