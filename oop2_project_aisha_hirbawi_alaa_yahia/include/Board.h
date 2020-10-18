#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "enumOpt.h"
#include "CollisionHandling.h"
#include <typeinfo>
#include <vector>
#include <memory>
#include <exception>
#include <random>
#include <cstdlib>
#include <ctime>

const int NO_GIFT = -1, MODIFIER1 = 20;
const float PIC_ZIAE = 64.f, MODIFTIER2 = 0.025f;

class GameObject; 
class Roller;
class SelfMovment;


class Board
{
public:

	// default constructor.
	Board();
	// destructor.
	~Board();
	// set the board
	void setBoard();
	// open the file
	void openBoardFile();
	// load the maps
	bool loadFile(Window& window);
	// setmap size
	void setMapSize(int width, int height);
	//read the board from the beggining
	void reset(Window& w);
	// draw the GameObject
	void drawData(Window& window);
	//flag to know if the file has been  loaded
	bool loadFfile = false;
	//gets the begin of  the bar list in the screen
	inline const  float getBegin() const { return m_mapBeginX; };
	//gets stage number
	inline const int getStage() const { return m_stageNum; };
	// get the roller info
	Roller* getRoller() const;
	//sets the beggining of the bar list
	void setBegin(const Window& window);
	//handeles explosion
	void exploid();
	//check collision between all the game objects
	void checkCollision();
	//check clollision between tow objects
	bool collide(GameObject& a, GameObject& b);
	//returns the scores
	int getScore() const { return m_score; }
	//returns gift type
	int getGift() const { return m_GType; }
	//sets gift type to no gift 
	inline void resetGift() { m_GType = NO_GIFT; }
	//sets scores to zero
	void resetScore() { m_score = 0; }
	


private:
	//draw statics
	void drawStaticts(Window& window, float h, float m, float w);
	//draw  non statics
	void drawNonStaticts(Window& window, float h, float m, float w);
	//the ststics (non self movment) vector
	std::vector<std::vector<GameObject*>> statics;
	//returning the GameObject data
	GameObject* getChar(const char& c, int i, int j);
	//filling the map
	void fillMap();
	//members: flgs and counters.
	int m_rows = 0,
		m_cols = 0,
		m_score = 0,
		m_stageNum=1,
		m_GType= NO_GIFT;
	//the begenning of the bar list
	float m_mapBeginX = 0;
	//radius for showing the objects on screen
	const int radius = 3;
	//pointer to the roller the main player 
	Roller* roller;
	//Self Movmen vector
	std::vector<SelfMovment*>selfMove;
	//the board file that we read stages from it
	std::ifstream boardFile;
};