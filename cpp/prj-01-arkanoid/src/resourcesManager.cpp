#include "../includes/resourcesManager.hpp"

gm::ResourcesManager::ResourcesManager(std::string background, std::string ball, std::string paddle, std::string brick , std::string scoreFont)
{
    m_background.loadFromFile(background);
    m_ball.loadFromFile(ball);
    m_paddle.loadFromFile(paddle);
    m_brick.loadFromFile(brick);
    m_font.loadFromFile(scoreFont);
}
