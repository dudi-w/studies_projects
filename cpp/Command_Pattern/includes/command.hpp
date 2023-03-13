#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command
{
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

#endif
