#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <cstdlib>
#include <stack>
#include <vector>
#include <array>
#include <functional>
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
    vm::OpCode add();
    vm::OpCode sub();
    vm::OpCode mul();
    vm::OpCode div();
    vm::OpCode pop();
    vm::OpCode push();
    vm::OpCode dup();
    vm::OpCode swap();
    vm::OpCode print();
    vm::OpCode printC();
    vm::OpCode nop();
    vm::OpCode halt();
    vm::OpCode inc();
    vm::OpCode dec();
    vm::OpCode jmp();
    vm::OpCode jz();
    vm::OpCode jnz();

private:
    std::stack<int32_t> m_stackMem;
    size_t m_index;
    std::array<std::function<vm::OpCode(vm::VirtualMachine&)> ,17> m_functions;
};

// vm::Code compiler(const char* const program);

}
#endif