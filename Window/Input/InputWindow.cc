#include "InputWindow.hpp"

InputWindow::InputWindow()
{
	this->textInside.setString("Your name");
	this->inputBackground.setFillColor({0xff,0,0});
	this->inputBackground.setSize({300,50});
	this->inputBackground.setPosition({250,200});
}

void InputWindow::setRelativeToFrame()
{
	this->textInside.setPosition({300,200});
	this->input.setPosition({300,250});
	this->inputBackground.setPosition({250,250});
}

void InputWindow::draw(sf::RenderWindow &wnd)
{
	this->Window::draw(wnd);
	wnd.draw(this->inputBackground);
	wnd.draw(this->input);
	wnd.draw(this->textInside);
}

