#include "MainMenu.hpp"

MainMenu::MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating main menu");
	this->background.assetPath = TextureManager::brickBackgroundTexPath;
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
			
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(this->handleMousePressed(event) != sceneID::none)
					return this->handleMousePressed(event);
			}

			if(event.type == sf::Event::MouseButtonReleased)
			{
				if(this->handleMouseReleased(event) != sceneID::none)
					return this->handleMouseReleased(event);
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
		(&TextureManager::yellowButtonDownTex,
		 &TextureManager::yellowButtonUpTex);

	this->startgameButton.loadTextures
		(&TextureManager::blueButtonDownTex,
		 &TextureManager::blueButtonUpTex);


	/* SETTING POSITIONS */
	this->highscoresButton.sprite.setPosition(200,500);
	this->startgameButton.sprite.setPosition(480,500);
}

sceneID MainMenu::handleMousePressed(const sf::Event &mev)
{
	auto mousex = mev.mouseButton.x;
	auto mousey = mev.mouseButton.y;


	if(this->startgameButton.sprite.getGlobalBounds().contains(mousex, mousey))
	{
		this->startgameButton.press();
	}

	if(this->highscoresButton.sprite.getGlobalBounds().contains(mousex, mousey))
	{
		this->highscoresButton.press();
	}

	return {sceneID::none};
}

sceneID MainMenu::handleMouseReleased(const sf::Event &mev)
{
	auto mousex = mev.mouseButton.x;
	auto mousey = mev.mouseButton.y;
	sceneID ret = sceneID::none;

	if(this->startgameButton.sprite.getGlobalBounds().contains(mousex, mousey))
	{
		ret = sceneID::gamescene;
	}

	if(this->highscoresButton.sprite.getGlobalBounds().contains(mousex, mousey))
	{
		ret = sceneID::highscores;
	}

	this->highscoresButton.release();
	this->startgameButton.release();
	return ret;
}

sceneID MainMenu::switchScene()
{
	puts("Switching to MainMenu");

	// TODO
	// Some returning animation ?

	return this->eventLoop();
}
