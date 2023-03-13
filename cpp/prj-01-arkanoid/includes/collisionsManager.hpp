#ifndef COLLISIONS_MANAGER_HPP
#define COLLISIONS_MANAGER_HPP

#include <memory>
#include <unordered_set>

#include "definitions.hpp"
#include "platform.hpp"
#include "ball.hpp"
#include "constObject.hpp"
#include "collisions.hpp"
#include "ballBrickCollision.hpp"
#include "ballPaddleCollision.hpp"
#include "player.hpp"


namespace gm{

class CollisionsManager
{
public:
    explicit CollisionsManager(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball, std::unordered_set<std::shared_ptr<gm::ConstObject>>& bricks, gm::Player& myPlayer);
    CollisionsManager(CollisionsManager const& other) = delete;
    CollisionsManager& operator=(CollisionsManager const& other) = delete;
    ~CollisionsManager() = default;

    void CheckCollision();

private:
    bool chekBallCollisionsLimit();
    gm::CollisionSide chekBoundingCollisions(sf::FloatRect const& boundingA , sf::FloatRect const& boundingB);
    std::vector<gm::BallBrickCollision> CheckCollisionsBetweenBallBricks();
    gm::BallPaddleCollision CheckCollisionsBetweenBallPaddle();
    void deleteKilledObjects();

private:
    std::shared_ptr<gm::Platform>& m_paddle;
    std::shared_ptr<gm::Ball>& m_ball;
    std::unordered_set<std::shared_ptr<gm::ConstObject>>& m_bricks;
    gm::Player& m_player;
    // static std::unordered_map<gm::CollisionSide,std::function<void(sf::Vector2f& direction)>> m_ballCollisinCases;
};

 static std::unordered_map<gm::CollisionSide,std::function<void(sf::Vector2f& direction)>> ballCollisinCases = 
{
    {gm::CollisionSide::Bottom, [](sf::Vector2f& direction){direction.y = -std::abs(direction.y);}},
    {gm::CollisionSide::Up, [](sf::Vector2f& direction){direction.y = std::abs(direction.y);}},
    {gm::CollisionSide::Right, [](sf::Vector2f& direction){direction.x = -std::abs(direction.x);}},
    {gm::CollisionSide::Left, [](sf::Vector2f& direction){direction.x = std::abs(direction.x);}}
};

}// namespace gm

#endif
