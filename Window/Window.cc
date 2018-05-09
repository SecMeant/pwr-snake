#include "Window.hpp"

Window::Window()
:active(false)
{
	this->initializeText(header);
	this->header.setPosition({260,200});
	this->header.setString
		("Nice ! Thats a score worth remembering.");

	this->background.setFillColor({0xff,0,0});
	this->background.setPosition(250,200);
	this->background.setSize({300,200});
}

void Window::draw(sf::RenderWindow &wnd) const
{
	wnd.draw(this->background);
	wnd.draw(this->header);
}

void Window::initializeText(sf::Text &text)
{
	text.setFont(TextureManager::mushyLove);
	text.setFillColor({0xff,0xff,0});
	text.setString("Sample text");
	text.setCharacterSize(12);
}
