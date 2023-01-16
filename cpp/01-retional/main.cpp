#include <fstream>
#include <iostream>
#include "rational.hpp"

int  main(){
    Rational a1(1,2);
    Rational b1(5,2);
    std::cout << a1 << '\n';
    std::cout << b1 << '\n';
    Rational c1 = a1+b1;
    std::cout << c1 << '\n';
    c1 += 0*a1;
    std::cout << c1 << '\n';
    c1 = a1-b1;   
    std::cout <<  c1 << '\n';
    c1 = a1/b1;
    Rational p1(1029,1071);
    std::cout << (3+a1) << '\n';

    return 0;
}