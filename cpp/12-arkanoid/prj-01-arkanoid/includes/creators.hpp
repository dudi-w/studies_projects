#ifndef CREATORS_HPP
#define CREATORS_HPP

#include <vector>
#include <iostream>
#include <memory>

#include "definitions.hpp"
#include "eventManager.hpp"
#include "collisionsManager.hpp"
#include "player.hpp"
#include "textureManager.hpp"
#include "textObject.hpp"

namespace gm{

std::shared_ptr<gm::Platform> createPaddle(gm::TextureManager& textureManager);

std::shared_ptr<gm::Ball> createBall(gm::TextureManager& textureManager, std::shared_ptr<gm::Platform> paddle);

std::vector <std::shared_ptr<gm::ConstObject>> createBricks(unsigned int row , unsigned int column , gm::TextureManager& textureManager);

std::shared_ptr<sf::Text> createScore(gm::TextureManager& textureManager);

std::shared_ptr<sf::Text> createLife(gm::TextureManager& textureManager);

} // namespace gm

#endif
