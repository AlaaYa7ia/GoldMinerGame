#pragma once
#include "GameObject.h"

const double HOP = 5,GAINED= 50; /*roller degreee/ rotation in each time*/
class SelfMovment :public GameObject
{
public:
	SelfMovment(sf::Sprite s, sf::Sound d) :GameObject(s, d), initPos(0) {}
	//init the location
	inline void setFirstLoc(float x, float y) { FirstLoc = sf::Vector2f(x, y); }
	//get the firs loc of the obj
	inline sf::Vector2f getFirstLoc() const { return FirstLoc; }
	//draw func for the moved obj
	virtual int draw (Window& window,int indexX, int indexY) override;
	//move the object according to givven indexes
	virtual void move(Window& window, int indexX, int indexY)=0;
	//default distractor
	virtual ~ SelfMovment() = default;
protected:
	sf::Vector2f FirstLoc;
	int initPos;
};


