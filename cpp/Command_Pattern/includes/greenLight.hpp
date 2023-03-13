#ifndef GREEN_LIGHT_HPP
#define GREEN_LIGHT_HPP

#include "light.hpp"

class GreenLight : public Light
{
public:
    using Light::Light;
    GreenLight& operator=(GreenLight const&) = default;
    ~GreenLight() = default;

    virtual void turnOn() override;
    virtual void turnOff() override;
};

inline void GreenLight::turnOn()
{
    m_light.setColor(sf::Color::Green);
}

inline void GreenLight::turnOff()
{
    m_light.setColor(sf::Color::Transparent);
}


#endif
