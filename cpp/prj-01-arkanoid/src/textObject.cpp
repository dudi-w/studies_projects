#include <iostream>
#include "../includes/textObject.hpp"

gm::TextObject::TextObject(sf::Vector2f const& position)
{
    m_text.setPosition(position);
    m_text.setString("dvfv");
}

gm::TextObject::TextObject(float x ,float y)
{
    m_text.setPosition(x,y);
}

sf::Drawable const& gm::TextObject::getDraw() const
{
    return m_text;
}

void gm::TextObject::set_character_size(uint8_t size)
{
    m_text.setCharacterSize(size);
}

void gm::TextObject::set_Color(sf::Color& color)
{
    m_text.setFillColor(color);
}

void gm::TextObject::set_font(sf::Font const& font)
{
    m_text.setFont(font);
}

void gm::TextObject::setMessage(std::string message)
{
    m_text.setString(message);
}

const sf::String& gm::TextObject::getMessage() const
{
    return m_text.getString();
}
