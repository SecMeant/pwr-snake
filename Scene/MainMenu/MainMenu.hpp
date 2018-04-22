#ifndef MAINMENU_H
#define MAINMENU_H

#include "../Scene.hpp"

#include "../../utility/complexTypes.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

class MainMenu: public Scene
{
private:
	virtual sceneID eventLoop() override;

public:
	explicit MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd);

	virtual sceneID switchScene() override;
};

#endif // MAINMENU_H
