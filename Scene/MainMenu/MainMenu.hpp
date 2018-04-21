#ifndef MAINMENU_H
#define MAINMENU_H

#include "../Scene.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

struct renderObject
{
	sf::Texture texture;
	sf::RectangleShape shape;
};

class MainMenu: public Scene
{
private:
	renderObject background;

	inline void initializeBackground();
	inline void eventLoop();
public:
	explicit MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd);

	virtual void switchScene() override;
};

#endif // MAINMENU_H
