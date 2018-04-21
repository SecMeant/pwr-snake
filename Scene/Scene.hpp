#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

#include <memory>

class Scene
{
protected:
	std::shared_ptr<sf::RenderWindow> parentWindow;

public:
	explicit Scene(const std::shared_ptr<sf::RenderWindow> &wnd)
		:parentWindow(wnd){puts("Creating scene");}

	virtual void switchScene() = 0;
};

#endif // SCENE_H
