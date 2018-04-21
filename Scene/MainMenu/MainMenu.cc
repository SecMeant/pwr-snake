#include "MainMenu.hpp"

MainMenu::MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating main menu");
	this->initializeBackground();
}

void MainMenu::initializeBackground()
{
	this->background.texture.loadFromFile("./assets/mainmenutex.png");
	this->background.shape.setSize(sf::Vector2f(800,600));
	this->background.shape.setPosition(0,0);
	this->background.shape.setTexture(&this->background.texture);
}

inline void MainMenu::eventLoop()
{
	while (this->parentWindow->isOpen())
	{
		sf::Event event;
		while (this->parentWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->parentWindow->close();
			
			// TODO event handling
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->display();
	}
}

void MainMenu::switchScene()
{
	puts("Switching to MainMenu");

	// TODO
	// Some returning animation ?

	this->eventLoop();
}
