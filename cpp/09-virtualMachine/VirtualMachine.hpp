#ifndef VIRTUALMACHINE_HPP
#define VIRTUALMACHINE_HPP

#include <stack>
#include <vector>
#include <unordered_map>
#include <functional>
#include "report.hpp"

namespace vm
{

class VirtualMachine
{
public:
    explicit VirtualMachine();
    VirtualMachine(VirtualMachine const& other) = default;
    VirtualMachine& operator=(VirtualMachine const& other) = default;
    ~VirtualMachine() = default;

    vm::Report run(std::vector<int32_t> const& code);

private:
    vm::Log add();
    vm::Log sub();
    vm::Log mul();
    vm::Log div();
    vm::Log pop();
    vm::Log dup();
    vm::Log swap();
    vm::Log print();
    vm::Log printC();
    vm::Log inc();
    vm::Log dec();
    vm::Log jz();
    vm::Log jnz();
    vm::Log ret();

    void cleanMem();

private:
    std::stack<int32_t> m_memStack;
    std::stack<int32_t> m_callStack;
    size_t m_index;
    std::unordered_map <vm::OpCode , std::function <vm::Log(vm::VirtualMachine&) > > m_functions;
};

}
#endif