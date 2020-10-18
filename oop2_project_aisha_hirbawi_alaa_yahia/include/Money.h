#pragma once
#include "Gift.h"
const int MINBOUNUS = 3;
class Money :public Gift
{
public:
	Money() :Gift(ResourceManager::getSprite("money.png"),MONEY) {}
	//give the gift of the vaue
	virtual int getGiftValue() const{ return rand() % 10+ MINBOUNUS; }
private:
};