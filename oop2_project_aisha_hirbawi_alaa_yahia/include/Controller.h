#pragma once
#include <SFML/Audio.hpp>
#include "Window.h"
#include "Menu.h"
#include "Game.h"
class Controller
{
public:
	//constructor
	Controller() { set(); };
	//runs the game
	void runGame();
	//sets music
	void set() { 
		if (!music.openFromFile("menu_music.ogg"))
		{
			throw "music doesn't open";
		}
		music.setPosition(0, 1, 10); // change its 3D position
		music.setLoop(true);         // make it loop

	}
	//initializes the Menu bar
	void initializeMenu();
	//gets the window
	inline Window* getWindow() { return &mWindow; }
	//destructor
	~Controller() { music.stop(); }

private:
	Window mWindow;
	sf::Clock gameClock;
	Menu mainMenu;
	Game mGame;
	sf::Music music;
};
