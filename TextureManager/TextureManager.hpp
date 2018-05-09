#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "stdint.h"
#include <SFML/Graphics.hpp>

// Im not sure about correctness of below code.
// Maybe i should perform transform operations
// textures instead of adding each variant as
// separate file. TODO: maybe change it in future

struct SnakeBodyTex
{
	sf::Texture vertical;
	sf::Texture horizontal;

	constexpr static const char *verticalPath =
		"./assets/snake/body/snakeBodyVertical.png";
	
	constexpr static const char *horizontalPath =
		"./assets/snake/body/snakeBodyHorizontal.png";

	inline void loadTextures()
	{
		this->vertical.loadFromFile(this->verticalPath);
		this->horizontal.loadFromFile(this->horizontalPath);
	}
};

struct SnakeHeadTex
{
	sf::Texture left;
	sf::Texture right;
	sf::Texture up;
	sf::Texture down;

	constexpr static const char *leftpath =
		"./assets/snake/head/snakeHeadLeft.png";

	constexpr static const char *rightpath =
		"./assets/snake/head/snakeHeadRight.png";

	constexpr static const char *uppath =
		"./assets/snake/head/snakeHeadUp.png";

	constexpr static const char *downpath =
		"./assets/snake/head/snakeHeadDown.png";

	inline void loadTextures()
	{
		this->left.loadFromFile(this->leftpath);
		this->right.loadFromFile(this->rightpath);
		this->up.loadFromFile(this->uppath);
		this->down.loadFromFile(this->downpath);
	}
};

struct SnakeTailTex
{
	sf::Texture left;
	sf::Texture right;
	sf::Texture up;
	sf::Texture down;

	constexpr static const char *leftpath =
		"./assets/snake/tail/snakeTailLeft.png";

	constexpr static const char *rightpath =
		"./assets/snake/tail/snakeTailRight.png";

	constexpr static const char *uppath =
		"./assets/snake/tail/snakeTailUp.png";

	constexpr static const char *downpath =
		"./assets/snake/tail/snakeTailDown.png";

	inline void loadTextures()
	{
		this->left.loadFromFile(this->leftpath);
		this->right.loadFromFile(this->rightpath);
		this->up.loadFromFile(this->uppath);
		this->down.loadFromFile(this->downpath);
	}
};

struct SnakeTurnTex
{
	sf::Texture snakeTurnDR;
	sf::Texture snakeTurnLD;
	sf::Texture snakeTurnLU;
	sf::Texture snakeTurnUR;

	constexpr static const char *snakeTurnDRPath =
		"./assets/snake/turn/snakeTurnDR.png";
	
	constexpr static const char *snakeTurnLDPath =
		"./assets/snake/turn/snakeTurnLD.png";
	
	constexpr static const char *snakeTurnLUPath =
		"./assets/snake/turn/snakeTurnLU.png";

	constexpr static const char *snakeTurnURPath =
		"./assets/snake/turn/snakeTurnUR.png";

	inline void loadTextures()
	{
		this->snakeTurnDR.loadFromFile(this->snakeTurnDRPath);
		this->snakeTurnLD.loadFromFile(this->snakeTurnLDPath);
		this->snakeTurnLU.loadFromFile(this->snakeTurnLUPath);
		this->snakeTurnUR.loadFromFile(this->snakeTurnURPath);
	}
};

class TextureManager
{
private:
	// Prevents from creating more than one TextureManager
	static int32_t lifecount;

	inline void loadTextures();
	inline void loadFonts();
public:
	// Textures
	static sf::Texture brickBackgroundTex;
	static sf::Texture waterandsandBackgroundTex;
	static sf::Texture highscoresBackgroundTex;
	static sf::Texture tileTexture;
	static sf::Texture cherryTexture;
	static sf::Texture redButtonDownTex;
	static sf::Texture redButtonUpTex;
	static sf::Texture yellowButtonDownTex;
	static sf::Texture yellowButtonUpTex;
	static sf::Texture blueButtonDownTex;
	static sf::Texture blueButtonUpTex;
	static sf::Texture blueSliderLeftTex;
	static sf::Texture pypyTex;
	static SnakeBodyTex snakeBodyTex;
	static SnakeHeadTex snakeHeadTex;
	static SnakeTailTex snakeTailTex;
	static SnakeTurnTex snakeTurnTex;

	static sf::Font defaultFont;
	static sf::Font mushyLove;

	static constexpr const char *brickBackgroundTexPath 
		= "./assets/default-background.png";

	static constexpr const char *waterandsandBackgroundTexPath 
		= "./assets/waterandsand-background.png";

	static constexpr const char *highscoresBackgroundTexPath 
		= "./assets/highscores.png";
	
	static constexpr const char *tileTexturePath 
		= "./assets/rocktile.png";

	static constexpr const char *cherryTexturePath 
		= "./assets/cherry.png";

	static constexpr const char *redButtonDownTexPath
		= "./assets/red_button_down.png";

	static constexpr const char *redButtonUpTexPath
		= "./assets/red_button_up.png";

	static constexpr const char *yellowButtonDownTexPath
		= "./assets/yellow_button_down.png";

	static constexpr const char *yellowButtonUpTexPath
		= "./assets/yellow_button_up.png";

	static constexpr const char *blueButtonDownTexPath
		= "./assets/blue_button_down.png";

	static constexpr const char *blueButtonUpTexPath
		= "./assets/blue_button_up.png";

	static constexpr const char *blueSliderLeftTexPath
		= "./assets/blue_sliderLeft.png";

	static constexpr const char *snakeHeadTexPath
		= "./assets/snake/snakeHead.png";

	static constexpr const char *snakeBodyTexPath
		= "./assets/snake/snakeBody.png";

	static constexpr const char *snakeTailTexPath
		= "./assets/snake/snakeTail.png";

	static constexpr const char *snakeTurnTexPath
		= "./assets/snake/snakeTurn1.png";
	
	static constexpr const char *pypyTexPath
		= "./assets/pypy.png";

	static constexpr const char *defaultFontPath
		= "./assets/font/orange_juice.ttf";

	static constexpr const char *mushyLovePath
		= "./assets/font/mushy_love.ttf";

	TextureManager();
	~TextureManager();
};

#endif // TEXTUREMANAGER_H
