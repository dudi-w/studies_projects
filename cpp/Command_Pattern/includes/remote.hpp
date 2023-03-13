#ifndef REMOTE_CONTROL
#define REMOTE_CONTROL

#include <queue>
#include <memory>
#include "command.hpp"

class RemoteControl
{
public:
    RemoteControl() = default;
    RemoteControl(RemoteControl const &other) = default;
    RemoteControl &operator=(RemoteControl const &other) = default;
    ~RemoteControl() = default;

    void setCommand(std::shared_ptr<Command> command);
    void buttonWasPressed();

private:
    std::queue<std::shared_ptr<Command>> m_slot;
};

inline void RemoteControl::setCommand(std::shared_ptr<Command> command)
{
    m_slot.push(command);
}

inline void RemoteControl::buttonWasPressed()
{
    while (!m_slot.empty())
    {
        m_slot.front()->execute();
        m_slot.pop();
    }
}

#endif
