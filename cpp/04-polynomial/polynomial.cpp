#include "polynomial.hpp"

poly::Polynomial::Polynomial():
m_degree(0)
,m_coeff()
{}

poly::Polynomial::Polynomial(size_t degree):
m_degree(degree),
m_coeff(degree+1)
{}

poly::Polynomial::Polynomial(size_t degree , const Rational* const arr):
m_degree(degree),
m_coeff(degree+1,arr)
{}

poly::Polynomial poly::Polynomial::operator+( const Polynomial& other) const
{
    size_t maxDegree = ((*this).m_degree > other.m_degree)? (*this).m_degree : other.m_degree;
    poly::Polynomial newPoly(maxDegree);
    for(size_t i=0 ; i<= maxDegree;++i){
        if(i<=(*this).m_degree && i<=other.m_degree){
            newPoly.m_coeff[i]= (*this).m_coeff[i] + other.m_coeff[i];
            continue;
        }
        if(i<=(*this).m_degree){
            newPoly.m_coeff[i]= (*this).m_coeff[i];
            continue;
        }
        if(i<=other.m_degree){
            newPoly.m_coeff[i]= other.m_coeff[i];
            continue;
        }
    }
    newPoly.reSize();
    return newPoly;
}


poly::Polynomial poly::Polynomial::operator-( const Polynomial& other) const
{
    size_t maxDegree = ((*this).m_degree > other.m_degree)? (*this).m_degree : other.m_degree;
    poly::Polynomial newPoly(maxDegree);
    for(size_t i=0 ; i<= maxDegree;++i){
        if(i<=(*this).m_degree && i<=other.m_degree){
            newPoly.m_coeff[i]= (*this).m_coeff[i] - other.m_coeff[i];
            continue;
        }
        if(i<=(*this).m_degree){
            newPoly.m_coeff[i]= (*this).m_coeff[i];
            continue;
        }
        if(i<=other.m_degree){
            newPoly.m_coeff[i]= 0 - other.m_coeff[i];
            continue;
        }
    }
    newPoly.reSize();
    return newPoly;
}

poly::Polynomial poly::Polynomial::operator*( const Polynomial& other) const
{
    poly::Polynomial newPoly((*this).m_degree + other.m_degree +1);
    for(size_t i(0); i< (*this).m_degree+1 ; ++i){
        for(size_t j(0) ; j< other.m_degree +1 ; ++j){
            newPoly.m_coeff[i+j] += (*this).m_coeff[i] * other.m_coeff[j];
        }
    }
    newPoly.reSize();
    return newPoly;
}

poly::Polynomial poly::Polynomial::operator/( const Polynomial& other) const
{
    if((*this).m_degree<other.m_degree){
        throw;
    }
    poly::Polynomial result(m_degree-other.m_degree);
    poly::Polynomial rest(*this);
    poly::Polynomial temp;
    while(!(rest.m_degree<other.m_degree))
    {   
        poly::Polynomial temp2(rest.m_degree-other.m_degree);
        temp2.at(rest.m_degree-other.m_degree)= m_coeff[rest.m_degree]/other.m_coeff[other.m_degree];    
        result= result+temp2;
        temp = temp2 * other;
        rest = rest - temp;
        rest.reSize();
    }
    return result;
}

/*Rational& poly::Polynomial::at(size_t i) const
{
    return m_coeff[i];
}*/

Rational& poly::Polynomial::at(size_t i)
{   
    return m_coeff[i];
}

float poly::Polynomial::valueAt(double x) const
{
    float result=0;
    for(size_t i(0); i<m_coeff.getSize() ; ++i){
        result+= m_coeff[i].value()*pow(x,i);
    }
    return result;
}

Rational poly::Polynomial::valueAt(Rational x) const
{
    Rational result = m_coeff[0];
    Rational temp = x;
    for(size_t i(1); i<m_coeff.getSize() ; ++i){
        result += (m_coeff[i] * temp);
        temp*=x;
    }
    return result;
}

void poly::Polynomial::reSize()
{   
    size_t i(m_degree+1);
    while(i>0 && m_coeff[i-1].value() == 0)
    {
        --i;
    }
    if(!i){
        ds::ArrRational temp(m_coeff);
        m_coeff = ds::ArrRational();
    }
    else{
        --i;
        ds::ArrRational temp(m_coeff);
        m_coeff = ds::ArrRational(i+1);
        for(size_t j(0);j<=i;++j){
            m_coeff[j]= temp[j];
        }
    }
    m_degree = i;
}

poly::Polynomial poly::Polynomial::derivative() const
{
    poly::Polynomial newpoly(m_degree-1);
    for(size_t i= 0; i<=newpoly.m_degree;++i){
        newpoly.m_coeff[i] = (*this).m_coeff[i+1]*(i+1);
    }
    return newpoly;
}

void poly::Polynomial::displye() const
{
    m_coeff.display();
}