#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Scene.hpp"
#include "Board/Board.hpp"

#include "../../utility/stdshared.hpp"

#include <vector>
#include <memory>

// Settings are picked manualy
// This might not be the best way
// Maybe it should be calculated
// TODO ^^^
namespace boardSettings
{
	// Width and height are in tiles units
	constexpr int32_t boardWidth = 18;
	constexpr int32_t boardHeight = 12;
};

class GameScene:public Scene
{
private:
	Board board;

	// Textures
	sf::Texture tileTexture;
	sf::Texture cherryTexture;
	sf::RectangleShape tile;

	// Buttons
	Button returnMainMenu;

	virtual sceneID eventLoop() override;
	inline void drawBoard();

	// Initializing helpers
	inline void initializeBoard();
	inline void initializeButtons();
	inline void loadTextures();

	/* Helpers for handling mouse events 
	 *
	 * Takes event as argument
	 * Returns id of scene if mouse event caused 
	 * scene switch. If scene shouldnt be switched
	 * sceneID::none is returned
	 *
	 * */
	inline sceneID handleMousePressed(const sf::Event &mev);
	inline sceneID handleMouseReleased(const sf::Event &mev);
public:
	explicit GameScene
	(const std::shared_ptr<sf::RenderWindow> &wnd);

	virtual sceneID switchScene() override;
};

#endif // GAMESCENE_H
