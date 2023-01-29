#include "brainfuck.hpp"
// #include <memory.h>


bf::Brainfuck::Brainfuck(size_t size):
m_runMem(size)
{}

bf::Log bf::Brainfuck::compiler(const char* const program)
{
    size_t size = checkValid(program);
    if(!size){
        return Log::inValidProgram;
    }
    m_codeStor = bf::Code(size);
    return translate(program);
}

bf::Log bf::Brainfuck::run()
{
    m_runMem.cleanMem();
    OpCode op;
    while(m_codeStor.getCurrentOp()!= OpCode::EndOp){
        op = m_codeStor.getCurrentOp();
        execute(op);
        m_codeStor>>1;
    }
    return Log::success;
}

void bf::Brainfuck::execute(bf::OpCode const code)
{
    switch(code){

        case bf::OpCode::Right:
            m_runMem>>1;
            break;

        case bf::OpCode::Left:
            m_runMem<<1;
            break;

        case bf::OpCode::Read:
            m_runMem.read();
            break;

        case bf::OpCode::Write:
            m_runMem.write();
            break;

        case bf::OpCode::Increment:
            m_runMem++;
            break;

        case bf::OpCode::Decrement:
            m_runMem--;
            break;

        case bf::OpCode::LoopBegin:
            if(m_runMem.getValue()){
                break;
            }
            else{
                m_codeStor.jumpToEndLoop();
                break;
            }

        case bf::OpCode::LoopEnd:
            if(m_runMem.getValue()){
                m_codeStor.jumpToHeadLoop();
                break;
            }
            else{break;}

        default:
            break;
    }
}

size_t bf::Brainfuck::checkValid(const char* const program)
{
    size_t count, headLoop, endLoop;
    count = headLoop = endLoop = 0;
    for(size_t i=0 ; program[i]!='\0' ; ++i){
        if( program[i]== '<' || program[i]== '>' ||
            program[i]== '.' || program[i]== ',' ||
            program[i]== '+' || program[i]== '-'){
            ++count;
        }
        if(program[i]== '['){
            ++headLoop;
        }
        if(program[i]== ']'){
            ++endLoop;
        }
    }
    return (headLoop==endLoop)? count+1 : 0;
}

bf::Log bf::Brainfuck::translate(const char* const program)
{
    size_t i = 0;
    while(program[i]!= '\0'){
        switch(program[i]){

            case '>':
                m_codeStor.setOp(OpCode::Right);
                break;

            case '<':
                m_codeStor.setOp(OpCode::Left);
                break;

            case '.':
                m_codeStor.setOp(OpCode::Read);
                break;

            case ',':
                m_codeStor.setOp(OpCode::Write);
                break;

            case '+':
                m_codeStor.setOp(OpCode::Increment);
                break;

            case '-':
                m_codeStor.setOp(OpCode::Decrement);
                break;

            case '[':
                m_codeStor.setOp(OpCode::LoopBegin);
                break;

            case ']':
                m_codeStor.setOp(OpCode::LoopEnd);
                break;

            default:
                break;
        }                  
    }
    m_codeStor.setOp(OpCode::EndOp);
    return Log::success;
}

// void Brainfuck::setOperations(char* const program)
// {
//     m_ptrPro = program;
//     memset(m_OpStorage ,0 ,m_size);
//     while(*m_ptrPro!='\0')
//     {
//         std::cout<<*m_ptrPro;;
//         char c = *m_ptrPro;
//         translateEndExecute(c);
//         ++m_ptrPro;
//     }
    
// }


// void Brainfuck::NoOp() const
// {
//     return;
// }

// void Brainfuck::Right()
// {
//     ++m_OpStorage;
// }

// void Brainfuck::Left()
// {
//     --m_OpStorage;
// }

// void Brainfuck::Increment()
// {
//     ++(*m_OpStorage);
// }

// void Brainfuck::Decrement()
// {
//     --(*m_OpStorage);
// }

// void Brainfuck::Write() 
// {
//     (*m_OpStorage)= ++(*m_ptrPro);
// }

// void Brainfuck::Read() const
// {
//     std::cout<<(*m_OpStorage);
// }

// void Brainfuck::LoopBegin(char c)
// {
//     if(*m_OpStorage){
//         return NoOp();
//     }
//     while(*m_ptrPro != ']')
//     {
//         ++m_ptrPro;
//     }
//     ++m_ptrPro;    
// }

// void Brainfuck::LoopEnd(char c)
// {
//     while(*m_ptrPro !='[')
//     {
//         --m_ptrPro;
//     }
// }
