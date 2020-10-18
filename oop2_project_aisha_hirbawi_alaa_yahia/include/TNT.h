#pragma once
#include "NonSelfMovment.h"
const int ANIMATION = 4;
class TNT :public NonSelfMovment
{
public:
	TNT() :NonSelfMovment(ResourceManager::getSprite("TNT.png"),
		ResourceManager::getSounds("Explosion.wav")),
	Explod(ResourceManager::getSprite("explosion.png")){
		//for the anime pic we set the origin in the half top
		Explod.setOrigin( Sp.getTexture()->getSize().x / 2,0 );
		Size = 2.0;
	};
	//-------- setHidden redifinition -----------
	inline void setHidden(bool h) { Sp = Explod; exploded = h; }
	//-------- we make the object hide after some animation--------
	virtual void move(int& score)override;

private:
	bool exploded = false;
	//----------for animation Pic--------
	sf::Sprite Explod;

};