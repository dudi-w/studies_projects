#ifndef MODE_HPP
#define MODE_HPP

#include "definitions.hpp"
#include "eventManager.hpp"
#include "collisionsManager.hpp"
#include "player.hpp"
#include "resourcesManager.hpp"
#include "textObject.hpp"
#include "bestPlayers.hpp"

using rs = gm::ResourcesManager::Resource;

namespace gm{

bool checkValid(char const c);

void getPlayerNameMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager);

void topTenMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager);

void homescreenMODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager);

bool levelA_MODE(sf::RenderWindow& window, gm::Player& player, gm::ResourcesManager& resourcesManager);

}

#endif