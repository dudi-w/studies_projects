#ifndef WINDOW_CLOSE_COMMAND
#define WINDOW_CLOSE_COMMAND

#include "command.hpp"
#include <SFML/Graphics.hpp>

class WindowCloseCommand : public Command
{
public:
    explicit WindowCloseCommand(sf::RenderWindow& window);
    void execute() override;

private:
    sf::RenderWindow& m_window;
};

WindowCloseCommand::WindowCloseCommand(sf::RenderWindow& window)
: m_window(window)
{}

void WindowCloseCommand::execute()
{
    m_window.close();
}

// class windowOffCommand : public Command
// {
// public:
//     windowOffCommand(sf::RenderWindow& window);
//     void execute() override;

// private:
//     sf::RenderWindow& m_window;
// };

// windowOffCommand::windowOffCommand(sf::RenderWindow& window)
// : m_window(window)
// {}

// void windowOffCommand::execute()
// {
//     m_window.turnOff();
// }

#endif
