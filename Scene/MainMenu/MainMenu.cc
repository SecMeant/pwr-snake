#include "MainMenu.hpp"

#ifdef _WIN32
#define setColor(arg) setFillColor(arg)
#endif // _WIN32

MainMenu::MainMenu(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating main menu");
	this->background.assetPath = TextureManager::brickBackgroundTexPath;
	this->initializeBackground();
	this->initilizeFreeSprites();
	this->initializeButtons();
	this->initializeHeader();
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
			
			if(event.type == sf::Event::MouseButtonReleased)
			{
				if(this->handleMouseReleased(event) != sceneID::none)
					return this->handleMouseReleased(event);
			}

			if(event.type == sf::Event::MouseMoved)
			{
				this->handleMouseHovers(event);
			}
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->draw(this->header.text);
		this->parentWindow->draw(this->pypy);
		this->parentWindow->draw(this->highscoresButton.text);
		this->parentWindow->draw(this->startgameButton.text);
		this->parentWindow->display();
	}
	return {sceneID::none};
}

void MainMenu::initializeButtons()
{
	constexpr int defStringSize = 32;
	sf::Color deftextColor{0x46,0x21,0x1a};
	sf::Color hovertextColor{0xa4,0x38,0x20};
	/* SETTING LOOKS */
	this->highscoresButton.setColors
	(deftextColor,hovertextColor);
	this->highscoresButton.text.setFont(TextureManager::mushyLove);
	this->highscoresButton.text.setString("HIGHSCORES");
	this->highscoresButton.text.setCharacterSize(defStringSize);
	
	/* SETTING LOOKS */
	this->startgameButton.setColors
	(deftextColor,hovertextColor);
	this->startgameButton.text.setFont(TextureManager::mushyLove);
	this->startgameButton.text.setString("START GAME");
	this->startgameButton.text.setCharacterSize(defStringSize);
	
	/* SETTING POSITIONS */
	this->startgameButton.text.setPosition(50,450);
	this->highscoresButton.text.setPosition(50,500);
}

void MainMenu::initializeHeader()
{
	sf::Color textColor{0xfb,0x65,0x42};

	this->header.text.setFont(TextureManager::mushyLove);
	this->header.text.setString("Snake Game");
	this->header.setPosition
		(scoreBoardSettings::headerOffsetx,
		 scoreBoardSettings::headerOffsety);
	this->header.text.setColor(textColor);
	this->header.text.setCharacterSize(64);
}

void MainMenu::initilizeFreeSprites()
{
	this->pypy.setTexture(TextureManager::pypyTex, true);
	this->pypy.setPosition(250,150);
}

sceneID MainMenu::handleMouseReleased(const sf::Event &mev)
{
	sceneID ret = sceneID::none;

	if(this->startgameButton.clicked(mev))
		ret = sceneID::gamescene;

	else if(this->highscoresButton.clicked(mev))
		ret = sceneID::highscores;

	return ret;
}

void MainMenu::handleMouseHovers(const sf::Event &mev)
{
	this->startgameButton.handleHoverEvent(mev);
	this->highscoresButton.handleHoverEvent(mev);
}

sceneID MainMenu::switchScene()
{
	puts("Switching to MainMenu");

	// TODO
	// Some returning animation ?

	return this->eventLoop();
}

#ifdef setColor
#undef setColor
#endif // setColor
