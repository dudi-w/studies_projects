#include <vector>
#include "VirtualMachine.hpp"
#include "assert.h"

/*declaration*/
// vm::Log translate(vm::Code& code , const char* const program);
// size_t checkValid(const char* const program);


vm::VirtualMachine::VirtualMachine()
: m_it(nullptr)
{}

void vm::VirtualMachine::run( std::vector<int32_t> const& code)
{
    cleanMem();
    
    m_it = code.begin();
    while(m_it != code.end()){
        
        vm::OpCode log = execute(static_cast<vm::OpCode>(*m_it));

        if(log == vm::OpCode::Jmp){
            ++m_it;
            m_it = &code.at(*m_it);
        }
        if(log == vm::OpCode::Halt){
            return;
        };
        ++m_it;
    }
}

vm::OpCode vm::VirtualMachine::execute(vm::OpCode const code)
{
    switch(code){

        case vm::OpCode::Add:
            add();
            break;

        case vm::OpCode::Sub:
            sub();
            break;

        case vm::OpCode::Mul:
            mul();
            break;

        case vm::OpCode::Div:
            div();
            break;

        case vm::OpCode::Pop:
            pop();
            break;

        case vm::OpCode::Push:
            return VirtualMachine::push();
            break;

        case vm::OpCode::Dup:
            dup();
            break;

        case vm::OpCode::Swap:
            swap();
            break;
        
        case vm::OpCode::Print:
            print();
            break;

        case vm::OpCode::PrintC:
            printC();
            break;

        case vm::OpCode::Nop:
            nop();
            break;

        case vm::OpCode::Halt:
            return halt();
            break;

        case vm::OpCode::Inc:
            inc();
            break;

        case vm::OpCode::Dec:
            dec();
            break;

        default:
            break;
    }
    return vm::OpCode::Nop;
}

void vm::VirtualMachine::cleanMem()
{
    while(!m_stackMem.empty()){
        m_stackMem.pop();
    }
}

void vm::VirtualMachine::add()
{
    m_stackMem.push(pop()+pop());
}

void vm::VirtualMachine::sub()
{
    m_stackMem.push(pop()-pop());
}

void vm::VirtualMachine::mul()
{
    m_stackMem.push(pop()*pop());
}

void vm::VirtualMachine::div()
{
    m_stackMem.push(pop()/pop());
}

int32_t vm::VirtualMachine::pop()
{
    int32_t data = m_stackMem.top();
    m_stackMem.pop();
    return data;
}

vm::OpCode vm::VirtualMachine::push()
{
    ++m_it;
    m_stackMem.push(*m_it);
    return OpCode::Push;
}

void vm::VirtualMachine::dup()
{
    m_stackMem.push(m_stackMem.top());
}

void vm::VirtualMachine::swap()
{
    int32_t data1 = pop();
    int32_t data2 = pop();
    m_stackMem.push(data1);
    m_stackMem.push(data2);
}

void vm::VirtualMachine::print()
{
    std::cout<<pop();
}

void vm::VirtualMachine::printC()
{
    std::cout<<static_cast<char>(pop());
}

void vm::VirtualMachine::nop()
{}

vm::OpCode vm::VirtualMachine::halt()
{
    return vm::OpCode::Halt;
}

void vm::VirtualMachine::inc()
{
    int32_t data = pop();
    m_stackMem.push(++data);
}

void vm::VirtualMachine::dec()
{
    int32_t data = pop();
    m_stackMem.push(--data);
}

void vm::VirtualMachine::jmp()
{
    ++m_it;
    int32_t address = *m_it;
    m_it = &code[address];
}

void vm::VirtualMachine::jz()
{

}

void vm::VirtualMachine::jnz()
{

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