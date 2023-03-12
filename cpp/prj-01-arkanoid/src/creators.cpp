#include <sstream>
#include <fstream>
#include <filesystem>

#include "../includes/creators.hpp"
// #include "../includes/brick.hpp"
// #include "../includes/indestructBrick.hpp"


using rs = gm::ResourcesManager::Resource;

std::shared_ptr<gm::Platform> gm::createPaddle(gm::ResourcesManager& resourcesManager)
{
    auto const& paddelTexture = resourcesManager.getTexture(rs::paddle);
    uint x = (SCREEN_WIDTH-paddelTexture.getSize().x)/2;
    uint y = SCREEN_HEIGHT-paddelTexture.getSize().y;
    return std::make_shared<gm::Platform>(sf::Vector2f(x,y),paddelTexture);
}

std::shared_ptr<gm::Ball> gm::createBall(gm::ResourcesManager& resourcesManager, std::shared_ptr<gm::Platform> paddle)
{   
    auto const& ballTexture = resourcesManager.getTexture(rs::ball);
    uint x = SCREEN_WIDTH/2;
    uint y = (SCREEN_HEIGHT-ballTexture.getSize().y)-(paddle->setShip().getTextureRect().height/2);
    return std::make_shared<gm::Ball>(sf::Vector2f(x,y),ballTexture);
}

std::unordered_set<std::shared_ptr<gm::ConstObject>> gm::createBricks(gm::ResourcesManager& resourcesManager)
{
    std::unordered_set<std::shared_ptr<gm::ConstObject>> bricks;
    
    auto& brickTexture = resourcesManager.getTexture(rs::brick);
    uint space = 2;
    uint offsetY = 50;
    uint offsetX = 10;
    uint i = 0;
    uint j = 0;

    auto LevelFile = resourcesManager.deLevelFile();
    std::string levelFileName = LevelFile.first;
    uint level = LevelFile.second;

    std::string line;
    std::string brickCode;
    std::fstream fs;
    
    fs.clear();
    // std::vector<std::function<std::shared_ptr<gm::ConstObject>(uint i, uint j, sf::Texture const& texture, std::pair<int16_t, sf::Color> )>> factory;
    auto path = std::filesystem::path(levelFileName);
    if(std::filesystem::exists(path)){
        fs.open(levelFileName, std::ios::in);
        while(std::getline(fs , line)){
            std::stringstream brickLine(line);
            while(std::getline(brickLine ,brickCode ,',')){
                std::cout<<brickCode<<std::endl;
                gm::Type bricType = static_cast<gm::Type>(stoi(brickCode));
                if(bricType != gm::Type::noType){
                    auto brick = resourcesManager.m_factoryMap[bricType](offsetX +(brickTexture.getSize().x+space)*j ,offsetY + (brickTexture.getSize().y+space)*i, level ,brickTexture);
                    bricks.insert(brick);
                }
                std::cout<<bricks.size()<<std::endl;
                brickCode.clear();
                ++j;
            }
            line.clear();
            brickLine.clear();
            j = 0;
            ++i;
        }
    }
    fs.close();
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