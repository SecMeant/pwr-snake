#include "Highscores.hpp"

#ifdef _WIN32
#define setColor(arg) setFillColor(arg)
#endif // _WIN32

Highscores::Highscores
(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating highscores");
	this->background.assetPath = TextureManager::highscoresBackgroundTexPath;
	this->initializeBackground();
	this->initializeButtons();
	this->initializeHeader();
}

sceneID Highscores::switchScene()	
{
	puts("Switching to Highscores");
	saveManager.loadScoresFromFile();

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

			// TODO event handlingstd::get<0>(entry).c_str()
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->draw(this->returnButton.sprite);
		this->drawScoreBoard();
		this->parentWindow->display();
	}
	return {sceneID::none};
}

void Highscores::initializeButtons()
{
	/* SETTING TEXTURES */
	this->returnButton.loadTextures
	(&TextureManager::blueSliderLeftTex);

	/* SETTING POSITIONS */
	this->returnButton.sprite.setPosition(700,500);
}

void Highscores::drawScoreBoard()
{
	this->drawHeader();
	this->drawScoreBoardEntries(12);
}

void Highscores::drawHeader()
{
	this->parentWindow->draw(this->header.background);
	this->parentWindow->draw(this->header.text);
}

void Highscores::drawScoreBoardEntries
(int numberOfEntries)
{
	float currOffset = scoreBoardSettings::headerHeight;
	      currOffset += scoreBoardSettings::topmargin;
	int32_t i = 1;
	sf::Text tmp;
	sf::Color color(226,184,26);
	SaveManager::sBoardType highscoresTable;
	highscoresTable = saveManager.getBoard();

	tmp.setFont(TextureManager::mushyLove);
	tmp.setCharacterSize(24);
	tmp.setColor(color);
	tmp.setPosition(scoreBoardSettings::nameOffset,currOffset);

	for(auto entry:highscoresTable)
	{
		if(i >= numberOfEntries)
			break;

		tmp.setString(std::get<0>(entry).c_str());
		this->parentWindow->draw(tmp);

		tmp.setPosition(scoreBoardSettings::scoreOffset,currOffset);
		tmp.setString(std::get<1>(entry).c_str());
		this->parentWindow->draw(tmp);

		currOffset += scoreBoardSettings::topmargin;
		tmp.setPosition(scoreBoardSettings::nameOffset,currOffset);
		i++;
	}
}

void Highscores::initializeHeader()
{
	sf::Color textColor;
	sf::Color backgroundColor;

	textColor.r = 226;
	textColor.g = 184;
	textColor.b = 46;

	backgroundColor.r = 35;
	backgroundColor.g = 34;
	backgroundColor.b = 50;

	this->header.text.setFont(TextureManager::mushyLove);
	this->header.text.setString(scoreBoardSettings::headerText);
	this->header.setPosition
		(scoreBoardSettings::headerOffsetx,
		 scoreBoardSettings::headerOffsety);
	this->header.text.setColor(textColor);
	this->header.text.setCharacterSize(64);
	this->header.background.setColor(backgroundColor);
	this->header.background.setSize
		({scoreBoardSettings::headerWidth,
		 scoreBoardSettings::headerHeight});
}

#ifdef setColor
#undef setColor
#endif // setColor
