#include <vector>
#include <stdlib.h>
#include <iostream>

void margSort(std::vector<int>& vec, size_t begin, size_t end){
    std::cout<<"begin"<< begin<<" end"<<end<<std::endl;
    if((end - begin)<=1){
        return;
    }
    size_t k = end/2;
    size_t j = begin;
    margSort(vec, begin, k);
    margSort(vec, k+1, end);

    std::vector<int> tmp;
    for(size_t i = 0; i < (end-begin) ; ++i){
        if(k == end || vec[j] <= vec[k]){
            tmp.push_back(vec[j++]);
            continue;
        }
        if(j == end/2 || vec[j] > vec[k]){
            tmp.push_back(vec[k++]);
            continue;
        }
    }
    vec = tmp;

}

int main(){
    std::vector<int> vec = {1,56,4641,516,13,13,3,8};
    margSort(vec, 0, vec.size());
    for(auto i : vec){
        std::cout<<i<<" ";
    }
    return 0;
}