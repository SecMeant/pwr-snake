#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include "../Window.hpp"

#include "../../utility/stdshared.hpp"

class InputWindow:public Window
{
public:
	sf::Text textInside;
	sf::Text input;
	sf::RectangleShape inputBackground;

	void draw(sf::RenderWindow &wnd);
	void setRelativeToFrame();

	explicit InputWindow();
};

#endif // INPUTWINDOW_H
