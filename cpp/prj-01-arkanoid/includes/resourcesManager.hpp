#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace gm{

class ResourcesManager
{
public:

    ResourcesManager() = default;
    ResourcesManager(ResourcesManager const& other) = default;
    ResourcesManager& operator=(ResourcesManager const& other) = default;
    ~ResourcesManager() = default;

public:
    enum class Resource : int8_t
    {
        background,
        homescreen,
        top10,
        ball,
        paddle,
        brick,
        exit,
        play,
        sandClock,
        font1,
        font2,
        font3,
        font4
    };

    void insertFunt(std::string const& path, gm::ResourcesManager::Resource key);
    void insertTexture(std::string const& path, gm::ResourcesManager::Resource key);
    sf::Font const& getFont(gm::ResourcesManager::Resource) const;
    sf::Texture const& getTexture(gm::ResourcesManager::Resource) const;

private:
    std::unordered_map<gm::ResourcesManager::Resource, sf::Texture> m_textureMap;
    std::unordered_map<gm::ResourcesManager::Resource, sf::Font> m_fontMap;
};

}
#endif