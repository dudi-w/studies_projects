#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

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
    void cleanMem();
    vm::OpCode add();
    vm::OpCode sub();
    vm::OpCode mul();
    vm::OpCode div();
    vm::OpCode pop();
    vm::OpCode dup();
    vm::OpCode swap();
    vm::OpCode print();
    vm::OpCode printC();
    vm::OpCode inc();
    vm::OpCode dec();
    vm::OpCode jz();
    vm::OpCode jnz();

private:
    std::stack<int32_t> m_stackMem;
    size_t m_index;
    std::array<std::function<vm::OpCode(vm::VirtualMachine&)> ,SIZE_OPCODE-1> m_functions;
};

}
#endif