#include <algorithm>
#include <utility>
#include <iostream>
#include "../includes/collisionsManager.hpp"

gm::CollisionsManager::CollisionsManager(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball, std::unordered_set<std::shared_ptr<gm::ConstObject>>& bricks, gm::Player& player)
: m_paddle(paddle)
, m_ball(ball)
, m_bricks(bricks)
, m_player(player)
{}

void gm::CollisionsManager::CheckCollisions()
{
    std::vector<std::unique_ptr<gm::Collision>> Collisions;
    Collisions.push_back(std::move(chekBallCollisionsLimit()));
    Collisions[0]->doCollision();
    // if(!chekBallCollisionsLimit()){
    //     m_player.subLife();
    // }

    auto collisions = CheckCollisionsBetweenBallBricks();
    for(auto collision : collisions){
        collision.doCollision();
    }
    
    auto paddleCollision = CheckCollisionsBetweenBallPaddle();
    paddleCollision->doCollision();
    
    deleteKilledObjects();
}

std::unique_ptr<gm::BallLimitCollision> gm::CollisionsManager::chekBallCollisionsLimit()
{    
    sf::FloatRect bounding = m_ball->getGlobalBounds();
    gm::CollisionSide result;
    if(bounding.top < 0 || bounding.left < 0 || bounding.left+bounding.width > SCREEN_WIDTH || bounding.top+bounding.height > SCREEN_HEIGHT){
        std::vector< std::pair < int, gm::CollisionSide>> CollisionVector = {
            {std::abs(bounding.top), gm::CollisionSide::Up},
            {std::abs(bounding.top+bounding.height - SCREEN_HEIGHT), gm::CollisionSide::Bottom},
            {std::abs(bounding.left+bounding.width - SCREEN_WIDTH), gm::CollisionSide::Right},
            {std::abs(bounding.left), gm::CollisionSide::Left}
        };
        result = std::min_element(CollisionVector.cbegin(), CollisionVector.cend())->second;
    }else{
        result = gm::CollisionSide::noCollisions;
    }

    return std::make_unique<gm::BallLimitCollision>(m_ball, m_paddle, m_player , result);
    
    
    // sf::Vector2f ballDirection = m_ball->getDirection();

    // if(bounding.top < 0){
    //     ballDirection.y = std::abs(ballDirection.y);
    // }
    // else if(bounding.left < 0){
    //     ballDirection.x = std::abs(ballDirection.x);
    // }
    // else if(bounding.left+bounding.width > SCREEN_WIDTH){
    //     ballDirection.x = -std::abs(ballDirection.x);
    // }
    // else if(bounding.top+bounding.height > SCREEN_HEIGHT){
    //     m_ball->reset();
    //     m_paddle->reset();
    //     return false;
    // }

    // m_ball->setDirection(ballDirection);
    // return true;
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
        gm::CollisionSide collisionSide = chekBoundingCollisions(m_ball->getGlobalBounds() ,brick->getGlobalBounds());
        collisions.push_back(gm::BallBrickCollision(m_ball ,brick ,m_player ,collisionSide));
    }
    return collisions;
}

std::unique_ptr<gm::BallPaddleCollision> gm::CollisionsManager::CheckCollisionsBetweenBallPaddle()
{
    gm::CollisionSide collisionSide = chekBoundingCollisions(m_ball->getGlobalBounds() ,m_paddle->getGlobalBounds());
    return std::make_unique<gm::BallPaddleCollision>(m_ball ,m_paddle ,collisionSide);
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