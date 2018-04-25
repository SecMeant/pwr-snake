#include "Board.hpp"

Board::Board(int32_t w, int32_t h)
:width(w), height(h)
{this->tiles.resize(w*h);}

void Board::resize(int32_t w, int32_t h)
{
	if(w <= 0 || h <= 0)
	{
		puts("Cannot resize board to zero or negative span");
		return;
	}

	this->width = w;
	this->height = h;
	this->tiles.resize(w*h);
}

