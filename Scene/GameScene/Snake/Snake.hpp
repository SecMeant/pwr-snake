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
	typedef std::vector<coordType> bodyType; 

private:
	// Holds X:Y as FIRST:SECOND of body parts of snake
	// CAUTION: LAST BODY PART IS INVISIBLE
	//          IT IS USED TO PROPERLY SPAWN NEW BODY PARTS
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

	inline std::vector<std::pair<int32_t, int32_t> >::const_iterator getBodyBegin() const
	{return this->body.cbegin();}

	inline std::vector<std::pair<int32_t, int32_t> >::const_iterator getBodyEnd() const
	{return --this->body.cend();}

	inline int32_t getBodySize() const  
	{return this->body.size();}

	// Returns direction to next body part of snake
	// relative to body part passed as iterator
	Direction getNextBodyDirection(bodyType::const_iterator part) const;

	// prints debug info
	void debug_info();
};

#endif // SNAKE_H
