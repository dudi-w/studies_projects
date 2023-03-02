#include "../includes/resourcesManager.hpp"

void gm::ResourcesManager::insertFunt(std::string const& path, gm::ResourcesManager::Resource key)
{
    m_fontMap[key].loadFromFile(path);
}

void gm::ResourcesManager::insertTexture(std::string const& path, gm::ResourcesManager::Resource key)
{
    m_textureMap[key].loadFromFile(path);
}

sf::Font& gm::ResourcesManager::getFont(ResourcesManager::Resource key)
{
    return m_fontMap.find(key)->second;
}

sf::Texture& gm::ResourcesManager::getTexture(gm::ResourcesManager::Resource key)
{
    return m_textureMap.find(key)->second;
}

