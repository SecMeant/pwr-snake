#include "Logic.hpp"
#include "../GameScene.hpp"

Logic::Logic(GameScene *p, float mvInt)
:parent(p), moveInterval(mvInt){}

bool Logic::isMoveInBoundary(Direction d) const
{
	auto snakesHead = this->parent->snake.getBodyBegin();

	switch(d)
	{
		case Direction::Up:
			if(snakesHead->second == 0)
				return false;
			return true;
		case Direction::Down:
			if(snakesHead->second >= parent->board.height-1)
				return false;
			return true;
		case Direction::Right:
			if(snakesHead->first >= parent->board.width-1)
				return false;
			return true;
		case Direction::Left:
			if(snakesHead->first == 0)
				return false;
			return true;
	}

	return false;
}

bool Logic::isSnakeSelfeating()
{
	auto head = this->parent->snake.getBodyBegin();
	auto it = head;
	auto itend = this->parent->snake.getBodyEnd();
	++it;
	while(it != itend)
	{
		if(head == it)
			return true;
	}
	return false;
}

void Logic::intervalMove()
{
	static auto lastCheck = std::chrono::system_clock::now();
	std::chrono::duration<float>diff;
	
	diff = std::chrono::system_clock::now() - lastCheck;
	if(diff.count() >= this->moveInterval)
	{
		this->parent->snake.move();
		lastCheck = std::chrono::system_clock::now();
	}
}
