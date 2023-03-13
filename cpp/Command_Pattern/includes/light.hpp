#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <SFML/Graphics.hpp>

class Light
{
public:
    explicit Light(float x, float y);
    Light(Light const& other) = delete;
    Light& operator=(Light const& other) = delete;
    virtual ~Light() = default;

    sf::FloatRect getBounds() const;
    sf::Drawable const& getDrow() const;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
        
protected:
    sf::Sprite m_light;
    sf::Texture m_texture;
};

inline Light::Light(float x, float y)
{
    m_texture.loadFromFile("./light.png");
    m_light.setOrigin(m_texture.getSize().x/2,m_texture.getSize().y/2);
    m_light.setPosition(x,y);
    m_light.setTexture(m_texture);
}

inline sf::FloatRect Light::getBounds() const
{
    return m_light.getGlobalBounds();
}

inline sf::Drawable const& Light::getDrow() const
{
    return m_light;
}

#endif
