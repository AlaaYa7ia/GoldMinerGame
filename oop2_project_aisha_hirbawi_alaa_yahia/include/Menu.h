#pragma once
#include <vector>
#include <functional>
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "TextDrawer.h"
#include <sstream>
//menu list ,each option with lambda function
typedef std::pair<std::string, std::function<bool(/*parameters*/Window&)>> Element;

class TextDrawer;
class Menu
{

private:
	std::vector<Element> menuList;
	bool inMenu = true;
	int selected = 0;
	TextDrawer d;
	sf::Texture tBackGround;
	sf::Sprite sBackGround;

public:
	//constractor
	Menu() { setBakground(); };
	~Menu() = default;
	//adding another option to the menue
	inline void add(std::string t, std::function<bool(Window&)> f) {menuList.push_back(std::pair(t, f));}
	inline void setInMenu(bool m){inMenu = m;}
	inline bool getInMenu() const{return inMenu;}
	//the menu background
	inline void setBakground()
	{
		tBackGround.loadFromFile("OpeningPic.jpg");
		sBackGround.setTexture(tBackGround);
	}
	//controlling paye choose in the menu and draw it 
	void draw(Window& w);
	Menu& operator=(bool v) noexcept // copy/move constructor is called to construct arg
	{
		setInMenu(v);
		return *this;
	} // destructor of arg is called to release the resources formerly held by *this
	explicit operator bool()const {
		return inMenu;
	}
};
//to print on sceen
inline Window& operator<<(Window& w, Menu& m) {
	m.draw(w);

	return w;
}