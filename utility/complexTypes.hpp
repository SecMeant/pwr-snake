#ifndef COMPLEXTYPES_H
#define COMPLEXTYPES_H

#include <string>
#include "SFML/Graphics.hpp"

struct renderObject
{
	sf::Texture texture;
	sf::RectangleShape shape;
	std::string assetPath;
};

enum sceneID:size_t
{
	mainmenu = 0,
	highscores = 1,
	none = 1337
};
#endif // COMPLEXTYPES_H
