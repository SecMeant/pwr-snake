#include "Snake.hpp"

Snake::Snake()
{
	body={{1,2},{3,4},{5,6}};
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
			++(this->body.at(0).second);
			break;
		case Direction::Down:
			--(this->body.at(0).second);
			break;
		case Direction::Left:
			--(this->body.at(0).first);
			break;
		case Direction::Right:
			++(this->body.at(0).first);
			break;
	}
}

void Snake::spawn(int32_t x, int32_t y)
{
	this->body={{x,y},{x,y-1},{x,y-2}};
}


