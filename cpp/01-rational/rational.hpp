#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational
{
public:
    explicit Rational();
    explicit Rational(int n, int d);
    explicit Rational(int n);

    Rational operator+( const Rational& other) const;
    Rational operator-( const Rational& other) const;
    Rational operator*( const Rational& other) const;
    Rational operator/( const Rational& other) const;
    //Rational operator^( const Rational& other) const;
    
    Rational operator*(int n) const;
    Rational operator/(int n) const;
    Rational operator+(int n) const;
    Rational operator-(int n) const;
    
    Rational mul(int n) const;
    Rational div(int n) const;
    Rational add(int n) const;
    Rational sub(int n) const;
    
    Rational mul(const Rational& other) const;
    Rational div(const Rational& other) const;
    Rational add(const Rational& other) const;
    Rational sub(const Rational& other) const;
    
    Rational& operator+=(const Rational& other );
    Rational& operator-=(const Rational& other );
    Rational& operator*=(const Rational& other );
    Rational& operator/=(const Rational& other );

    bool operator>( const Rational& other) const;
    bool operator>=( const Rational& other) const;
    bool operator<( const Rational& other) const;
    bool operator<=( const Rational& other) const;
    bool operator==( const Rational& other) const;
    bool operator!=( const Rational& other) const;

    double value() const;

private:
    void makeGcd();

private:
    int m_numer;
    int m_denom;
};

std::ostream& operator<<(std::ostream& out , const Rational& self );
Rational operator+(int n, const Rational& self );
Rational operator-(int n, const Rational& self );
Rational operator*(int n, const Rational& self );
Rational operator/(int n, const Rational& self );


#endif