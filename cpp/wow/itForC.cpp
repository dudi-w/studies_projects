#include <algorithm>
#include <iostream>
#include <map>
#include <array>

void findElemet(int arr[])
{
    auto res = std::find(std::begin(arr), std::end(arr), 3);
    (res != std::end(arr)) ? (std::cout<<"resulte = "<<*res<<std::endl) : (std::cout<<"no exis value"<<std::endl);
}

void itForStyleC(void){
    int arr[] = {1,2,3,4,5};
    findElemet(arr);
}

void map()
{
    std::map<int, int> myMap;
    std::cout<<std::boolalpha<<(myMap[1] == 0 && myMap[1] == 0 && myMap[2] == 0 && myMap.size() == 3);
}

int main(){
    itForStyleC();
    return EXIT_SUCCESS;
}