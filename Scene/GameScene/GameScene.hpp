#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Scene.hpp"
#include "Board/Board.hpp"

#include "../../utility/complexTypes.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

class GameScene:public Scene
{
private:
	static constexpr const char *tileTexturePath 
		= "./assets/rocktile.png";
	
	static constexpr const char *cherryTexturePath 
		= "./assets/cherry.png";
	
	Board board;

	// Textures
	sf::Texture tileTexture;
	sf::Texture cherryTexture;
	sf::RectangleShape tile;

	virtual sceneID eventLoop() override;
	inline void initializeBoard();
	inline void loadTextures();
	inline void drawBoard();
public:
	explicit GameScene
	(const std::shared_ptr<sf::RenderWindow> &wnd);

	virtual sceneID switchScene() override;
};

#endif // GAMESCENE_H
