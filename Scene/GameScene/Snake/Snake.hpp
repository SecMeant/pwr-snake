#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>

#include <vector>
#include <stdint.h>
#include <utility>

#include "../../../utility/stdshared.hpp"

class Snake
{
private:
	// Holds X:Y as FIRST:SECOND of body parts of snake
	std::vector<std::pair<int32_t,int32_t> > body;
	
	Direction movementDirection;
public:
	explicit Snake();

	void move(Direction d);

	// places snake at given x,y and 
	// makes its body length 3
	void spawn(int32_t x, int32_t y);

	inline std::vector<std::pair<int32_t, int32_t> >::const_iterator getBodyBegin()
	{return this->body.cbegin();}

	inline std::vector<std::pair<int32_t, int32_t> >::const_iterator getBodyEnd()
	{return this->body.cend();}

	// prints debug info
	void debug_info();
};

#endif // SNAKE_H
