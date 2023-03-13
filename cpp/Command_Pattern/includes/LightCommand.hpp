#ifndef LIGHT_COMMAND
#define LIGHT_COMMAND

#include "command.hpp"
#include "light.hpp"

class LightOnCommand : public Command
{
public:
    explicit LightOnCommand(Light& light);
    void execute() override;

private:
    Light& m_light;
};

LightOnCommand::LightOnCommand(Light& light)
: m_light(light)
{}

void LightOnCommand::execute()
{
    m_light.turnOn();
}

class LightOffCommand : public Command
{
public:
    explicit LightOffCommand(Light& light);
    void execute() override;

private:
    Light& m_light;
};

LightOffCommand::LightOffCommand(Light& light)
: m_light(light)
{}

void LightOffCommand::execute()
{
    m_light.turnOff();
}

#endif
