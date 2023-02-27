#include "../includes/textObject.hpp"

gm::TextObject::TextObject(sf::Vector2f position)
{
    m_text.setPosition(position);
    m_text.setCharacterSize(30);
}

sf::Drawable const& gm::TextObject::getDraw() const
{
    return m_text;
}

void gm::TextObject::setMessage(std::string message)
{
    m_text.setString(message);
}

void gm::TextObject::set_Color(sf::Color& color)
{
    m_text.setColor(color);
}

void gm::TextObject::set_font(std::string font_file)
{
    sf::Font font;
    font.loadFromFile(font_file);
    m_text.setFont(font);
}

const sf::String& gm::TextObject::getMessage() const
{
    return m_text.getString();
}
