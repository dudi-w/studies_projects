#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace gm{

class ResourcesManager
{
public:

    explicit ResourcesManager(std::string background, std::string homescreen, std::string ball, std::string paddle, std::string brick ,std::string exit  ,std::string play , std::string Font1 ,std::string Font2);
    ResourcesManager(ResourcesManager const& other) = default;
    ResourcesManager& operator=(ResourcesManager const& other) = default;
    ~ResourcesManager() = default;

public:
    sf::Texture m_background;
    sf::Texture m_homescreen;
    sf::Texture m_ball;
    sf::Texture m_paddle;
    sf::Texture m_brick;
    sf::Texture m_exit;
    sf::Texture m_play;
    sf::Font m_font1;
    sf::Font m_font2;
};

}
#endif