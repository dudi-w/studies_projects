#ifndef RED_LIGHT_HPP
#define RED_LIGHT_HPP

#include "light.hpp"

class RedLight : public Light
{
public:
    using Light::Light;
    RedLight& operator=(RedLight const&) = default;
    ~RedLight() = default;

    virtual void turnOn() override;
    virtual void turnOff() override;
};

inline void RedLight::turnOn()
{
    m_light.setColor(sf::Color::Red);
    m_light.setRotation(180);
}

inline void RedLight::turnOff()
{
    m_light.setColor(sf::Color(100,0,0));
    m_light.setRotation(0);
}

#endif
