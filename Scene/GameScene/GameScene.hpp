#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../Scene.hpp"
#include "Snake/Snake.hpp"
#include "Board/Board.hpp"
#include "Logic/Logic.hpp"
#include "../../Window/Input/InputWindow.hpp"
#include "../../SaveManager/SaveManager.hpp"

#include "../../utility/stdshared.hpp"

#include <vector>
#include <memory>
#include <string>

extern SaveManager saveManager;

// Settings are picked manualy
// This might not be the best way
// Maybe it should be calculated
// TODO ^^^
namespace boardSettings
{
	// Width and height are in tiles units
	constexpr int32_t boardWidth = 14;
	constexpr int32_t boardHeight = 9;
};

namespace snakeSettings
{
	constexpr float moveInterval = 0.15f;
};

class GameScene:public Scene
{
private:
	Board board;
	Snake snake;
	Logic logic;
	InputWindow inputWindow;
	std::pair<int32_t, int32_t> cherryCoords;

	int32_t pointsCount;

	// Buttons
	TextButton returnMainMenu;

	mutable sf::Text scoreString;

	virtual sceneID eventLoop() override;
	inline void drawBoard() const;
	inline void drawSnake() const;
	inline void drawCherry() const;
	inline void drawScore() const;

	// Calls all methods that draws elements every game frame
	inline void renderGameTick() const;

	inline void updateScoreString() const;

	// Initializing helpers
	inline void initializeBoard();
	inline void initializeSnake();
	inline void initializeButtons();
	inline void initializeLabels();
	inline void initializeInputWindow();

	/* Helpers for handling mouse events 
	 *
	 * Takes event as argument
	 * Returns id of scene if mouse event caused 
	 * scene switch. If scene shouldnt be switched
	 * sceneID::none is returned
	 *
	 * */
	void handleMouseHovers(const sf::Event &mev);
	sceneID handleMouseReleased(const sf::Event &mev);
	sceneID handleKeyPressed(const sf::Event &kev);
	void handleTextEntered(const sf::Event &kev);
public:
	explicit GameScene
	(const std::shared_ptr<sf::RenderWindow> &wnd);

	virtual sceneID switchScene() override;

	friend class Logic;
};

#endif // GAMESCENE_H
