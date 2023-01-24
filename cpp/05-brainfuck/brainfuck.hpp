#include <iostream>

class Brainfuck
{

public:
    explicit Brainfuck(size_t size);
    ~Brainfuck();

    void setOperations(char* const  program);
    
private:
    // enum class OpCode{  NoOp,
                        // Right,
                        // Left,
                        // Increment,
                        // Decrement,
                        // Write,
                        // Read,
                        // LoopBegin,
                        // LoopEnd
    // };

    void NoOp() const;
    void Right();
    void Left();
    void Increment();
    void Decrement();
    void Write() ;
    void Read() const;
    void LoopBegin(char c);
    void LoopEnd(char c);
    void translateEndExecute(char const c);

private:
    size_t m_size;
    char* m_OpStorage;
    char* m_ptrPro;
};