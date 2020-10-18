#pragma once
#include "SelfMovment.h"

class Animal :public SelfMovment
{
public:
	/*A humester that moves right and left*/
	Animal() :SelfMovment(ResourceManager::getSprite("Humester.png"), 
		ResourceManager::getSounds("SmallGoldCatch.wav")) {
		m_clock.restart();
		Sp.setOrigin({ SPCENTER,SPCENTER });
		Size = 1.3;
	};

	virtual ~Animal() = default;

	/*Moves the humester to the right then to the left*/
	void move(Window& window, int indexX, int indexY);

	/*Sets the Origin of the object's sprite to the middile top of the sprite */
	inline void resetOrigin() { Sp.setOrigin({ SPCENTER,0 }); }
private:
	float speed = 4; 
    	//is it a move to the right (true) or left (false)
	bool rightMove = true;
	
};