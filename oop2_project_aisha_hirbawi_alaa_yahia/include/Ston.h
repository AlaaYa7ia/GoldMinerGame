#pragma once
#include "NonSelfMovment.h"

class Ston :public NonSelfMovment
{
public:
	Ston(char s) :NonSelfMovment(ResourceManager::getSprite("rock.png"),
		ResourceManager::getSounds("rockCatch.wav")) { setSize(s);	};
	//set size for different stone
	void setSize(char s) {
		if (s == 'S') { Size = 2.0; }
		else { Size = 3.0; }
	}
private:
};