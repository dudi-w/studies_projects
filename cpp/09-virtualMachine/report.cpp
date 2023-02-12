#include "report.hpp"

vm::Report::Report(size_t index, vm::OpCode code, vm::Log log , bool memEmpty, bool callEmpty)
: m_log(log)
, m_code(code)
, m_index(index)
, m_memEmpty(memEmpty)
, m_callEmpty(callEmpty)
{}

std::ostream& operator<<(std::ostream& out , const vm::Report& self )
{
    out << "\n\t---------------------" << std::endl;
    out << "halt the Run in index                   :" << self.getIndex() << std::endl;
    out << "During the execution of the operation   :" << vm::arrOpCodes[static_cast<size_t> (self.getCode())] << std::endl;
    out << "call stack is empty                     :" <<std::boolalpha<<self.getCallEmpty()<< std::endl;;
    out << "memory stack is empty                   :" <<std::boolalpha<<self.getMemEmpty()<< std::endl;;
    out << "the Log is report                       :" << vm::arrLogs[static_cast<size_t> (self.getLog())] << std::endl;
    out << "Running analysis                        :";
    if(self.getCode()==vm::OpCode::Halt && self.getCallEmpty() && self.getMemEmpty() && self.getLog()==vm::Log::Halt){
        out << "\033[3;32mSuccess\033[0m" << std::endl;
    }else if(self.getCode()!=vm::OpCode::Halt || self.getLog()!=vm::Log::Halt){
        out<<"\033[3;31mFailure\033[0m"<<std::endl;
    }else{
        out<<"N/A"<<std::endl;
    }
    return out;
}