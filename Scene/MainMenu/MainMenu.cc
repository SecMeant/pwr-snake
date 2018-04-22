#include "MainMenu.hpp"

MainMenu::MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating main menu");
	this->background.assetPath = "./assets/mainmenutex.png";
	this->initializeBackground();
}

sceneID MainMenu::eventLoop()
{
	while (this->parentWindow->isOpen())
	{
		sf::Event event;
		while (this->parentWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->parentWindow->close();
			
			if (event.type == sf::Event::MouseButtonPressed)
				return {sceneID::highscores};

			// TODO event handling
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->display();
	}
	return {sceneID::none};
}

sceneID MainMenu::switchScene()
{
	puts("Switching to MainMenu");

	// TODO
	// Some returning animation ?

	return this->eventLoop();
}
