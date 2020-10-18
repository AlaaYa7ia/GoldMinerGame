#pragma once
#include "NonSelfMovment.h"

/*a class that represent a diamond object*/
class Diamond :public NonSelfMovment
{
public:
	Diamond() :NonSelfMovment(ResourceManager::getSprite("Diamond.png"),
		ResourceManager::getSounds("BigGoldCatch.wav")) {
		 Size = 1.6;
		 Sp.setOrigin(SPCENTER, SPCENTER);
		};
	virtual ~Diamond() = default;


private:
};