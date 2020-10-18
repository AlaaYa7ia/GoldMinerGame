#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Menu.h"
#include "StageHandler.h"
#include <cmath>
#include <SFML/Audio.hpp>
#include "Board.h"
class Game
{
public:
	Game() { setBakground(); };
	virtual ~Game() = default;
	//in the game, sets an draws the game.
	void inGame(Window& w, Menu& mainMenu, sf::Music& music);
	void drawG(Window& window) { board.drawData(window); board.checkCollision(); }

private:
	//sets the background
	inline void setBakground()
	{
		tBackGround.loadFromFile("BackGround.jpg");
		sBackGround.setTexture(tBackGround);
	}
	StageHandler handlMyStage;
	sf::Texture tBackGround;
	sf::Sprite sBackGround;
	Roller* roller;
	std::vector<SelfMovment*>selfMove;
	Board board;
};