#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <stack>
#include <functional>

#include "../node/expressionNode.hpp"
#include "../ETenum.hpp"

namespace tk{//token

using Constructor_fun = std::function<P_ex(P_ex right , P_ex left)>;

class Token
{
public:
    Token() = default;
    virtual ~Token() = default;

    virtual size_t getIndex() const = 0;
    virtual void creatNode(std::stack<P_ex>& stack) const = 0;
    virtual Group preyutiryGroup() const = 0;
};

}//namespace tk

#endif
