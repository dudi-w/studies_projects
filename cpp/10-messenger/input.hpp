#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
class Input
{
public:
    // input();
    virtual ~Input() = default;

    virtual std::string returnAsString() const = 0;
};

#endif