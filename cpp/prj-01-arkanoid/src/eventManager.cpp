#include "../includes/eventManager.hpp"

void gm::keystrokeManager(std::shared_ptr<gm::Platform>& paddle, std::shared_ptr<gm::Ball>& ball)
{
	sf::Vector2f direction(0,0);
    sf::FloatRect GlobalBounds = paddle->getGlobalBounds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && GlobalBounds.left > 0){
		direction = sf::Vector2f(-PLATFORM_SPEED, 0);
	}
    
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && GlobalBounds.left + GlobalBounds.width < SCREEN_WIDTH){
		direction = sf::Vector2f(PLATFORM_SPEED, 0);
	}
	
    paddle->move(direction);

    if(!ball->isMoved()){
        ball->move(direction);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !ball->isMoved()){
		direction = sf::Vector2f(BALL_X_SPEED ,BALL_Y_SPEED);
        ball->startMove();
        ball->move(direction);
        return;
	}
}
