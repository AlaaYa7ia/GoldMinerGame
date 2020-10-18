#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Window.h"

class TextDrawer
{
public:
	TextDrawer() { m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf"); } 
	//text for menu, status bar, messeges
	inline void setText(std::string content, const float& x, const float& y,
		unsigned int fontSize = 24, const sf::Color& c = sf::Color::White,
		std::string font = "",sf::Uint32 style = sf::Text::Style::Italic)
	{
		if (font != "")//load only once
			m_font.loadFromFile(font); 

		text.setFont(m_font);
		text.setString(content);
		text.setCharacterSize(fontSize);
		text.setFillColor(c);
		text.setStyle(style);
		text.setPosition(x, y);
	}

	inline void draw(Window& w) {w.draw(text);}
	//put text in the  center
	inline void centerText() {
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
	}
	//get text width
	inline float getTextWidth() {return text.getGlobalBounds().width;}
	//get the left bound
	inline float getTextX() {return text.getGlobalBounds().left;}
	//set the font
	void setFont(const std::string& f = "C:/Windows/Fonts/Arial.ttf");
	//get the font
	inline sf::Font getFont() const {return m_font;}

private:
	static bool loaded;
	sf::Font m_font;
	sf::Text text;
};
//printing with << operator
inline Window& operator<<(Window& w, TextDrawer& d) {d.draw(w);return w;}