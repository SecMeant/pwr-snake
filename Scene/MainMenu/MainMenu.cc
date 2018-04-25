#include "MainMenu.hpp"

MainMenu::MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating main menu");
	this->background.assetPath = "./assets/default-background.png";
	this->initializeBackground();
	this->initializeButtons();
}

sceneID MainMenu::eventLoop()
{
	while(this->parentWindow->isOpen())
	{
		sf::Event event;
		while(this->parentWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->parentWindow->close();
			
			if (event.type == sf::Event::MouseButtonPressed)
			{
				auto mousex = event.mouseButton.x;
				auto mousey = event.mouseButton.y;

				if(this->startgameButton.sprite.getGlobalBounds().contains(mousex, mousey))
				{
					return {sceneID::gamescene};
				}

				if(this->highscoresButton.sprite.getGlobalBounds().contains(mousex, mousey))
				{
					return {sceneID::highscores};
				}
			}

			// TODO event handling
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->draw(this->highscoresButton.sprite);
		this->parentWindow->draw(this->startgameButton.sprite);
		this->parentWindow->display();
	}
	return {sceneID::none};
}

void MainMenu::initializeButtons()
{
	/* SETTING TEXTURES */
	this->highscoresButton.loadTextures
		("./assets/blue_button_down.png",
		 "./assets/blue_button_up.png");

	this->startgameButton.loadTextures
		("./assets/green_button_down.png",
		 "./assets/yellow_button_up.png");


	/* SETTING POSITIONS */
	this->highscoresButton.sprite.setPosition(200,500);
	this->startgameButton.sprite.setPosition(280,500);
}

sceneID MainMenu::switchScene()
{
	puts("Switching to MainMenu");

	// TODO
	// Some returning animation ?

	return this->eventLoop();
}
