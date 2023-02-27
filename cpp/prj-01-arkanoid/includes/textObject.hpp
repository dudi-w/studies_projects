#ifndef TEXT_OBJECT_HPP
#define TEXT_OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "object.hpp"


namespace gm{ // game namespace

class TextObject : public Object
{
public:
	TextObject() = default;
	explicit TextObject(sf::Vector2f position);
	TextObject(TextObject const& other) = default;
    TextObject& operator=(TextObject const& other) = default;
	virtual ~TextObject() = default;

	virtual sf::Drawable const& getDraw() const override final;
    
	// virtual sf::Sprite& setShip() final;
    void setMessage(std::string message);
    void set_Color(sf::Color& color);
    void set_font(std::string font_file);
    const sf::String& getMessage() const;

private:
    sf::Text m_text;
};

} // namespace gm

#endif
