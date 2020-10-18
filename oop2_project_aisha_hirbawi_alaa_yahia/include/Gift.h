#pragma once
#include "NonSelfMovment.h"

const int XPOS = 350, BOM_NUM = 2, XDIFFER =50;
/*a class that represents a gift object*/
class Gift :public NonSelfMovment
{
public:
	Gift(sf::Sprite x,int t) :NonSelfMovment(ResourceManager::getSprite("Gift.png"),
		ResourceManager::getSounds("BigGoldCatch.wav")),SGType(x) {
		gType = t;
		SGType.setOrigin({ SPCENTER,0 });
		Size = 2.0;
	};
	virtual ~Gift() = default;
	virtual void move(int& score);
	void setHidden(bool h) { Sp = SGType; Gifted = h; }

	//gets the money value for the gift
	virtual int getGiftValue() { return 0; }
	

protected:
	bool Gifted = true;
	sf::Sprite SGType;
};