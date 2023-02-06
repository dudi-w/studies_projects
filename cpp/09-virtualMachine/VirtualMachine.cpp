#include <vector>
#include "VirtualMachine.hpp"
#include "assert.h"

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
        [](VirtualMachine&){return vm::OpCode::Nop;}
    }
)
{}

void vm::VirtualMachine::run( std::vector <int32_t> const& code)
{
    cleanMem();

    while(true){
        
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

// vm::OpCode vm::VirtualMachine::execute(vm::OpCode const code)
// {
//     switch(code){

//         case vm::OpCode::Add:
//             return add();
//             break;

//         case vm::OpCode::Sub:
//             return sub();
//             break;

//         case vm::OpCode::Mul:
//             return mul();
//             break;

//         case vm::OpCode::Div:
//             return div();
//             break;

//         case vm::OpCode::Pop:
//             return pop();
//             break;

//         case vm::OpCode::Push:
//             return push();
//             break;

//         case vm::OpCode::Dup:
//             return dup();
//             break;

//         case vm::OpCode::Swap:
//             return swap();
//             break;
        
//         case vm::OpCode::Print:
//             return print();
//             break;

//         case vm::OpCode::PrintC:
//             return printC();
//             break;

//         case vm::OpCode::Nop:
//             return nop();
//             break;

//         case vm::OpCode::Halt:
//             return halt();
//             break;

//         case vm::OpCode::Inc:
//             return inc();
//             break;

//         case vm::OpCode::Dec:
//             return dec();
//             break;

//         case vm::OpCode::Jmp:
//             return jmp();
//             break;

//         case vm::OpCode::Jz:
//             return jz();
//             break;

//         case vm::OpCode::Jnz:
//             return jnz();
//             break;

//         default:
//             break;
//     }
//     return vm::OpCode::Nop;
// }

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
    int32_t data2 = m_stackMem.top();
    pop();
    m_stackMem.push(data1+data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::sub()
{
    int32_t data1 = m_stackMem.top();
    pop();
    int32_t data2 = m_stackMem.top();
    pop();
    m_stackMem.push(data1-data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::mul()
{
    int32_t data1 = m_stackMem.top();
    pop();
    int32_t data2 = m_stackMem.top();
    pop();
    m_stackMem.push(data1*data2);
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::div()
{
    int32_t data1 = m_stackMem.top();
    pop();
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

vm::OpCode vm::VirtualMachine::push()
{
    return OpCode::Push;
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

vm::OpCode vm::VirtualMachine::nop()
{
    return vm::OpCode::Nop;
}

vm::OpCode vm::VirtualMachine::halt()
{
    return vm::OpCode::Halt;
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

vm::OpCode vm::VirtualMachine::jmp()
{
    return vm::OpCode::Jmp;
}

vm::OpCode vm::VirtualMachine::jz()
{
    if(!m_stackMem.top()){
        return jmp();
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
        return jmp();
    }
    else{
        pop();
        ++m_index;
        return vm::OpCode::Nop;
    }
}


// vm::Code vm::compiler(const char* const program)
// {
//     size_t size = checkValid(program);
    
//     if(!size){
//         assert(!"invalid code");
//     }
    
//     vm::Code code(size);
//     translate(code , program);
//     return code;
// }

// size_t checkValid(const char* const program)
// {
//     size_t count, headLoop, endLoop;
//     count = headLoop = endLoop = 0;
    
//     for(size_t i=0 ; program[i]!='\0' ; ++i){
//         if( program[i]== '<' || program[i]== '>' ||
//             program[i]== '.' || program[i]== ',' ||
//             program[i]== '+' || program[i]== '-'){
//             ++count;
//         }
//         if(program[i]== '['){
//             ++headLoop;
//             ++count;
//         }
//         if(program[i]== ']'){
//             ++endLoop;
//             ++count;
//         }
//         if(endLoop > headLoop){
//             return 0;
//         }
//     }
//     return (headLoop==endLoop) ? count +1 : 0;
// }

// vm::Log translate(vm::Code& code , const char* const program)
// {
//     size_t i = 0;

//     while(program[i]!= '\0'){
//         switch(program[i++]){

//             case '>':
//                 code.setOp(vm::OpCode::Right);
//                 break;

//             case '<':
//                 code.setOp(vm::OpCode::Left);
//                 break;

//             case '.':
//                 code.setOp(vm::OpCode::Read);
//                 break;

//             case ',':
//                 code.setOp(vm::OpCode::Write);
//                 break;

//             case '+':
//                 code.setOp(vm::OpCode::Increment);
//                 break;

//             case '-':
//                 code.setOp(vm::OpCode::Decrement);
//                 break;

//             case '[':
//                 code.setOp(vm::OpCode::LoopBegin);
//                 break;

//             case ']':
//                 code.setOp(vm::OpCode::LoopEnd);
//                 break;

//             default:
//             code<<1;                    //In order to stay the same place in memory
//                 break;
//         }
//         code>>1;               
//     }
//     code.setOp(vm::OpCode::EndOp);      //To indicate the end of the program
//     return vm::Log::success;
// }