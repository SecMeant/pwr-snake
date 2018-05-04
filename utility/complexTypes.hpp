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

enum class GameState
{
	Pending,
	Over
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

namespace scoreBoardSettings
{
	constexpr int headerOffsetx = 0;
	constexpr int headerOffsety = 0;
	constexpr int headerWidth = 800;
	constexpr int headerHeight = 80;
	constexpr int nameOffset = 150;
	constexpr int scoreOffset = 550;
	constexpr int topmargin = 30;
	constexpr const char *headerText = "SCORE TABLE";
};

class TableHeader
{
public:
	sf::Text text;
	sf::RectangleShape background;

	inline void setPosition(float x, float y)
	{
		this->background.setPosition(x,y);
		this->centerTextRelativeToBackground();
	}

	inline void centerTextRelativeToBackground()
	{
		float headerOffset = scoreBoardSettings::headerWidth/2;
		headerOffset -= this->text.getLocalBounds().width;
		headerOffset += this->background.getGlobalBounds().left;
		this->text.setPosition(headerOffset,this->background.getGlobalBounds().top);
	}
};

class TableEntry
{
public:
	sf::Text name;
	sf::Text score;

	inline void resetPosition()
	{
		constexpr float yoffset = scoreBoardSettings::headerHeight+
		                          scoreBoardSettings::topmargin;

		this->name.setPosition
			(scoreBoardSettings::nameOffset, yoffset);

		this->score.setPosition
			(scoreBoardSettings::scoreOffset, yoffset);
	}

	inline void shiftPosition()
	{
		float currentPos;
		currentPos = this->name.getGlobalBounds().top;
		currentPos += scoreBoardSettings::topmargin;

		this->name.setPosition
			(scoreBoardSettings::nameOffset, currentPos);

		this->score.setPosition
			(scoreBoardSettings::scoreOffset, currentPos);
	}
};

#endif // COMPLEXTYPES_H
