#ifndef SHABAT_CLOCK_HPP
#define SHABAT_CLOCK_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "TV.hpp"
#include "TVCommand.hpp"
#include "remote.hpp"

class ShabatClock
{
public:
    ShabatClock() = default;
    ShabatClock(ShabatClock const &other) = default;
    ShabatClock &operator=(ShabatClock const &other) = default;
    ~ShabatClock() = default;

    void checkTime(TV& tv ,RemoteControl& renote);

private:
    sf::Clock m_clock;
};

inline void ShabatClock::checkTime(TV& tv ,RemoteControl& renote)
{
    if(m_clock.getElapsedTime().asSeconds() > 5){
        renote.setCommand(std::make_shared<TVplayCommand>(tv));
        m_clock.restart();
    }
}

#endif
