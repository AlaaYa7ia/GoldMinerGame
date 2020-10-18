#pragma once
#include "enumOpt.h"
#include "SFML\Graphics.hpp"
#include "Board.h"
#include "NonSelfMovment.h"

class GoldMiner :public NonSelfMovment
{
public:
	sf::SoundBuffer buffer;
	sf::Sound sound;

	GoldMiner() :MovedSp(ResourceManager::getSprite("GoldMiner1.png")),NonSelfMovment(ResourceManager::getSprite("GoldMiner.png"),
		ResourceManager::getSounds("gainObj.wav")) {
	//set the origin of the differnt sprites
	Sp.setOrigin({ 0,0 });
	MovedSp.setOrigin({ 0,0 });
	temp.setOrigin({ 0,0 });
	 Size = 1.5;
	}; 
	//redifiinetion of draw
	virtual int draw(Window& window,
		int indexX, int indexY)override;

private:
	//to save the main sprite
	sf::Sprite temp = Sp;
	sf::Sprite MovedSp;
};