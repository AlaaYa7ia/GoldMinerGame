#pragma once
#include <iostream>
#include "enumOpt.h" 
#include "Window.h"
#include <sfml/Audio.hpp>
#include "ResourceManager.h"
const float movTime = 80;
const int SCOREBOUNOS = 50,MONEY = 0,
SPEED = 1, BOMB = 2,SPCENTER= 32;
class Roller;
class SelfMovment;
class GameObject
{
public:
	// default constructor
	GameObject(sf::Sprite s, sf::Sound d) :Sp(s),sound(d), preScaled(sf::Vector2f{ 1,1 }),
		gain(ResourceManager::getSounds("gainObj.wav")){
		// we set the origin in the half top
		Sp.setOrigin({ SPCENTER,0 });
		
	};
	// setting the GameObject location
	inline void setLocation(float x, float y) { location = sf::Vector2f(x, y); }
	// return the scale info
	inline virtual bool isScaled()const
	{
		return scaled;
	}

	//plays sound
	virtual void soundOn() { sound.play(); }

	//moves the object
	virtual void move(int& score);

	// function to scale the sprite.
	inline virtual void setScale(float scaleX, float scaleY)
	{
		// save the first scale data
		preScaled = Sp.getScale();
		postScaled.x = scaleX;
		postScaled.y = scaleY;
	}

	//retuns if the object is hidden
	inline bool IsHidden() const { return m_hidden; }

	// draws the game object
	virtual int draw(Window& window,
		int indexX, int indexY);

	//gets the size of an object
	virtual	float getObjSize() const { return Size; }

	// getting the GameObject location
	inline sf::Vector2f getLocation() const{return location;}

	//returns if intersects or not
	inline bool intersects(GameObject& obj) { 
		return this->Sp.getGlobalBounds().intersects(obj.Sp.getGlobalBounds()); 
	}

	//sets colide 
	inline void setColide(bool c) { colide = c; }

	//gets colide 
	inline bool getColide()const { return colide; }

	//sets the coordanates where to move 
	inline void setMoveCoords(float x, float y) { xMove = x; yMove = y;}

	//set start flag 
	inline void setStart(float s) { start = s; }

	//set Explosion position 
	inline void setExplosion(float x, float y) { explosion.x = x; explosion.y = y; }

	//get Explosion position 
	inline sf::Vector2f getExplosion()const { return explosion; }

	//sets if hidden
	inline virtual void setHidden(bool h) { m_hidden = h; }
    virtual ~GameObject() { sound.stop(); }

	//gets gift type
	inline const virtual int getGiftType() { return gType; }

	//set gift
	inline virtual void setGiftType(int g) { gType = g; }
private:
	bool colide = false;
	sf::Vector2f explosion{ 0,0 };
	
protected:
	float Size;
	bool m_hidden = false;
	float xMove, yMove, start;
	bool scaled = false;
	sf::Vector2f location{ 1,1 };
	sf::Vector2f preScaled{ 1,1 };
	sf::Vector2f postScaled{ 1,1 };
	sf::Sprite Sp;
	sf::Sound sound;
	sf::Sound gain;
	sf::Clock m_clock;
	int gType = -1;
};
