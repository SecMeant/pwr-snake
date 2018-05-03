#include "Snake.hpp"

Snake::Snake()
:movementDirection(Direction::Down), lastMovementDirection(Direction::Down)
{
	this->spawn(0,2);
}

void Snake::move(Direction d)
{
	if(body.size() == 0)
		return;

	std::vector<std::pair<int32_t, int32_t> >::reverse_iterator rit = this->body.rbegin();
	std::vector<std::pair<int32_t, int32_t> >::reverse_iterator ritend = this->body.rend();
	++rit;

	while(rit != ritend)
	{
		*(rit-1) = *rit;
		++rit;
	}

	switch(d)
	{
		case Direction::Up:
			--(this->body.at(0).second);
			break;
		case Direction::Down:
			++(this->body.at(0).second);
			break;
		case Direction::Left:
			--(this->body.at(0).first);
			break;
		case Direction::Right:
			++(this->body.at(0).first);
			break;
		default:
			break;
	}

	this->lastMovementDirection = d;
}

void Snake::move()
{
	this->move(this->movementDirection);
}

void Snake::spawn(int32_t x, int32_t y)
{
	this->movementDirection = Direction::Down;
	this->lastMovementDirection = Direction::Down;
	this->body={{x,y},{x,y-1},{x,y-2},
		          {x,y-3}/*invisible part*/};
}

void Snake::addBodyPart()
{
	this->body.push_back(*(this->body.cend()--));
}

void Snake::debug_info()
{
	for(auto i:this->body)
	{
		printf("{%i,%i};",i.first,i.second);
	}
	putchar('\n');
}
