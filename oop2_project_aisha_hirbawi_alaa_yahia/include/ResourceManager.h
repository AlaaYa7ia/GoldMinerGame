#pragma once
#include <unordered_map>
#include <string>
#include "SFML\Graphics.hpp"
#include <SFML/Audio.hpp>

class ResourceManager {
private:
	//private constractor
	ResourceManager() {};
	//texture map
	static std::unordered_map<std::string, sf::Texture*> texturesMap;
	//load the texture from file 
	inline static sf::Texture* getTexture(std::string s) {
		auto obj = texturesMap.find(s);
		if (obj == texturesMap.end()) {
			sf::Texture* t = new(std::nothrow) sf::Texture();
			texturesMap[s] = t;
			t->loadFromFile(s);
		}
		return texturesMap[s];
	}

	//sound buffer map
	static std::unordered_map<std::string, sf::SoundBuffer*> buffersMap;
	//load the sound from file 
	inline static sf::SoundBuffer* getSoundBuf(std::string s) {
		auto obj = buffersMap.find(s);
		if (obj == buffersMap.end()) {
			sf::SoundBuffer* t = new(std::nothrow) sf::SoundBuffer();
			buffersMap[s] = t;
			if (!t->loadFromFile(s))
			{
				//std::cout << "couldnt load file /n";
				exit(EXIT_FAILURE);

			}
		}
		return buffersMap[s];
	}
public:
	//function that we could call to take sprite
	inline static sf::Sprite getSprite(std::string s) {

		sf::Sprite ts;
		ts.setTexture(*getTexture(s));
		return ts;
	}

	//function that we could call to take sound
	inline static sf::Sound getSounds(std::string s) {

		sf::Sound ts;
		ts.setBuffer(*getSoundBuf(s));
		return ts;
	}
};