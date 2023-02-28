#ifndef TEXT_OBJECT_HPP
#define TEXT_OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "object.hpp"


namespace gm{ // game namespace

class TextObject : public Object
{
public:
	TextObject() = default;
	explicit TextObject(sf::Vector2f const& position);
	explicit TextObject(float x ,float y);
	TextObject(TextObject const& other) = default;
    TextObject& operator=(TextObject const& other) = default;
	virtual ~TextObject() = default;

	virtual sf::Drawable const& getDraw() const override final;
    
	// virtual sf::Sprite& setShip() final;
    void set_character_size(uint8_t size);
    void set_Color(sf::Color& color);
    void set_font(sf::Font const& font);
    void setMessage(std::string message);
    sf::String const& getMessage() const;

private:
    sf::Text m_text;
};

} // namespace gm

#endif
