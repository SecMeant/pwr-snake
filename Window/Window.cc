#include "Window.hpp"

void Window::draw(sf::RenderWindow &wnd)
{
	this->background.setPosition(200,200);
	this->background.setSize({300,200});
	this->header.setPosition(250,200);
	wnd.draw(this->background);
}
