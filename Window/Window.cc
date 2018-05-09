#include "Window.hpp"

Window::Window()
:active(false)
{
	this->initializeText(header);
	this->header.setPosition({260,200});
	this->header.setString
		("Nice ! Thats a score worth remembering.");

	this->background.setFillColor({0x33,0x6b,0x87});
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
	text.setColor({0x0,0x0,0x0});
	text.setCharacterSize(12);
}
