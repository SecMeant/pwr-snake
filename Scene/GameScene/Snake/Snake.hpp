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
private:
	// Holds X:Y as FIRST:SECOND of body parts of snake
	// CAUTION: LAST BODY PART IS INVISIBLE
	//          IT IS USED TO PROPERLY SPAWN NEW BODY PARTS
	std::vector<std::pair<int32_t,int32_t> > body;
public:
	Direction movementDirection;
	
	explicit Snake();

	// Moves in direction d
	void move(Direction d);

	// Moves in current direction
	void move();

	// places snake at given x,y and 
	// makes its body length 3
	void spawn(int32_t x, int32_t y);

	void addBodyPart();	

	inline std::vector<std::pair<int32_t, int32_t> >::const_iterator getBodyBegin() const
	{return this->body.cbegin();}

	inline std::vector<std::pair<int32_t, int32_t> >::const_iterator getBodyEnd() const
	{return --this->body.cend();}

	// prints debug info
	void debug_info();
};

#endif // SNAKE_H
