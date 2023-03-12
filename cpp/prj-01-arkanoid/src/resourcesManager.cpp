#include "../includes/resourcesManager.hpp"

gm::ResourcesManager::ResourcesManager()
: m_factoryMap(
{
    {gm::Type::brickType1 , [](uint i, uint j, [[maybe_unused]] uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 50, sf::Color::White, 1);}},
    {gm::Type::brickType2 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 60, sf::Color(255,127,80),1);}},
    {gm::Type::brickType3 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 70, sf::Color(0,255,255),1);}},
    {gm::Type::brickType4 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 80, sf::Color::Green,1);}},
    {gm::Type::brickType5 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 90, sf::Color::Red,1);}},
    {gm::Type::brickType6 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 100, sf::Color::Blue,1);}},
    {gm::Type::brickType7 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 110, sf::Color(255,153,204),1);}},
    {gm::Type::brickType8 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 120, sf::Color(255,153,51),1);}},
    {gm::Type::brickType9 , [](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 50 * level, sf::Color(255,215,0),1);}},
    {gm::Type::brickType10 ,[](uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::IndestructBrick>( sf::Vector2f(i, j), texture, 0, sf::Color(160,160,160), 1);}}
})
{
    insertTexture("./resources/2x1_NSwitch_ArkanoidEternalBattle.jpg", Resource::background);
    insertTexture("./resources/opening_screen.jpg", Resource::homescreen);
    insertTexture("./resources/ball2.png", Resource::ball);
    insertTexture("./resources/paddle.png", Resource::paddle);
    insertTexture("./resources/bricks1.jpg",Resource::brick);
    insertTexture("./resources/exit.png", Resource::exit);
    insertTexture("./resources/play.png", Resource::play);
    insertTexture("./resources/colorful-balloons-flying-sky.jpg", Resource::top10);
    insertTexture("./resources/sand.png", Resource::sandClock);
    insertFont("./resources/SwipeRaceDemo.ttf", Resource::font1);
    insertFont("./resources/Sportfield_Varsity-Outline2.otf", Resource::font2);
    insertFont("./resources/Famouse.ttf", Resource::font3);
    insertFont("./resources/MiracleFairway.otf", Resource::font4);
    // restartQeueu();
}

void gm::ResourcesManager::insertFont(std::string const& path, gm::ResourcesManager::Resource key)
{
    m_fontMap[key].loadFromFile(path);
}

void gm::ResourcesManager::insertTexture(std::string const& path, gm::ResourcesManager::Resource key)
{
    m_textureMap[key].loadFromFile(path);
}

void gm::ResourcesManager::inLevelFile(std::string const& path , uint level)
{
    m_levelFileName.push({path, level});
}

sf::Font const& gm::ResourcesManager::getFont(ResourcesManager::Resource key) const
{
    return m_fontMap.find(key)->second;
}

sf::Texture const& gm::ResourcesManager::getTexture(gm::ResourcesManager::Resource key) const
{
    return m_textureMap.find(key)->second;
}

std::pair<std::string, uint> gm::ResourcesManager::deLevelFile()
{
    auto levelFileName = m_levelFileName.front();
    m_levelFileName.pop();
    return levelFileName;
}

bool gm::ResourcesManager::isEndGame() const
{
    return m_levelFileName.empty();
}

void gm::ResourcesManager::restartQeueu()
{
    while(!m_levelFileName.empty()){
        m_levelFileName.pop();
    }

    m_levelFileName.push({"./resources/level-1.dat",1});
    m_levelFileName.push({"./resources/level-2.dat",2});
    m_levelFileName.push({"./resources/level-3.dat",3});
    m_levelFileName.push({"./resources/level-4.dat",4});
    m_levelFileName.push({"./resources/level-5.dat",5});
}
