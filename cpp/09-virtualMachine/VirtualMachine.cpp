#include <vector>
#include "VirtualMachine.hpp"
#include "assert.h"

/*declaration*/
// vm::Log translate(vm::Code& code , const char* const program);
// size_t checkValid(const char* const program);


vm::VirtualMachine::VirtualMachine()
{}

void vm::VirtualMachine::run( std::vector<vm::VMdata> const code)
{
    cleanMem();
    
    std::vector<vm::VMdata>::const_iterator it = code.begin();
    while(it != code.end()){
        
        execute((*it).code);
        vm::VMdata::OpCode log = execute((*it).code);

        if(log == vm::VMdata::OpCode::Push){
            ++it;
            m_stackMem.push((*it).data);
        }
        if(log == vm::VMdata::OpCode::Halt){
            return;
        };
        ++it;
    }
}

vm::VMdata::OpCode vm::VirtualMachine::execute(vm::VMdata::OpCode const code)
{
    switch(code){

        case vm::VMdata::OpCode::Add:
            add();
            break;

        case vm::VMdata::OpCode::Sub:
            sub();
            break;

        case vm::VMdata::OpCode::Mul:
            mul();
            break;

        case vm::VMdata::OpCode::Div:
            div();
            break;

        case vm::VMdata::OpCode::Pop:
            pop();
            break;

        case vm::VMdata::OpCode::Push:
            return VirtualMachine::push();
            break;

        case vm::VMdata::OpCode::Dup:
            dup();
            break;

        case vm::VMdata::OpCode::Swap:
            swap();
            break;
        
        case vm::VMdata::OpCode::Print:
            print();
            break;

        case vm::VMdata::OpCode::PrintC:
            printC();
            break;

        case vm::VMdata::OpCode::Nop:
            nop();
            break;

        case vm::VMdata::OpCode::Halt:
            return halt();
            break;

        case vm::VMdata::OpCode::Inc:
            inc();
            break;

        case vm::VMdata::OpCode::Dec:
            dec();
            break;

        default:
            break;
    }
    return vm::VMdata::OpCode::Nop;
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

vm::VMdata::OpCode vm::VirtualMachine::push()
{
    return:VMdata::OpCode::Push;
}

void vm::VirtualMachine::dup()
{
    m_stackMem.push(m_stackMem.top());
}

void vm::VirtualMachine::swap()
{
    int32_t data1 = pop();
    int32_t data2 = pop();
    m_stackMem.push(data2);
    m_stackMem.push(data1);
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

vm::VMdata::OpCode vm::VirtualMachine::halt()
{
    return vm::VMdata::OpCode::Halt;
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
//                 code.setOp(vm::VMdata::OpCode::Right);
//                 break;

//             case '<':
//                 code.setOp(vm::VMdata::OpCode::Left);
//                 break;

//             case '.':
//                 code.setOp(vm::VMdata::OpCode::Read);
//                 break;

//             case ',':
//                 code.setOp(vm::VMdata::OpCode::Write);
//                 break;

//             case '+':
//                 code.setOp(vm::VMdata::OpCode::Increment);
//                 break;

//             case '-':
//                 code.setOp(vm::VMdata::OpCode::Decrement);
//                 break;

//             case '[':
//                 code.setOp(vm::VMdata::OpCode::LoopBegin);
//                 break;

//             case ']':
//                 code.setOp(vm::VMdata::OpCode::LoopEnd);
//                 break;

//             default:
//             code<<1;                    //In order to stay the same place in memory
//                 break;
//         }
//         code>>1;               
//     }
//     code.setOp(vm::VMdata::OpCode::EndOp);      //To indicate the end of the program
//     return vm::Log::success;
// }