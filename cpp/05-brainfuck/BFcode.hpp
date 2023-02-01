#ifndef BF_CODE_HPP
#define BF_CODE_HPP

#include "dataStructure.hpp"
#include "BFenum.hpp"

namespace bf
{

class Code
{
public:
    explicit Code(size_t size);
    Code(Code const& other) = default;
    Code& operator=(Code const& other) = default;
    ~Code() = default;


    void operator>>(size_t i);
    void operator<<(size_t i);

    bf::OpCode getCurrentOp() const;
    size_t getSize() const;
    size_t getIndex() const;
    void setOp(bf::OpCode op);
    void jumpToEndLoop();
    void jumpToHeadLoop();

    void display();

private:
    size_t m_index;
    ds::ArrByte m_codeMem;
};

}
#endif
