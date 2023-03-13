#include <algorithm>
#include <utility>
#include <iostream>
#include "../includes/collisionsManager.hpp"
#include "../includes/brick.hpp"

gm::CollisionsManager::CollisionsManager(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball, std::unordered_set<std::shared_ptr<gm::ConstObject>>& bricks, gm::Player& player)
: m_paddle(paddle)
, m_ball(ball)
, m_bricks(bricks)
, m_player(player)
// , m_ballCollisinCases
// ({
//     {gm::CollisionSide::Bottom, [](sf::Vector2f& direction){direction.y = -std::abs(direction.y);}},
//     {gm::CollisionSide::Up, [](sf::Vector2f& direction){direction.y = std::abs(direction.y);}},
//     {gm::CollisionSide::Right, [](sf::Vector2f& direction){direction.x = -std::abs(direction.x);}},
//     {gm::CollisionSide::Left, [](sf::Vector2f& direction){direction.x = std::abs(direction.x);}}
// })
{}

void gm::CollisionsManager::CheckCollision()
{
    if(!chekBallCollisionsLimit()){
        m_player.subLife();
    }

    uint16_t score;
    auto collisions = CheckCollisionsBetweenBallBricks();
    for(auto collision : collisions){
        if((score = collision.doCollision())){
            m_player.addScore(score);
        }
    }
    
    auto paddleCollision = CheckCollisionsBetweenBallPaddle();
    paddleCollision.doCollision();
    
    deleteKilledObjects();
}

bool gm::CollisionsManager::chekBallCollisionsLimit()
{    
    sf::FloatRect bounding = m_ball->setShip().getGlobalBounds();
    sf::Vector2f ballDirection = m_ball->getDirection();

    if(bounding.top < 0 ){
        ballDirection.y = std::abs(ballDirection.y);
    }
    else if(bounding.left < 0){
        ballDirection.x = std::abs(ballDirection.x);
    }
    else if(bounding.left+bounding.width > SCREEN_WIDTH){
        ballDirection.x = -std::abs(ballDirection.x);
    }
    else if(bounding.top+bounding.height > SCREEN_HEIGHT){
        m_ball->reset();
        m_paddle->reset();
        return false;
    }

    m_ball->setDirection(ballDirection);
    return true;
}

gm::CollisionSide gm::CollisionsManager::chekBoundingCollisions(sf::FloatRect const& boundingA , sf::FloatRect const& boundingB)
{
    if(boundingA.intersects(boundingB)){

        std::vector< std::pair < int, gm::CollisionSide>> CollisionVector = {
            {std::abs(boundingA.top - (boundingB.top + boundingB.height)), gm::CollisionSide::Up},
            {std::abs((boundingA.top + boundingA.height) - boundingB.top), gm::CollisionSide::Bottom},
            {std::abs((boundingA.left + boundingA.width) - boundingB.left), gm::CollisionSide::Right},
            {std::abs(boundingA.left - (boundingB.left + boundingB.width)), gm::CollisionSide::Left}
        };

        auto result = std::min_element(CollisionVector.cbegin(), CollisionVector.cend());
        
        return result->second;
    }
    return gm::CollisionSide::noCollisions;
}

std::vector<gm::BallBrickCollision> gm::CollisionsManager::CheckCollisionsBetweenBallBricks()
{
    std::vector<gm::BallBrickCollision> collisions;
    for(auto brick : m_bricks){
        gm::CollisionSide collisionSide = chekBoundingCollisions(m_ball->setShip().getGlobalBounds() ,brick->setShip().getGlobalBounds());
        collisions.push_back(gm::BallBrickCollision(m_ball ,brick ,collisionSide));
    }
    return collisions;
}

gm::BallPaddleCollision gm::CollisionsManager::CheckCollisionsBetweenBallPaddle()
{
    gm::CollisionSide collisionSide = chekBoundingCollisions(m_ball->setShip().getGlobalBounds() ,m_paddle->setShip().getGlobalBounds());
    return gm::BallPaddleCollision(m_ball ,m_paddle ,collisionSide);
}

void gm::CollisionsManager::deleteKilledObjects()
{
    auto it = m_bricks.cbegin();

    while(it != m_bricks.cend()){
        if((*it)->isKill()){
            it = m_bricks.erase(it);
        }else{
            ++it;
        }
    }
}