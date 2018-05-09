#include "Logic.hpp"
#include "../GameScene.hpp"

Logic::Logic(GameScene *p, float mvInt)
:parent(p), moveInterval(mvInt), gameState(GameState::Over){}

bool Logic::isTileSnakeFree(int32_t x, int32_t y) const
{
	auto it = this->parent->snake.getBodyBegin();
	auto itend = this->parent->snake.getBodyEnd();
	while(it != itend)
	{
		if(x == it->first && y == it->second)
			return false;
		++it;
	}
	return true;
}

bool Logic::checkEating()
{
	if(*(this->parent->snake.getBodyBegin()) == this->parent->cherryCoords)
	{
		this->parent->pointsCount++;
		this->parent->snake.addBodyPart();
		this->spawnCherry();
		return true;
	}

	return false;
}

bool Logic::isMoveInBoundary(Direction d) const
{
	auto snakesHead = this->parent->snake.getBodyBegin();

	switch(d)
	{
		case Direction::Up:
			if(snakesHead->second <= 0)
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
			if(snakesHead->first <= 0)
				return false;
			return true;
		default:
			return true;
	}

	return false;
}

bool Logic::isSnakeSelfeating() const
{
	auto head = this->parent->snake.getBodyBegin();
	auto it = head;
	auto itend = this->parent->snake.getBodyEnd();
	++it;
	while(it != itend)
	{
		if((head->first == it->first) && (head->second == it->second))
			return true;
		++it;
	}
	return false;
}

void Logic::spawnCherry()
{
	int32_t x,y;

	// Infinite loop below if i dont check that
	if(this->parent->snake.getBodySize() ==
		 this->parent->board.width * this->parent->board.height)
	{
		return;
	}

	do
	{
		x = this->randGenerator() % this->parent->board.width;
		y = this->randGenerator() % this->parent->board.height;
	}while(!this->isTileSnakeFree(x,y));

	this->parent->cherryCoords = {x,y};
}

void Logic::resetGameState()
{
	this->gameState = GameState::Pending;
	this->parent->pointsCount = 0;

	// Reset random generator
	this->randGenerator.seed
		(std::chrono::system_clock::now().time_since_epoch().count());
}

void Logic::intervalMove()
{
	static auto lastCheck = std::chrono::system_clock::now();
	std::chrono::duration<float>diff;
	
	diff = std::chrono::system_clock::now() - lastCheck;
	if(diff.count() >= this->moveInterval)
	{
		if(!this->isMoveInBoundary(this->parent->snake.movementDirection) ||
			 this->isSnakeSelfeating())
		{
			this->gameState = GameState::Over;
			printf("GameOver!\nScore:%i\n",this->parent->pointsCount);
			return;
		}

		if(!this->isMoveValid())
		{
			this->parent->snake.movementDirection =
			this->parent->snake.lastMovementDirection;
		}

		this->parent->snake.move();

		lastCheck = std::chrono::system_clock::now();
	}
}

bool Logic::isMoveValid()
{
	auto revMove = reverseDirection(this->parent->snake.movementDirection);
	if(revMove == this->parent->snake.lastMovementDirection)
		return false;
	return true;
}

Direction Logic::reverseDirection(Direction d)
{
	if(d == Direction::Up)
		return Direction::Down;

	if(d == Direction::Down)
		return Direction::Up;

	if(d == Direction::Left)
		return Direction::Right;

	return Direction::Left;

}
