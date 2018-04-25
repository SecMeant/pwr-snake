#include "Highscores.hpp"

Highscores::Highscores
(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd){puts("Creating highscores");}

sceneID Highscores::switchScene()	
{
	puts("Switching to Highscores");
	this->background.assetPath = "./assets/highscores.png";
	this->initializeBackground();
	this->initializeButtons();

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
			
			if (event.type == sf::Event::MouseButtonReleased)
			{
				auto mousex = event.mouseButton.x;
				auto mousey = event.mouseButton.y;

				if(this->returnButton.sprite.getGlobalBounds().contains(mousex, mousey))
				{
					return {sceneID::mainmenu};
				}
			}

			// TODO event handling
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->draw(this->returnButton.sprite);
		this->parentWindow->display();
	}
	return {sceneID::none};
}

void Highscores::initializeButtons()
{
	/* SETTING TEXTURES */
	this->returnButton.loadTextures("./assets/blue_sliderLeft.png");

	/* SETTING POSITIONS */
	this->returnButton.sprite.setPosition(700,500);
}
