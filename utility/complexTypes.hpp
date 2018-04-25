#ifndef COMPLEXTYPES_H
#define COMPLEXTYPES_H

#include <string>
#include <stdint.h>
#include "SFML/Graphics.hpp"

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

class Button
{
public:
	sf::Texture pressedTexture;
	sf::Texture releasedTexture;
	sf::Sprite sprite;

	inline void loadTextures
	(const char *pressedTexPath, const char *releasedTexPath)
	{
		this->pressedTexture.loadFromFile(pressedTexPath);
		this->releasedTexture.loadFromFile(releasedTexPath);
		this->sprite.setTexture(this->releasedTexture, true);
	}

	inline void press()
	{
		this->sprite.setTexture(this->pressedTexture, true);
	}

	inline void release()
	{
		this->sprite.setTexture(this->releasedTexture, true);
	}
};
#endif // COMPLEXTYPES_H
