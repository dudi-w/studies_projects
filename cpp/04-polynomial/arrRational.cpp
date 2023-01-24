#include "arrRational.hpp"

ds::ArrRational::ArrRational():
m_size(1),
m_arr(new Rational[m_size])
{}

ds::ArrRational::ArrRational(size_t size):
m_size(size),
m_arr(new Rational[m_size])
{
    if(m_size==0){
        throw std::invalid_argument("degree must by non negative");
    }
}

ds::ArrRational::ArrRational(size_t size , const Rational* const arr):
ArrRational(size)
{
    std::copy(arr , arr+m_size, m_arr);
}

ds::ArrRational::ArrRational(const ArrRational& other):
ArrRational(other.m_size, other.m_arr)
{}

ds::ArrRational::~ArrRational()
{
    if(m_arr!=NULL){
        delete[] m_arr; 
    }
}

ds::ArrRational& ds::ArrRational::operator=( const ArrRational& other)
{

    if (&other == this){
		return *this;
    }
	if (m_arr != NULL){
		delete[] m_arr;
    }
	m_arr = new Rational[other.m_size];
    m_size = other.m_size;
    std::copy(other.m_arr , other.m_arr+m_size, m_arr);
	return *this;
}

Rational& ds::ArrRational::operator[](size_t i)
{   
    if(i>=m_size){
        throw std::range_error("out of renge");
    }
    return m_arr[i];
}

const Rational& ds::ArrRational::operator[](size_t i) const
{
    if(i>=m_size){
        throw std::range_error("out of renge");
    }
    return m_arr[i];
}

size_t ds::ArrRational::getSize() const
{
    return m_size;
}

void ds::ArrRational::display() const
{
    for(size_t i(m_size);i>0;--i){
        std::cout <<"\033[1;34m"<< m_arr[i-1] << "\033[0mX^" << i-1 << " + " <<std::flush;
    }
    std::cout<<std::endl;
}