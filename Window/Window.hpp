#ifndef WINDOW_H
#define WINDOW_H

#include "../utility/stdshared.hpp"

#include <stdint.h>

class Window
{
public:
	sf::RectangleShape background;
	sf::Text header;

	// True if window is active and events
	// should affect it.
	// False otherwise.
	mutable bool active;

	void draw(sf::RenderWindow &wnd) const;
	void initializeText(sf::Text &text);

	explicit Window();
};

#endif // WINDOW_H
