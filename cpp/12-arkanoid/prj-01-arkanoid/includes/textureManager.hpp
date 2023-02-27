#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace gm{

struct TextureManager
{
public:

    inline explicit TextureManager(std::string background, std::string ball, std::string paddle, std::string brick , std::string scoreFont)
    {
        m_background.loadFromFile(background);
        m_ball.loadFromFile(ball);
        m_paddle.loadFromFile(paddle);
        m_brick.loadFromFile(brick);
        m_font.loadFromFile(scoreFont);
    }

public:
    sf::Texture m_background;
    sf::Texture m_ball;
    sf::Texture m_paddle;
    sf::Texture m_brick;
    sf::Font m_font;
};

}
#endif