#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "stdint.h"
#include <SFML/Graphics.hpp>

// Im not sure about correctness of below code.
// Maybe i should perform transform operations
// textures instead of adding each variant as
// separate file. TODO: maybe change it in future

struct SnakeHeadTex
{
	sf::Texture left;
	sf::Texture right;
	sf::Texture up;
	sf::Texture down;

	constexpr static const char *leftPath =
		"./assets/snake/head/snakeHeadLeft.png";

	constexpr static const char *rightPath =
		"./assets/snake/head/snakeHeadRight.png";

	constexpr static const char *upPath =
		"./assets/snake/head/snakeHeadUp.png";

	constexpr static const char *downPath =
		"./assets/snake/head/snakeHeadDown.png";

	inline void loadTextures()
	{
		this->left.loadFromFile(this->leftPath);
		this->right.loadFromFile(this->rightPath);
		this->up.loadFromFile(this->upPath);
		this->down.loadFromFile(this->downPath);
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
	static sf::Texture snakeBodyTex;
	static SnakeHeadTex snakeHeadTex;

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
		= "./assets/snake/head/snakeHead.png";

	static constexpr const char *snakeBodyTexPath
		= "./assets/snake/body/snakeBody.png";

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
