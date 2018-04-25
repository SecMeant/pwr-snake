#ifndef MAINMENU_H
#define MAINMENU_H

#include "../Scene.hpp"

#include "../../utility/complexTypes.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <string>

class MainMenu: public Scene
{
private:
	Button highscoresButton;
	Button startgameButton;

	virtual sceneID eventLoop() override;
	inline void initializeButtons();

	/* Helpers for handling mouse events 
	 *
	 * Takes event as argument
	 * Returns id of scene if mouse event caused 
	 * scene switch. If scene shouldnt be switched
	 * sceneID::none is returned
	 *
	 * */
	inline sceneID handleMousePressed(const sf::Event &mev);
	inline sceneID handleMouseReleased(const sf::Event &mev);
public:
	explicit MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd);

	virtual sceneID switchScene() override;
};

#endif // MAINMENU_H
