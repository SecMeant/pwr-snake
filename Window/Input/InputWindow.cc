#include "InputWindow.hpp"

InputWindow::InputWindow()
{
	this->initializeText(this->textInside);
	this->textInside.setPosition({280,250});
	this->textInside.setString("Enter your name and press enter ");
	this->initializeText(this->input);
	this->input.setPosition({280,300});
	this->input.setCharacterSize(18);
	this->input.setFillColor({0x00,0x00,0x00});

	this->inputBackground.setFillColor({0x90,0xaf,0xc5});
	this->inputBackground.setSize({300,50});
	this->inputBackground.setPosition({250,280});
}

void InputWindow::setRelativeToFrame()
{
	this->textInside.setPosition({300,200});
	this->input.setPosition({300,250});
	this->inputBackground.setPosition({250,250});
}

void InputWindow::draw(sf::RenderWindow &wnd) const
{
	this->Window::draw(wnd);
	wnd.draw(this->inputBackground);
	wnd.draw(this->input);
	wnd.draw(this->textInside);
}

