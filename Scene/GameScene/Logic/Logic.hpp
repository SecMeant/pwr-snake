#ifndef LOGIC_H
#define LOGIC_H

#include "../../../utility/stdshared.hpp"

#include "../Board/Board.hpp"
#include "../Snake/Snake.hpp"

#include <chrono>

class GameScene;

class Logic
{
private:
	GameScene * const parent;
	const float moveInterval;

public:
	explicit Logic(GameScene *parent,float mvInt);

	// Checks if in current frame snake ate fruit
	// Returns true if snake is eating
	// false otherwise
	inline bool checkEating(const Board &board, const Snake &snake) const;

	// Checks if game is over
	inline bool gameOver(const Board &board, const Snake &snake) const;

	// Checks if snakes move is safe.
	// If it is not safe snakes hits a wall
	// Therefore false is returned.
	// True otherwise
	bool isMoveInBoundary(Direction d) const;

	bool isSnakeSelfeating();

	// Moves snake in its current
	// direction if time since last move passed
	// this->moveInterval.
	void intervalMove();
};

#endif // LOGIC_H
