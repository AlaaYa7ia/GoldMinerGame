#pragma once
#include "Gift.h"

/*a clas that represents a force that is given as a gift from the gift object*/
class Force :public Gift
{
public:
	Force() :Gift(ResourceManager::getSprite("force.png"),SPEED) {}
	virtual ~Force() = default;
private:
};