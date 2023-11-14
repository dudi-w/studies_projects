#ifndef EVENT_MENEGAR_HPP
#define EVENT_MENEGAR_HPP

#include <unordered_map>
#include "includes/greenLight.hpp"
#include "includes/redLight.hpp"
#include "includes/TV.hpp"
#include "includes/LightCommand.hpp"
#include "includes/TVCommand.hpp"
#include "includes/windowCloseCommand.hpp"
#include "includes/remote.hpp"
#include "includes/ShabatClock.hpp"


class EventMenegar
{
public:
    explicit EventMenegar(RemoteControl& remote,sf::RenderWindow& window ,GreenLight& greenLight, RedLight& redLight,[[maybe_unused]] TV& tv);
    EventMenegar(EventMenegar const& other) = delete;
    EventMenegar operator=(EventMenegar const& other) = delete;
    ~EventMenegar();

    checkEvent(sf::Event const& event);

private:
    RemoteControl& m_remote;
    sf::RenderWindow& m_window;
    GreenLight& m_greenLight;
    RedLight& m_redLight;
    TV& m_tv;
    std::unordered_map<sf::Keyboard, std::vector<std::shared_ptr<Command>>> m_map;
};

EventMenegar::EventMenegar(RemoteControl& remote,sf::RenderWindow& window ,GreenLight& greenLight, RedLight& redLight,[[maybe_unused]] TV& tv)
: m_remote(remote)
, m_window(window)
, m_greenLight(greenLight)
, m_redLight(redLight)
, m_tv(tv)
, m_map({{sf::Keyboard::Escape , {std::make_shared<WindowCloseCommand>(m_window)}},
        {sf::Event::Closed , {std::make_shared<WindowCloseCommand>(m_window)}},
        {sf::Keyboard::Add, {std::make_shared<LightOnCommand>(m_greenLight), std::make_shared<LightOnCommand>(m_redLight)}},
        {sf::Keyboard::Subtract, {std::make_shared<LightOffCommand>(greenLight), std::make_shared<LightOffCommand>(redLight)}},
        {sf::Keyboard::Up , {std::make_shared<TVplayCommand>(tv), std::make_shared<LightOffCommand>(greenLight)}},
        {sf::Keyboard::Down, {std::make_shared<TVstopPlayCommand>(tv)}}
        })
{}
    
EventMenegar::checkEvent(sf::Event const& event)
{
    m_remote.setCommand(m_map[event]);
}

#endif
