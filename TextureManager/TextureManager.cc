#include "TextureManager.hpp"

// Creation of static memebrs
sf::Texture TextureManager::brickBackgroundTex;
sf::Texture TextureManager::highscoresBackgroundTex;
sf::Texture TextureManager::tileTexture;
sf::Texture TextureManager::cherryTexture;
sf::Texture TextureManager::redButtonDownTex;
sf::Texture TextureManager::redButtonUpTex;
sf::Texture TextureManager::yellowButtonDownTex;
sf::Texture TextureManager::yellowButtonUpTex;
sf::Texture TextureManager::blueButtonDownTex;
sf::Texture TextureManager::blueButtonUpTex;
sf::Texture TextureManager::blueSliderLeftTex;
sf::Texture TextureManager::snakeHeadTex;
sf::Texture TextureManager::snakeBodyTex;
int32_t TextureManager::lifecount = 0;

TextureManager::TextureManager()
{
	if(this->lifecount > 0)
		return;

	++lifecount;

	this->loadTextures();
}

void TextureManager::loadTextures()
{
	TextureManager::brickBackgroundTex.loadFromFile(this->brickBackgroundTexPath);
	TextureManager::highscoresBackgroundTex.loadFromFile(this->highscoresBackgroundTexPath);
	TextureManager::tileTexture.loadFromFile(this->tileTexturePath);
	TextureManager::cherryTexture.loadFromFile(this->cherryTexturePath);
	TextureManager::redButtonDownTex.loadFromFile(this->redButtonDownTexPath);
	TextureManager::redButtonUpTex.loadFromFile(this->redButtonUpTexPath);
	TextureManager::yellowButtonDownTex.loadFromFile(this->yellowButtonDownTexPath);
	TextureManager::yellowButtonUpTex.loadFromFile(this->yellowButtonUpTexPath);
	TextureManager::blueButtonDownTex.loadFromFile(this->blueButtonDownTexPath);
	TextureManager::blueButtonUpTex.loadFromFile(this->blueButtonUpTexPath);
	TextureManager::blueSliderLeftTex.loadFromFile(this->blueSliderLeftTexPath);
	TextureManager::snakeHeadTex.loadFromFile(this->blueSliderLeftTexPath);
	TextureManager::snakeHeadTex.loadFromFile(this->blueSliderLeftTexPath);
}

TextureManager::~TextureManager()
{
	--this->lifecount;
}
