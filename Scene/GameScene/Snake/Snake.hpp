#ifndef SNAKE_H
#define SNAKE_H

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

};

#endif // SNAKE_H
