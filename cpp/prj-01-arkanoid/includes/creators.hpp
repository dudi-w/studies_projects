#ifndef CREATORS_HPP
#define CREATORS_HPP

#include <unordered_set>
#include <memory>

#include "definitions.hpp"
#include "eventManager.hpp"
#include "collisionsManager.hpp"
#include "player.hpp"
#include "resourcesManager.hpp"
#include "textObject.hpp"

namespace gm{

std::shared_ptr<gm::Platform> createPaddle(gm::ResourcesManager& resourcesManager);

std::shared_ptr<gm::Ball> createBall(gm::ResourcesManager& resourcesManager, std::shared_ptr<gm::Platform> paddle);

std::unordered_set<std::shared_ptr<gm::ConstObject>> createBricks(unsigned int row , unsigned int column , gm::ResourcesManager& resourcesManager);

std::unique_ptr<sf::Text> createScore(gm::ResourcesManager& resourcesManager);

std::unique_ptr<sf::Text> createLife(gm::ResourcesManager& resourcesManager);

} // namespace gm

#endif
