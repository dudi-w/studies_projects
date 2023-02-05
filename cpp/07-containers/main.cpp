#include <iostream>
#include "templateFunction2.hpp"


void test1(){

    std::array<int,7UL> arr{52,12,17,27,525,200,200};
    std::optional<size_t*> resulteArr = tf::getDuplicates(arr);

    if(resulteArr.has_value()){
        std::cout<<(*resulteArr)[0] <<'\t' << resulteArr.value()[1] <<'\f'<<'\r';
        delete[] *resulteArr;
    }

    int arr2[]={500,512,217,127,52,20,1};
    std::cout<<"\033[3;33mis sorted ? "<<std::boolalpha<<tf::isSorted(arr2, 7)<<"\033[0m\n";
}


void test2(){
    std::array<int,7> arr{52,12,17,27,525,200,200};
    std::array<int,7>::const_iterator it1  = tf::getFirstUniq(arr);
    if(it1 != arr.end()){
        std::cout<<*it1<<std::flush<<std::endl;
    }

    std::array<int,7>::const_iterator it2  = tf::getFirstDuplicates(arr);
        if(it2 != arr.end()){
        std::cout<<*it2<<std::flush<<std::endl;
    }
}

int main()
{
    test1();
    test2();
    return 0;
}