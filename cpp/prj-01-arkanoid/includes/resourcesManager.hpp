#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace gm{

class ResourcesManager
{
public:

    explicit ResourcesManager(std::string background, std::string ball, std::string paddle, std::string brick , std::string scoreFont);
    ResourcesManager(ResourcesManager const& other) = default;
    ResourcesManager& operator=(ResourcesManager const& other) = default;
    ~ResourcesManager() = default;

public:
    sf::Texture m_background;
    sf::Texture m_ball;
    sf::Texture m_paddle;
    sf::Texture m_brick;
    sf::Font m_font;
};

}
#endif