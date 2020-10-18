#pragma once
#include "NonSelfMovment.h"

/*a class that represents a gold object*/
class Gold :public NonSelfMovment
{
public:
	//GameObject(sf::Sprite s) :Sp(s), preScaled(sf::Vector2f{ 1,1 }) {};
	Gold(char s) :NonSelfMovment(ResourceManager::getSprite("Gold.png"),
		ResourceManager::getSounds("smallGoldCatch.wav")) {
		 setSize(s); };
	virtual ~Gold() = default;
	//sets the gold size
	inline void setSize(char s) {
		if (s == 'S') { Size = 1.2; }
		else if (s == 'L') { Size = 4.0; }
		else { Size = 2.5; }
	}
private:
	
};