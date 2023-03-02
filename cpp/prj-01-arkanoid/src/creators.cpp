#include "../includes/creators.hpp"

using rs = gm::ResourcesManager::Resource;

std::shared_ptr<gm::Platform> gm::createPaddle(gm::ResourcesManager& resourcesManager)
{
    auto& paddelTexture = resourcesManager.getTexture(rs::paddle);
    unsigned int x = (SCREEN_WIDTH-paddelTexture.getSize().x)/2;
    unsigned int y = SCREEN_HEIGHT-paddelTexture.getSize().y;
    return std::make_shared<gm::Platform>(sf::Vector2f(x,y),paddelTexture);
}

std::shared_ptr<gm::Ball> gm::createBall(gm::ResourcesManager& resourcesManager, std::shared_ptr<gm::Platform> paddle)
{   
    auto& ballTexture = resourcesManager.getTexture(rs::ball);
    unsigned int x = (SCREEN_WIDTH-ballTexture.getSize().x)/2;
    unsigned int y = (SCREEN_HEIGHT-ballTexture.getSize().y)-(paddle->setShip().getTextureRect().height);
    return std::make_shared<gm::Ball>(sf::Vector2f(x,y),ballTexture);
}

std::unordered_set<std::shared_ptr<gm::ConstObject>> gm::createBricks(unsigned int row , unsigned int column , gm::ResourcesManager& resourcesManager)
{
    std::vector <sf::Color> colors = { sf::Color::Green, sf::Color::Blue, sf::Color::Cyan };
    std::unordered_set<std::shared_ptr<gm::ConstObject>> bricks;
    
    unsigned int space = 3;
    unsigned int offsetY = 100;
    auto& brickTexture = resourcesManager.getTexture(rs::brick);
    unsigned int offsetX = (SCREEN_WIDTH - ((brickTexture.getSize().x + space) * column))/2;

    for(unsigned int i = 0 ; i< row ; ++i){
        for(unsigned int j = 0 ; j< column ; ++j){
            auto brick = std::make_shared<gm::ConstObject>(sf::Vector2f (offsetX + (brickTexture.getSize().x+space)*j ,offsetY + (brickTexture.getSize().y+space)*i) ,brickTexture , gm::Score::brickType1);
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
    score->setCharacterSize(30);
    score->setFont(resourcesManager.getFont(rs::font1));
    score->setPosition(sf::Vector2f(10,30));
    score->setString("Your score is : ");

    return score;
}

std::unique_ptr<sf::Text> gm::createLife(gm::ResourcesManager& resourcesManager)
{  
    auto life = std::make_unique<sf::Text>();
    sf::Color color(sf::Color::Red);
    life->setFillColor(color);
    life->setCharacterSize(30);
    life->setFont(resourcesManager.getFont(rs::font1));
    life->setPosition(sf::Vector2f(1000,30));
    life->setString("life : ");

    return life;
}