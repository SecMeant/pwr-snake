#ifndef LOGIC_H
#define LOGIC_H

#include "../Board/Board.hpp"
#include "../Snake/Snake.hpp"

class Logic
{
public:
	// Checks if in current frame snake ate fruit
	// Returns true if snake is eating
	// false otherwise
	inline bool checkEating(const Board &board, const Snake &snake);

	// Checks if game is over
	inline bool gameOver(const Board &board, const Snake &snake);
};

#endif // LOGIC_H
