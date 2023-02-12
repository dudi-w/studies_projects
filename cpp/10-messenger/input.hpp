#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
namespace dt
{
class Input
{
public:
    virtual ~Input() = default;

    virtual std::string returnAsString() const = 0;
};

}//namespace dt
#endif