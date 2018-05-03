#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Scene.hpp"
#include "Snake/Snake.hpp"
#include "Board/Board.hpp"
#include "Logic/Logic.hpp"

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

namespace snakeSettings
{
	constexpr float moveInterval = 0.1f;
};

class GameScene:public Scene
{
private:
	Board board;
	Snake snake;
	Logic logic;
	std::pair<int32_t, int32_t> cherryCoords;

	int32_t pointsCount;

	// Buttons
	Button returnMainMenu;

	virtual sceneID eventLoop() override;
	inline void drawBoard() const;
	inline void drawSnake() const;
	inline void drawCherry() const;

	// Calls all methods that draws elements every game frame
	inline void renderGameTick() const;

	// Initializing helpers
	inline void initializeBoard();
	inline void initializeSnake();
	inline void initializeButtons();

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
	inline void handleKeyPressed(const sf::Event &kev);
public:
	explicit GameScene
	(const std::shared_ptr<sf::RenderWindow> &wnd);

	virtual sceneID switchScene() override;

	friend class Logic;
};

#endif // GAMESCENE_H
