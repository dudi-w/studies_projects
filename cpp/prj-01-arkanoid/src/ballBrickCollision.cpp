#include "../includes/ballBrickCollision.hpp"
#include "../includes/collisionsManager.hpp"
#include "../includes/constObject.hpp"
#include <iostream>

gm::BallBrickCollision::BallBrickCollision(std::shared_ptr<gm::Ball> ball ,std::shared_ptr<gm::ConstObject> brick ,gm::Player& player, gm::CollisionSide side)
: m_ball(ball)
, m_brick(brick)
, m_player(player)
, m_side(side)
{}

void gm::BallBrickCollision::doCollision() const
{
    sf::Vector2f direction = m_ball->getDirection();

    if(m_side == gm::CollisionSide::noCollisions){
        return;
    }

    gm::ballCollisinCases[m_side](direction);
    m_ball->setDirection(direction);
    if(auto brick = std::dynamic_pointer_cast<gm::ConstObject>(m_brick)){
        m_brick->subLife();
        if(m_brick->isKill()){
            m_player.addScore(m_brick->killScore());
        }
    }
}