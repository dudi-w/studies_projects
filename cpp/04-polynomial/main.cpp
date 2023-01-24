#include "polynomial.hpp"

int main(){
    poly::Polynomial aa(5);
    // aa.displye();
    aa.at(5) = Rational(7);
    aa.at(4) = Rational(-4);
    aa.at(1) = Rational(3);
    aa.at(0) = Rational(-9);
    std::cout<<aa.valueAt(3)<<'\n';
    // aa.displye();
    poly::Polynomial bb(4);
    bb.at(4) = Rational(1);
    bb.at(2) = Rational(-4);
    bb.at(1) = Rational(3);
    bb.displye();
    (bb-aa).displye();
    (aa-bb).displye();
    poly::Polynomial cc(4);
    cc.at(4) = Rational(1);
    cc.at(0) = Rational(-3,1);
    poly::Polynomial dd(2);
    dd.at(2) = Rational(4);
    dd.at(1) = Rational(3);
    dd.at(0) = Rational(-9);
    dd.displye();
    poly::Polynomial ee = (dd*cc);
    ee.displye();
    ee.ppp().displye();
    (ee/dd).ppp().displye();
    return 0;
}