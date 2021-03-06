#ifndef LOGIC_H
#define LOGIC_H

#include "../../../utility/stdshared.hpp"

#include "../Board/Board.hpp"
#include "../Snake/Snake.hpp"

#include <chrono>
#include <random>

class GameScene;

class Logic
{
public:
	// For highscores
	std::string playerName;

private:
	GameScene * const parent;
	const float moveInterval;
	GameState gameState;

	std::minstd_rand0 randGenerator;

	bool isTileSnakeFree(int32_t x, int32_t y) const;
public:
	explicit Logic(GameScene *parent,float mvInt);

	// Checks if in current frame snake ate fruit
	// Returns true if snake is eating
	// false otherwise
	bool checkEating();

	// Checks if snakes move is safe.
	// If it is not safe snakes hits a wall
	// Therefore false is returned.
	// True otherwise
	bool isMoveInBoundary(Direction d) const;

	bool isSnakeSelfeating() const;

	// Randomly spawns cherry
	// on boards free spot
	void spawnCherry();

	// Sets gamestate to pending.
	// Over is set next time game over condition
	// is met in any condition checking method
	void resetGameState();
	inline GameState getGameState()const{return this->gameState;}

	// Moves snake in its current
	// direction if time since last move passed
	// this->moveInterval.
	void intervalMove();

	// Checks if snake isnt going in reverse
	bool isMoveValid();

	// returns reverse direction to given in arg
	Direction reverseDirection(Direction d);
};

#endif // LOGIC_H
