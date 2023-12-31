#include <iostream>
#include <assert.h> 
#include <math.h>
#include "rational.hpp"
 
int gcd(int a, int b)
{   
    if(a<0) a= std::abs(a);
    if (!b){
        return (a);
    }
    else{
        return gcd(b, a % b);
    }
}

int gcd2(int a, int b)
{
    if(!a || !b) return 1;
    if(a<0) a= std::abs(a);
    if(b<0) b= std::abs(b);
    if(b>a){
        int temp(a);
        a=b;
        b=temp;
    }
    while(b>0){
        int temp(b);
        b = a % b; 
        a = temp;
    }
    return a;
}

Rational::Rational():m_numer(0), m_denom(1)
{}

Rational::Rational(int n): m_numer(n), m_denom(1)
{}

Rational::Rational(int n, int d)
{
    if(!d){
        assert(d!=0 && "can't division by zero" );
    }
    int result = gcd(n,d);
    m_numer = n/result;
    m_denom = d/result;
}

double Rational::value() const
{   
    return (double)m_numer/m_denom;
}

Rational Rational::mul(const Rational& other) const
{
    return (*this)*other;
}

Rational Rational::div(const Rational& other) const
{
    return (*this)/other;
}

Rational Rational::add(const Rational& other) const
{
    return (*this)+other;
}

Rational Rational::sub(const Rational& other) const
{
    return (*this)-other;
}

Rational Rational::operator+( const Rational& other) const
{
    int numer = m_numer * other.m_denom + (other.m_numer * m_denom);
    int denom = m_denom * other.m_denom;
    Rational temp(numer , denom) ;
    return temp;
    
}

Rational Rational::operator-( const Rational& other) const
{
    int numer = m_numer * other.m_denom - (other.m_numer* (*this).m_denom);
    int denom = m_denom * other.m_denom;
    Rational temp(numer, denom);
    return temp;
}

Rational Rational::operator*( const Rational& other) const
{   
    int numer = m_numer* other.m_numer;
    int denom = m_denom* other.m_denom;
    Rational temp(numer, denom);
    return temp;
}

Rational Rational::operator/( const Rational& other) const
{
    int numer = m_numer* other.m_denom;
    int denom = m_denom* other.m_numer;
    Rational temp(numer, denom);
    return temp;

}

Rational Rational::operator*(int n) const
{
    Rational temp(n);
    return (*this)*temp;
}

Rational Rational::operator/(int n) const
{
    Rational temp(n);
    return (*this)/temp;
}

Rational Rational::operator+(int n) const
{
    Rational temp(n);
    return (*this)+temp;
}

Rational Rational::operator-(int n) const
{
    Rational temp(n);
    return (*this)-temp;
}

Rational Rational::mul(int n) const
{
    Rational temp(n);
    return (*this)*temp;
}

Rational Rational::div(int n) const
{
    Rational temp(n);
    return (*this)/temp;

}

Rational Rational::add(int n) const
{
    Rational temp(n);
    return (*this)+temp;
}

Rational Rational::sub(int n) const
{
    Rational temp(n);
    return (*this)-temp;
}

Rational& Rational::operator+=(const Rational& other )
{
    return *this = (*this)+other;
}

Rational& Rational::operator-=(const Rational& other )
{
    return *this = (*this)-other;
}

Rational& Rational::operator*=(const Rational& other )
{
   return (*this) = (*this)*other;
}

Rational& Rational::operator/=(const Rational& other )
{
    return (*this) = (*this)/other;
}

bool  Rational::operator>( const Rational& other) const
{
    return (*this).value() > other.value();
}

bool  Rational::operator>=( const Rational& other) const
{
    return (*this).value() >= other.value();
}

bool  Rational::operator<( const Rational& other) const
{
    return (*this).value() < other.value();
}

bool  Rational::operator<=( const Rational& other) const
{
   return (*this).value() <= other.value();
}

bool Rational::operator==( const Rational& other) const
{
    return (*this).value() == other.value();
}

bool Rational::operator!=( const Rational& other) const
{
    return !((*this)==other);
}

std::ostream& operator<<(std::ostream& out , const Rational& self )
{
    out << self.value() << std::flush;
    return out;
}

Rational operator+(int n, const Rational& self ){
    return self+n;
}

Rational operator-(int n, const Rational& self )
{
    Rational temp(n);
    return temp-self;
}

Rational operator*(int n, const Rational& self )
{
    return (self*n);
}

Rational operator/(int n, const Rational& self )
{
    Rational temp(n);
    return temp/self;
}

void Rational::makeGcd()
{
    int result = gcd(m_numer,m_denom);
    (*this).m_numer/=result;
    (*this).m_denom/=result;
}
