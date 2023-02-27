#include "../includes/life.hpp"

gm::Life::Life(uint16_t life)
: m_count(life)
{}

uint16_t gm::Life::getCount() const
{
    return m_count;
}

bool gm::Life::isKill() const
{
    return !m_count;
}

void gm::Life::add(uint16_t n)
{
    m_count += n;
}

void gm::Life::sub(uint16_t n)
{
    m_count -= n;
}
