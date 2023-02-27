#include "../includes/creators.hpp"

std::shared_ptr<gm::Platform> gm::createPaddle(gm::ResourcesManager& resourcesManager)
{
    return std::make_shared<gm::Platform>(sf::Vector2f((SCREEN_WIDTH-resourcesManager.m_paddle.getSize().x)/2, SCREEN_HEIGHT-resourcesManager.m_paddle.getSize().y),resourcesManager.m_paddle);
}

std::shared_ptr<gm::Ball> gm::createBall(gm::ResourcesManager& resourcesManager, std::shared_ptr<gm::Platform> paddle)
{
    return std::make_shared<gm::Ball>(sf::Vector2f((SCREEN_WIDTH-resourcesManager.m_ball.getSize().x)/2, (SCREEN_HEIGHT-resourcesManager.m_ball.getSize().y)-(paddle->setShip().getTextureRect().height)) ,resourcesManager.m_ball);
}

std::unordered_set<std::shared_ptr<gm::ConstObject>> gm::createBricks(unsigned int row , unsigned int column , gm::ResourcesManager& resourcesManager)
{
    std::vector <sf::Color> colors = { sf::Color::Green, sf::Color::Blue, sf::Color::Cyan };

    std::unordered_set<std::shared_ptr<gm::ConstObject>> bricks;
    
    int space = 3;
    int offsetY = 100;
    int offsetX = (SCREEN_WIDTH - ((resourcesManager.m_brick.getSize().x+space) * column))/2;

    for(unsigned int i = 0 ; i< row ; ++i){
        for(unsigned int j = 0 ; j< column ; ++j){
            auto brick = std::make_shared<gm::ConstObject>(sf::Vector2f (offsetX + (resourcesManager.m_brick.getSize().x+space)*j ,offsetY + (resourcesManager.m_brick.getSize().y+space)*i) ,resourcesManager.m_brick, gm::Score::brickType1);
            brick->setShip().setColor(colors[i]);
            bricks.insert(brick);
        }
    }
    return bricks;
}

std::unique_ptr<sf::Text> gm::createScore(gm::ResourcesManager& resourcesManager)
{  
    auto score = std::make_unique<sf::Text>();
    sf::Color color(sf::Color::Blue);
    score->setFillColor(color);
    score->setCharacterSize(20);
    score->setFont(resourcesManager.m_font);
    score->setPosition(sf::Vector2f(10,30));
    score->setString("Your score is : ");

    return score;
}

std::unique_ptr<sf::Text> gm::createLife(gm::ResourcesManager& resourcesManager)
{  
    auto life = std::make_unique<sf::Text>();
    sf::Color color(sf::Color::Red);
    life->setFillColor(color);
    life->setCharacterSize(20);
    life->setFont(resourcesManager.m_font);
    life->setPosition(sf::Vector2f(1050,30));
    life->setString("life : ");

    return life;
}