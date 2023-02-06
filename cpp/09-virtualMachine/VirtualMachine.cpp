#include "VirtualMachine.hpp"
#include <assert.h>


vm::VirtualMachine::VirtualMachine()
: m_index(0)
, m_functions(
    {
        &VirtualMachine::pop,
        [](VirtualMachine&){return vm::OpCode::Push;},
        &VirtualMachine::add,
        &VirtualMachine::sub,
        &VirtualMachine::mul,
        &VirtualMachine::div,
        &VirtualMachine::inc,
        &VirtualMachine::dec,
        &VirtualMachine::dup,
        &VirtualMachine::swap,
        &VirtualMachine::print,
        &VirtualMachine::printC,
        [](VirtualMachine&){return vm::OpCode::Jmp;},
        &VirtualMachine::jz,
        &VirtualMachine::jnz,
        [](VirtualMachine&){return vm::OpCode::Halt;},
        // [](VirtualMachine&){return vm::OpCode::Nop;}
    }
)
{}

void vm::VirtualMachine::run( std::vector <int32_t> const& code)
{
    cleanMem();

    while(true){
        assert(!(code[m_index]>=(int32_t)m_functions.size()) && "invalid program");
        vm::OpCode log = m_functions[code[m_index]](*this);

        if(log == vm::OpCode::Push){
            ++m_index;
            m_stackMem.push(code[m_index]);
        }
        if(log == vm::OpCode::Jmp){
            ++m_index;
            m_index = code[m_index]-1;
        }
        if(log == vm::OpCode::Halt){
            return;
        };
        ++m_index;
    }
}

void vm::VirtualMachine::cleanMem()
{
    while(!m_stackMem.empty()){
        m_stackMem.pop();
    }
    m_index= 0;
}

vm::OpCode vm::VirtualMachine::add()
{   
    int32_t data1 = m_stackMem.top();
    pop();
    assert(!m_stackMem.empty() && "invalid program");
    int32_t data2 = m_stackMem.top();
    pop();
    m_stackMem.push(data1+data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::sub()
{
    int32_t data1 = m_stackMem.top();
    pop();
    assert(!m_stackMem.empty() && "invalid program");
    int32_t data2 = m_stackMem.top();
    pop();
    m_stackMem.push(data1-data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::mul()
{
    int32_t data1 = m_stackMem.top();
    pop();
    assert(!m_stackMem.empty() && "invalid program");
    int32_t data2 = m_stackMem.top();
    pop();
    m_stackMem.push(data1*data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::div()
{
    int32_t data1 = m_stackMem.top();
    pop();
    assert(!m_stackMem.empty() && "invalid program");
    int32_t data2 = m_stackMem.top();
    pop();
    m_stackMem.push(data1/data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::pop()
{
    m_stackMem.pop();
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::dup()
{
    m_stackMem.push(m_stackMem.top());
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::swap()
{
    int32_t data1 = m_stackMem.top();
    m_stackMem.pop();
    int32_t data2 = m_stackMem.top();
    m_stackMem.pop();
    m_stackMem.push(data1);
    m_stackMem.push(data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::print()
{
    std::cout<<m_stackMem.top()<<std::flush;
    m_stackMem.pop();
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::printC()
{
    std::cout<<static_cast<char>(m_stackMem.top())<<std::flush;
    m_stackMem.pop();
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::inc()
{
    int32_t data = m_stackMem.top();
    m_stackMem.pop();
    m_stackMem.push(++data);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::dec()
{
    int32_t data = m_stackMem.top();
    m_stackMem.pop();
    m_stackMem.push(--data);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::jz()
{
    if(!m_stackMem.top()){
        m_stackMem.pop();
        return vm::OpCode::Jmp;

    }
    else{
        pop();
        ++m_index;
        return vm::OpCode::Nop;
    }

}

vm::OpCode vm::VirtualMachine::jnz()
{
    if(m_stackMem.top()){
        m_stackMem.pop();
        return vm::OpCode::Jmp;
    }
    else{
        pop();
        ++m_index;
        return vm::OpCode::Nop;
    }
}