#include "polynomial.hpp"

int main(){
    poly::Polynomial poly1(5);
    poly1.at(5) = Rational(7);
    poly1.at(4) = Rational(-4);
    poly1.at(1) = Rational(3);
    poly1.at(0) = Rational(-9);
    std::cout<<poly1.valueAt(3)<<'\n';
    poly::Polynomial poly2(4);
    poly2.at(4) = Rational(1);
    poly2.at(2) = Rational(-4);
    poly2.at(1) = Rational(3);
    poly2.displye();
    (poly2-poly1).displye();
    (poly1-poly2).displye();
    poly::Polynomial poly3(4);
    poly3.at(4) = Rational(1);
    poly3.at(0) = Rational(-3,1);
    poly::Polynomial poly4(2);
    poly4.at(2) = Rational(4);
    poly4.at(1) = Rational(3);
    poly4.at(0) = Rational(-9);
    poly4.displye();
    poly::Polynomial poly5 = (poly4*poly3);
    poly5.displye();
    poly5.derivative().displye();
    (poly5/poly4).derivative().displye();

    return 0;
}