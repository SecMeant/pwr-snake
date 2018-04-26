#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <stdint.h>
#include <utility>

class Snake
{
	// Holds X:Y as FIRST:SECOND of body parts of snake
	std::vector<std::pair<int32_t,int32_t> > body;
};

#endif // SNAKE_H
