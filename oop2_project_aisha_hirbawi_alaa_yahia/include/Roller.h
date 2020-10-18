#pragma once
#include "SelfMovment.h"
const int RollerDegree = 75, RADIOS = 25, Arch = 30, DownDistance = 50, SimiCirc = 61;
const float PI = 3.14159265 / 180.,ROPEHI= 4.f,ROPEWD= 200.f;


class Roller :public SelfMovment
{
public:
	Roller() :SelfMovment(ResourceManager::getSprite("Roller.png"),
		ResourceManager::getSounds("rollerDown.wav")),down(DownDistance) {
		d2 = ResourceManager::getSounds("rollerUp.wav"); 
		rope.setFillColor(sf::Color::Black); 
		rope.setSize(sf::Vector2f(ROPEHI, ROPEWD));
		rope.setOrigin(0.0f, 2.0f);//SET the origrin at the top half
		//make the origin of the roller on th middle left
		Sp.setOrigin(0.0f, Sp.getTexture()->getSize().y/2);
		Size = 1.5;
	};
	//the first position of the roller
	void setFirstPos(int indexX, int indexY, float& length);
	//draw func override
	virtual int draw(Window& window,int indexX, int indexY) override;
	//move func override
	virtual void move(Window& window,int indexX, int indexY) override;
	//get the last movement of the roller
	inline sf::Vector2f getLastMovment()const{ return Sp.getPosition();}
	//get the start of the roller
	inline float getStartY()const { return startY; }
	//set speed of the roller
	void setSpeed(float s) { speed = s; }
	//speed factor when we got gift
	void setFactor(float s) { factor = s; }
	//simi sircle move
	void RoundMove(int indexX, int indexY,int factor, float &y);
	//if we reached the main place
	inline bool stopDown() const { return (down == DownDistance) ? true : false; }
	//distractor
	virtual ~Roller() { d2.stop(); }
private:
	float startY, speed =1, factor=1;
	int theta = RollerDegree, down, max = DownDistance-10;
	sf::Sound d2;
	bool roundMove = true,downMove=true;
	sf::RectangleShape rope;
	sf::Clock m_clock;
	sf::Vector2f lastMovement{ 0,0 };
};
