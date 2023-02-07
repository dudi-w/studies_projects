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
        [](VirtualMachine&){return vm::OpCode::Call;},
        &VirtualMachine::ret,
        [](VirtualMachine&){return vm::OpCode::Nop;}
    }
)
{}

void vm::VirtualMachine::run( std::vector <int32_t> const& code)
{
    cleanMem();

    while(true){
        if(code[m_index]>=(int32_t)m_functions.size()){
            assert(!"invalid program");
        }
        vm::OpCode log = m_functions[code[m_index]](*this);

        if(log == vm::OpCode::Push){
            m_memStack.push(code[++m_index]);
        }

        if(log == vm::OpCode::Call){
            m_callStack.push(m_index+2);
            log = vm::OpCode::Jmp;
        }

        if(log == vm::OpCode::Jmp){
            m_index = code[++m_index];
            continue;
        }

        if(log == vm::OpCode::Halt){
            break;
        };
        ++m_index;
    }
}

void vm::VirtualMachine::cleanMem()
{
    while(!m_memStack.empty()){
        m_memStack.pop();
    }
    m_index= 0;
}

vm::OpCode vm::VirtualMachine::add()
{   
    int32_t data1 = m_memStack.top();
    pop();
    assert(!m_memStack.empty() && "invalid program");
    int32_t data2 = m_memStack.top();
    pop();
    m_memStack.push(data1+data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::sub()
{
    int32_t data1 = m_memStack.top();
    pop();
    assert(!m_memStack.empty() && "invalid program");
    int32_t data2 = m_memStack.top();
    pop();
    m_memStack.push(data1-data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::mul()
{
    int32_t data1 = m_memStack.top();
    pop();
    assert(!m_memStack.empty() && "invalid program");
    int32_t data2 = m_memStack.top();
    pop();
    m_memStack.push(data1*data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::div()
{
    int32_t data1 = m_memStack.top();
    pop();
    assert(!m_memStack.empty() && "invalid program");
    int32_t data2 = m_memStack.top();
    pop();
    m_memStack.push(data1/data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::pop()
{
    m_memStack.pop();
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::dup()
{
    m_memStack.push(m_memStack.top());
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::swap()
{
    int32_t data1 = m_memStack.top();
    m_memStack.pop();
    int32_t data2 = m_memStack.top();
    m_memStack.pop();
    m_memStack.push(data1);
    m_memStack.push(data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::print()
{
    std::cout<<m_memStack.top()<<std::flush;
    m_memStack.pop();
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::printC()
{
    std::cout<<static_cast<char>(m_memStack.top())<<std::flush;
    m_memStack.pop();
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::inc()
{
    int32_t data = m_memStack.top();
    m_memStack.pop();
    m_memStack.push(++data);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::dec()
{
    int32_t data = m_memStack.top();
    m_memStack.pop();
    m_memStack.push(--data);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::jz()
{
    if(!m_memStack.top()){
        m_memStack.pop();
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
    if(m_memStack.top()){
        m_memStack.pop();
        return vm::OpCode::Jmp;
    }
    else{
        pop();
        ++m_index;
        return vm::OpCode::Nop;
    }
}

// vm::OpCode vm::VirtualMachine::call()
// {
// 
// }

vm::OpCode vm::VirtualMachine::ret()
{
    m_index = m_callStack.top()-1;
    m_callStack.pop();
    return vm::OpCode::Nop;
}