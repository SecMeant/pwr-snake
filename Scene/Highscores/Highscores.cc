#include "Highscores.hpp"

Highscores::Highscores
(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd){puts("Creating highscores");}

sceneID Highscores::switchScene()	
{
	puts("Switching to Highscores");
	this->background.assetPath = "./assets/default-background.png";
	this->initializeBackground();

	// TODO
	// some restoring actions
	
	return this->eventLoop();
}

sceneID Highscores::eventLoop()
{
	while (this->parentWindow->isOpen())
	{
		sf::Event event;
		while (this->parentWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->parentWindow->close();
			
			if (event.type == sf::Event::MouseButtonPressed)
				return {sceneID::gamescene};
			// TODO event handling
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->display();
	}
	return {sceneID::none};
}
