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
#endif // COMPLEXTYPES_H
