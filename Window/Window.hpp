#ifndef WINDOW_H
#define WINDOW_H

#include "../utility/stdshared.hpp"

#include <stdint.h>

class Window
{
public:
	sf::RectangleShape background;
	sf::Text header;

	void draw(sf::RenderWindow &wnd);

	explicit Window() = default;
};

#endif // WINDOW_H
