#include "stack.hpp"

Stack::Stack():
m_capacity(STACK_SIZE),
m_top(-1),
m_pArr(new int[m_capacity])
{}

Stack::Stack(const Stack& other):
m_capacity(other.m_capacity),
m_top(other.m_top),
m_pArr(new int[m_capacity])
{
    for(int i(getSize()-1); i>=0 ;--i){
        m_pArr[i]=other.m_pArr[i];
    }
}

Stack::~Stack()
{	if(m_pArr!=NULL){
    	delete[] m_pArr;
    }
}

Stack& Stack::operator=(const Stack& other)
{
	if (&other == this)
		return *this;

	if (m_pArr != NULL)
		delete[] m_pArr;
	m_pArr = new int[other.m_capacity];
	m_capacity = other.m_capacity;
	for(int i(0); i < getSize() ;i++)
		m_pArr[i] = other.m_pArr[i];

	return *this;

}

void Stack::push(int n)
{
    if(m_top < (int)m_capacity-1){
        m_pArr[++m_top] = n;
    }
    else
    {
        realloc();
        //m_pArr[++m_top] = n;
        (*this).push(n);
    }
}
int Stack::pop()
{   if(!isEmpty()){
        return m_pArr[m_top--];
    }
    else{
        throw std::underflow_error("The stack is empty!");
    } 
}

void Stack::display() const
{
    for(int i(getSize()-1); i>=0 ;--i){
       std::cout << m_pArr[i] << " -> " << std::flush;
    }
    std::cout << std::endl;
}

int Stack::top() const
{
    if(!isEmpty()){
        return m_pArr[m_top];
    }
    else{
        throw std::underflow_error("The stack is empty!");
    } 

}

int Stack::getSize() const
{
    return m_top+1;
}

bool Stack:: isEmpty() const
{
    return (m_top==-1);
}

void Stack::realloc()
{
    int * newArr = new int[m_capacity*2];
    for(std::size_t i(0) ; i<m_capacity ; ++i){
        newArr[i] = m_pArr[i];
    }
    int* temp= m_pArr;
    m_pArr = newArr;
    delete[] temp;
    m_capacity*=2;
}
