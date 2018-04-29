#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "stdint.h"
#include <SFML/Graphics.hpp>

class TextureManager
{
private:
	// Prevents from creating more than one TextureManager
	static int32_t lifecount;

	inline void loadTextures();
public:
	// Textures
	static sf::Texture brickBackgroundTex;
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
	static sf::Texture snakeHeadTex;
	static sf::Texture snakeBodyTex;

	static constexpr const char *brickBackgroundTexPath 
		= "./assets/default-background.png";

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
		= "./assets/blue_sliderLeft.png";

	static constexpr const char *snakeBodyTexPath
		= "./assets/blue_sliderLeft.png";

	TextureManager();
	~TextureManager();
};

#endif // TEXTUREMANAGER_H
