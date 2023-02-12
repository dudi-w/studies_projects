#ifndef REPORT_HPP
#define REPORT_HPP

#include "VMenum.hpp"

namespace vm
{
class Report
{
public:
    explicit Report(size_t index, vm::OpCode code, vm::Log log , bool memEmpty, bool callEmpty);
    Report(Report const& other) = default;
    Report& operator=(Report const& other) = default;
    ~Report() = default;

    vm::Log getLog() const{return m_log;}
    vm::OpCode getCode() const{return m_code;}
    size_t getIndex() const{return m_index;}
    bool getMemEmpty() const{return m_memEmpty;}
    bool getCallEmpty() const{return m_callEmpty;}

private:
    vm::Log m_log;
    vm::OpCode m_code;  
    size_t m_index;
    bool m_memEmpty;
    bool m_callEmpty;
};

}

std::ostream& operator<<(std::ostream& out , const vm::Report& self );

#endif