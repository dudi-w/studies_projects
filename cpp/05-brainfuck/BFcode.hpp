#ifndef BF_CODE_HPP
#define BF_CODE_HPP

#include "dataStructure.hpp"

namespace bf
{

class Code
{
    public:
        explicit Code();
        explicit Code(size_t size);

        void operator>>(size_t i);
        void operator<<(size_t i);
        size_t getSize() const;
        size_t getIndex() const;
        bf::OpCode getCurrentOp() const;
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
