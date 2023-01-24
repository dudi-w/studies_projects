#include "../04-polynomial/dataStructure.hpp"

ds::ArrByte::ArrByte(size_t size):
m_size(size),
m_arr(new int8_t[m_size])
{}


ds::ArrByte::ArrByte(const ArrByte& other):
ArrByte(other.m_size)
{
    if(other.m_arr!=NULL){
        std::copy(other.m_arr , other.m_arr + other.m_size , m_arr);
    }
}
    
ds::ArrByte::~ArrByte()
{
    if(m_arr!=NULL){
        delete[] m_arr; 
    }
}

ds::ArrByte& ds::ArrByte::operator=( const ArrByte& other)
{
    if (&other == this){
		return *this;
    }
	if (m_arr != NULL){
		delete[] m_arr;
    }
	m_arr = new int8_t[other.m_size];
    m_size = other.m_size;
    std::copy(other.m_arr , other.m_arr+m_size, m_arr);
	return *this;
}

ds::ArrByte ds::ArrByte::operator+( const ArrByte& other) const
{
    if(m_arr == NULL){
        return other;
    }
    if(other.m_arr == NULL){
        return *this;
    }
    ds::ArrByte temp(m_size+ other.m_size);
    std::copy(m_arr, m_arr+m_size, temp.m_arr);
    std::copy(other.m_arr, other.m_arr+other.m_size, temp.m_arr+m_size);
    return temp;
}

ds::ArrByte& ds::ArrByte::operator+=( const ArrByte& other)
{
    return (*this) = (*this) + other;
}

int8_t& ds::ArrByte::operator[](size_t i)
{
    if(i>=m_size){
        throw std::range_error("out of renge");
    }
    return m_arr[i];
}

const int8_t& ds::ArrByte::operator[](size_t i) const
{
    if(i>=m_size){
        throw std::range_error("out of renge");
    }
    return m_arr[i];
}

void ds::ArrByte::cleanMamory() const
{
    memset(m_arr , 0 , m_size);
}

void ds::ArrByte::printArr() const
{
    for(size_t i= 0; i<m_size ; ++i){
        std::cout<<(int)m_arr[i]<<"-\t"<<std::flush;
    }
    std::cout<<'\n';
}

size_t ds::ArrByte::getSize() const
{
    return m_size;
}
