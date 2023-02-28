#include "../includes/resourcesManager.hpp"

gm::ResourcesManager::ResourcesManager(std::string background, std::string homescreen, std::string ball, std::string paddle, std::string brick, std::string exit, std::string play ,std::string Font1 ,std::string Font2)
{
    m_background.loadFromFile(background);
    m_homescreen.loadFromFile(homescreen);
    m_ball.loadFromFile(ball);
    m_paddle.loadFromFile(paddle);
    m_brick.loadFromFile(brick);
    m_exit.loadFromFile(exit);
    m_play.loadFromFile(play);
    m_font1.loadFromFile(Font1);
    m_font2.loadFromFile(Font2);
}
