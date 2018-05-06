#include "complexTypes.hpp"

bool TextButton::clicked(const sf::Event &ev)
{
	auto mousex = ev.mouseButton.x;
	auto mousey = ev.mouseButton.y;

	if(ev.type == sf::Event::MouseButtonReleased)
	{
		return this->text.getGlobalBounds().contains(mousex, mousey);
	}
	return false;
}
