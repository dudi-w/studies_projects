#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <queue>
#include <memory>
#include <SFML/Graphics.hpp>
#include "constObject.hpp"
#include "brick.hpp"
#include "indestructBrick.hpp"

namespace gm{

class ResourcesManager
{
public:
    ResourcesManager();
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

    std::unordered_map<gm::Type ,std::function<std::shared_ptr<gm::ConstObject>(uint i, uint j, uint level, sf::Texture const& texture)>> m_factoryMap;

public:
    sf::Font const& getFont(gm::ResourcesManager::Resource) const;
    sf::Texture const& getTexture(gm::ResourcesManager::Resource) const;
    std::pair<std::string, uint> deLevelFile();
    bool isEndGame() const;
    void restartQeueu();

private:
    void insertFont(std::string const& path, gm::ResourcesManager::Resource key);
    void insertTexture(std::string const& path, gm::ResourcesManager::Resource key);
    void inLevelFile(std::string const& path , uint level);

private:
    std::unordered_map<gm::ResourcesManager::Resource, sf::Texture> m_textureMap;
    std::unordered_map<gm::ResourcesManager::Resource, sf::Font> m_fontMap;
    std::queue<std::pair<std::string, uint>> m_levelFileName;
};

}
#endif
