#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include "SFML/Graphics.hpp"

enum class TileState
{none, cherry};

class Board
{
public:
	static constexpr float boardxOffset = 40;
	static constexpr float boardyOffset = 40;
	static constexpr float tileWidth = 40;
	static constexpr float tileHeight = 40;
	
	int32_t width;
	int32_t height;

	std::vector<TileState> tiles;

	Board(int32_t w, int32_t h);

	Board() = default;

	void resize(int32_t w, int32_t h);

	// returns element by 2 dimensional reference
	inline TileState get(int32_t x, int32_t y)
	{return this->tiles[y*this->width+x];}
};

#endif // BOARD_H
