#ifndef TV_HPP
#define TV_HPP

#include <SFML/Graphics.hpp>

class TV
{
public:
    explicit TV(float x, float y);
    TV(TV const& other) = delete;
    TV& operator=(TV const& other) = delete;
    virtual ~TV() = default;

    sf::FloatRect getBounds() const;
    sf::Drawable const& getDrow() const;

    void play();
    void stopPlay();

private:
    sf::Sprite m_TV;
    sf::Texture m_texture;
};

inline TV::TV(float x, float y)
{
    m_TV.setPosition(x,y);
    m_texture.loadFromFile("./resurces/TV.png");
    m_TV.setTexture(m_texture);
    stopPlay();
}

inline sf::FloatRect TV::getBounds() const
{
    return m_TV.getGlobalBounds();
}

inline sf::Drawable const& TV::getDrow() const
{
    return m_TV;
}

inline void TV::play()
{
    m_TV.setColor(sf::Color::Magenta);
}

inline void TV::stopPlay()
{
    m_TV.setColor(sf::Color::White);
}

#endif
