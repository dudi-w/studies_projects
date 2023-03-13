#ifndef TV_COMMAND
#define TV_COMMAND

#include "command.hpp"
#include "TV.hpp"

class TVplayCommand : public Command
{
public:
    explicit TVplayCommand(TV& TV);
    void execute() override;

private:
    TV& m_TV;
};

TVplayCommand::TVplayCommand(TV& TV)
: m_TV(TV)
{}

void TVplayCommand::execute()
{
    m_TV.play();
}

class TVstopPlayCommand : public Command
{
public:
    TVstopPlayCommand(TV& TV);
    void execute() override;

private:
    TV& m_TV;
};

TVstopPlayCommand::TVstopPlayCommand(TV& TV)
: m_TV(TV)
{}

void TVstopPlayCommand::execute()
{
    m_TV.stopPlay();
}

#endif
