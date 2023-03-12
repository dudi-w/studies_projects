#ifndef CREATORS_HPP
#define CREATORS_HPP

#include <unordered_set>
#include <memory>

#include "GMenum.hpp"
#include "definitions.hpp"
#include "eventManager.hpp"
#include "collisionsManager.hpp"
#include "player.hpp"
#include "resourcesManager.hpp"
#include "textObject.hpp"
#include "brick.hpp"

namespace gm{

std::shared_ptr<gm::Platform> createPaddle(gm::ResourcesManager& resourcesManager);

std::shared_ptr<gm::Ball> createBall(gm::ResourcesManager& resourcesManager, std::shared_ptr<gm::Platform> paddle);

std::unordered_set<std::shared_ptr<gm::ConstObject>> createBricks(gm::ResourcesManager& resourcesManager);

std::unique_ptr<sf::Text> createScore(gm::ResourcesManager& resourcesManager);

std::unique_ptr<sf::Text> createLife(gm::ResourcesManager& resourcesManager);

static std::unordered_map<gm::Type ,std::function<std::shared_ptr<gm::ConstObject>( uint i, uint j, uint level, sf::Texture const& texture)>> FactoryMap
{
    {gm::Type::brickType1 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 50, sf::Color::White, 1);}},
    {gm::Type::brickType2 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 60, sf::Color(255,127,80),1);}},
    {gm::Type::brickType3 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 70, sf::Color(0,255,255),1);}},
    {gm::Type::brickType4 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 80, sf::Color::Green,1);}},
    {gm::Type::brickType5 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 90, sf::Color::Red,1);}},
    {gm::Type::brickType6 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 100, sf::Color::Blue,1);}},
    {gm::Type::brickType7 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 110, sf::Color(255,153,204),1);}},
    {gm::Type::brickType8 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 120, sf::Color(255,153,51),1);}},
    {gm::Type::brickType9 , []( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::Brick>( sf::Vector2f(i, j), texture, 50 * level, sf::Color(255,215,0),1);}},
    {gm::Type::brickType10 ,[]( uint i, uint j, uint level, sf::Texture const& texture){ return std::make_shared<gm::IndestructBrick>( sf::Vector2f(i, j), texture, 0, sf::Color(160,160,160), 1);}}
};

// static std::unordered_map<gm::Type , std::pair<int16_t, sf::Color>> typeMap
// {
//     {gm::Type::noType , {0, sf::Color(0,0,0)}},
//     {gm::Type::brickType1 , {50, sf::Color::White}},
//     {gm::Type::brickType2 , {60, sf::Color(255,127,80)}},
//     {gm::Type::brickType3 , {70, sf::Color(0,255,255)}},
//     {gm::Type::brickType4 , {80, sf::Color::Green}},
//     {gm::Type::brickType5 , {90, sf::Color::Red}},
//     {gm::Type::brickType6 , {100, sf::Color::Blue}},
//     {gm::Type::brickType7 , {110, sf::Color(255,153,204)}},
//     {gm::Type::brickType8 , {120, sf::Color(255,153,51)}},
//     {gm::Type::brickType9 , {50, sf::Color(255,215,0)}},
//     {gm::Type::brickType10 , {0, sf::Color(160,160,160)}}
// };

} // namespace gm

#endif
