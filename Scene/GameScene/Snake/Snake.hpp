#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>

#include <vector>
#include <stdint.h>
#include <utility>

#include "../../../utility/stdshared.hpp"

#include "../Board/Board.hpp"

class Snake
{
public:
	typedef std::pair<int32_t, int32_t> coordType;
	typedef std::list<Direction> bodyType; 

private:
	// Holds XY of snakes head
	std::pair<int32_t, int32_t> head;

	// Each body part holds direction
	// of previous body part
	bodyType body;

public:
	Direction movementDirection;

	// Holds value of last movement direction
	Direction lastMovementDirection;
	
	explicit Snake();

	// Moves in direction d
	void move(Direction d);

	// Moves in current direction
	void move();

	// places snake at given x,y and 
	// makes its body length 3
	void spawn(int32_t x, int32_t y);

	void addBodyPart();	

	inline int32_t getBodySize() const  
	{return this->body.size();}
};

#endif // SNAKE_H



// d d d r r r u u
/*
 * x
 * x     o
 * x     x
 * x x x x
 *
 * */


// d d r r r u u u
/*
 *       o
 * x     x
 * x     x
 * x x x x
 *
 * */

