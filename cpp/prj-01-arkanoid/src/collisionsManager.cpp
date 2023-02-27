#include <algorithm>
#include <utility>
#include "../includes/collisionsManager.hpp"

bool gm::chekBallCollisionsLimit(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball){
    
    sf::FloatRect bounding = ball->setShip().getGlobalBounds();
    sf::Vector2f ballDirection = ball->getDirection();

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
        ball->reset();
        paddle->reset();
        return false;
    }

    ball->setDirection(ballDirection);
    return true;
}

gm::CollisionSide gm::chekBoundingCollisions(sf::FloatRect const& boundingA , sf::FloatRect const& boundingB)
{
    if(boundingA.intersects(boundingB)){

        std::vector< std::pair < int, gm::CollisionSide>> CollisionVector = {
            {std::abs(boundingA.top - (boundingB.top + boundingB.height)), gm::CollisionSide::Up},
            {std::abs((boundingA.top + boundingA.height) - boundingB.top), gm::CollisionSide::Bottom},
            {std::abs((boundingA.left + boundingA.width) - boundingB.left), gm::CollisionSide::Right},
            {std::abs(boundingA.left - (boundingB.left + boundingB.width)), gm::CollisionSide::Left}
        };

        auto result = std::min_element(CollisionVector.begin(), CollisionVector.end());
        
        return result->second;
    }
    return gm::CollisionSide::noCollisions;
}

std::vector<gm::BallBrickCollision> gm::CheckCollisionsBetweenBallBricks(std::shared_ptr<gm::Ball>& ball, std::unordered_set<std::shared_ptr<gm::ConstObject>>& bricks){
    std::vector<gm::BallBrickCollision> collisions;
    for(auto brick : bricks){
        gm::CollisionSide collisionSide = chekBoundingCollisions(ball->setShip().getGlobalBounds() ,brick->setShip().getGlobalBounds());
        collisions.push_back(gm::BallBrickCollision(ball ,brick ,collisionSide));
    }
    return collisions;
}

gm::BallPaddleCollision gm::CheckCollisionsBetweenBallPaddle(std::shared_ptr<gm::Ball>& ball, std::shared_ptr<gm::Platform>& paddle)
{
    gm::CollisionSide collisionSide = chekBoundingCollisions(ball->setShip().getGlobalBounds() ,paddle->setShip().getGlobalBounds());
    return gm::BallPaddleCollision(ball ,paddle ,collisionSide);
}

void gm::deleteKilledObjects(std::unordered_set<std::shared_ptr<gm::ConstObject>>&  bricks)
{
    auto it = bricks.begin();

    while(it != bricks.end()){
        if((*it)->isKill()){
            it = bricks.erase(it);
        }else{
            ++it;
        }
    }
}

void gm::collisionsManager(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball, std::unordered_set<std::shared_ptr<gm::ConstObject>>& bricks, gm::Player& myPlayer)
{
    if(!chekBallCollisionsLimit(paddle, ball)){
        myPlayer.subLife();
    }

    gm::Score score;
    auto collisions = CheckCollisionsBetweenBallBricks(ball ,bricks);
    for(auto collision : collisions){
        if((score = collision.doCollision()) != gm::Score::noScore){
            myPlayer.addScore(gm::scoreMap[score]);
        }
    }
    auto paddleCollision = CheckCollisionsBetweenBallPaddle(ball ,paddle);
    paddleCollision.doCollision();
    
    gm::deleteKilledObjects(bricks);
}