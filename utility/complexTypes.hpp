#ifndef COMPLEXTYPES_H
#define COMPLEXTYPES_H

#include <string>
#include <stdint.h>
#include "SFML/Graphics.hpp"
#include "../TextureManager/TextureManager.hpp"

struct renderObject
{
	sf::Texture texture;
	sf::RectangleShape shape;
	std::string assetPath;
};

enum sceneID:int32_t
{
	mainmenu = 0,
	highscores = 1,
	gamescene = 2,
	none = 1337
};

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

class Button
{
public:
	sf::Texture *pressedTexture;
	sf::Texture *releasedTexture;
	sf::Sprite sprite;

	inline void loadTextures
	(sf::Texture *upTexture, sf::Texture *downTexture)
	{
		this->releasedTexture = upTexture;
		this->pressedTexture = downTexture;
		this->sprite.setTexture(*this->releasedTexture, true);
	}

	inline void loadTextures
	(sf::Texture *uniTexture)
	{
		this->releasedTexture = uniTexture;
		this->pressedTexture = uniTexture;
		this->sprite.setTexture(*this->releasedTexture, true);
	}

	inline void press()
	{this->sprite.setTexture(*this->pressedTexture, true);}

	inline void release()
	{this->sprite.setTexture(*this->releasedTexture, true);}
};


#endif // COMPLEXTYPES_H
