#ifndef COLLISIONS_MANAGER_HPP
#define COLLISIONS_MANAGER_HPP

#include <memory>

#include "definitions.hpp"
#include "platform.hpp"
#include "ball.hpp"
#include "constObject.hpp"
#include "collisions.hpp"
#include "ballBrickCollision.hpp"
#include "ballPaddleCollision.hpp"
#include "player.hpp"


namespace gm{

bool chekBallCollisionsLimit(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball);

gm::CollisionSide chekBoundingCollisions(sf::FloatRect const& boundingA , sf::FloatRect const& boundingB);

std::vector<gm::BallBrickCollision> CheckCollisionsBetweenBallBricks(std::shared_ptr<gm::Ball>& ball, std::vector <std::shared_ptr<gm::ConstObject>>& bricks);

gm::BallPaddleCollision CheckCollisionsBetweenBallPaddle(std::shared_ptr<gm::Ball>& ball, std::shared_ptr<gm::Platform>& paddle);

void collisionsManager(std::shared_ptr<gm::Platform>& paddle, \
                        std::shared_ptr<gm::Ball>& ball,\
                        std::vector <std::shared_ptr<gm::ConstObject>>&  bricks,\
                        gm::Player& myPlayer);

static std::unordered_map<gm::CollisionSide,std::function<void(sf::Vector2f& direction)>> ballCollisinCases = 
{
    {gm::CollisionSide::Bottom, [](sf::Vector2f& direction){direction.y = -std::abs(direction.y);}},
    {gm::CollisionSide::Up, [](sf::Vector2f& direction){direction.y = std::abs(direction.y);}},
    {gm::CollisionSide::Right, [](sf::Vector2f& direction){direction.x = -std::abs(direction.x);}},
    {gm::CollisionSide::Left, [](sf::Vector2f& direction){direction.x = std::abs(direction.x);}}
};


}// namespace gm

#endif