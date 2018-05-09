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
	auto tmp = *(this->body.cend()-1);
	this->body.push_back(std::move(tmp));
}

Direction Snake::getNextBodyDirection(Snake::bodyType::const_iterator part) const
{
	Snake::coordType diff;

	if(part == this->getBodyBegin())
		return Direction::None;

	diff = *part;
	++part;
	diff.first = part->first - diff.first;
	diff.second = part->second - diff.second;

	if(diff.first == 1)
		return Direction::Right;
	if(diff.first == -1)
		return Direction::Left;
	if(diff.second == 1)
		return Direction::Down;
	if(diff.second == -1)
		return Direction::Up;

	return Direction::None;
}

Direction Snake::getPrevBodyDirection(Snake::bodyType::const_iterator part) const
{
	Snake::coordType diff;

	if(part == this->getBodyBegin())
		return Direction::None;

	diff = *part;
	--part;
	diff.first = part->first - diff.first;
	diff.second = part->second - diff.second;

	if(diff.first == 1)
		return Direction::Right;
	if(diff.first == -1)
		return Direction::Left;
	if(diff.second == 1)
		return Direction::Down;
	if(diff.second == -1)
		return Direction::Up;

	return Direction::None;
}

Turn Snake::checkTurn(Snake::bodyType::const_iterator part) const
{
	Direction n,p;

	n = this->getNextBodyDirection(part);
	p = this->getPrevBodyDirection(part);

	if(p == Direction::Left && n == Direction::Right)
		return Turn::HS;
	if(p == Direction::Right && n == Direction::Left)
		return Turn::HS;

	if(p == Direction::Up && n == Direction::Down)
		return Turn::VS;
	if(p == Direction::Down && n == Direction::Up)
		return Turn::VS;

	if(p == Direction::Up && n == Direction::Right)
		return Turn::UR;
	if(p == Direction::Right && n == Direction::Up)
		return Turn::UR;

	if(p == Direction::Left && n == Direction::Down)
		return Turn::LD;
	if(p == Direction::Down && n == Direction::Left)
		return Turn::LD;

	if(p == Direction::Left && n == Direction::Up)
		return Turn::LU;
	if(p == Direction::Up && n == Direction::Left)
		return Turn::LU;

	if(p == Direction::Down && n == Direction::Right)
		return Turn::DR;
	if(p == Direction::Right && n == Direction::Down)
		return Turn::DR;

	return Turn::None;
}

void Snake::debug_info()
{
	for(auto i:this->body)
	{
		printf("{%i,%i};",i.first,i.second);
	}
	putchar('\n');
}
