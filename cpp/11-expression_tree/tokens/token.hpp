#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <stack>
#include <memory>
#include <functional>
#include "../node/expressionNode.hpp"
#include "../ETenum.hpp"

namespace tk
{

using P_Ex =  std::unique_ptr<et::ExpressionNode>;
using constructor_fun = std::function<P_Ex(P_Ex right , P_Ex left)>;

class Token
{
public:
    Token() = default;
    virtual ~Token() = default;

    virtual size_t getIndex() const = 0;
    virtual void creatNode(std::stack<P_Ex> stack) const = 0;
    virtual Group preyutiryGroup() const = 0;
};

}

#endif