#include "TextureManager.hpp"

int32_t TextureManager::lifecount = 0;

TextureManager::TextureManager()
{
	if(this->lifecount > 0)
		return;

	// TODO LOAD TEXTURES
}
