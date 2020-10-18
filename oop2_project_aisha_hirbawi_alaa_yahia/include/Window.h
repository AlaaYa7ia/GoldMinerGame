#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class Window : public sf::RenderWindow
{
public:
	Window() {};
	//-----------redifinition of openWindow -----------
	void openWindow(float w = sf::VideoMode::getDesktopMode().width, float h = sf::VideoMode::getDesktopMode().height,
		std::string title = "GOLD MINER", sf::Uint32 style = sf::Style::Fullscreen) 
	{
		setScreen(w, h);
		this->create(sf::VideoMode{ (unsigned int)w,(unsigned int)h }, title, style);
	}
	//--------set width & height of the window---------
	inline void setScreen(float w, float h)
	{
		width = w;
		height = h;
	}
	//--------get the width of the window---------
	inline float getWidth() const
	{
		return width;
	}
	//--------get the height of the window---------
	inline float getHeight() const
	{
		return height;
	}
	//--------check if the music sound is on--------
	inline bool getVolume() const
	{
		return soundOn;
	}
	//--------decide if the volume on or off--------
	inline void setVolume(bool val)
	{
		soundOn = val;
	}
	//--------draw backgroung of the game--------------
	inline void drawBackGround(sf::Sprite sBackGround,sf::Vector2u backgroundsize)
	{
		sBackGround.setOrigin(backgroundsize.x / 2, 0);
		sBackGround.setPosition(sf::Vector2f(this->getWidth()/2, 0));
		draw(sBackGround);
	}
private:
	float width;
	float height;
	bool soundOn = true;
	bool isFullscreen = false;

};

