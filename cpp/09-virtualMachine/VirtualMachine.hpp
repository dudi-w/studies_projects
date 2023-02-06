#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <cstdlib>
#include <stack>
#include <vector>
#include "VMenum.hpp"

namespace vm
{

class VirtualMachine
{
public:
    explicit VirtualMachine();

    VirtualMachine(VirtualMachine const& other) = default;
    VirtualMachine& operator=(VirtualMachine const& other) = default;
    ~VirtualMachine() = default;

    void run(std::vector<int32_t> const& code);

private:
    vm::OpCode execute(vm::OpCode const code);
    void cleanMem();
    void add();
    void sub();
    void mul();
    void div();
    int32_t pop();
    vm::OpCode push();
    void dup();
    void swap();
    void print();
    void printC();
    void nop();
    vm::OpCode halt();
    void inc();
    void dec();
    void jmp();
    void jz();
    void jnz();

private:
    std::stack<int32_t> m_stackMem;
    std::vector<int32_t>::const_iterator m_it;
};

// vm::Code compiler(const char* const program);

}
#endif