#include "Highscores.hpp"

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
	this->returnButton.reset();

	return this->eventLoop();
}

sceneID Highscores::eventLoop()
{
	while (this->parentWindow->isOpen())
	{
		sf::Event event;
		while (this->parentWindow->pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				this->parentWindow->close();
			
			if(this->returnButton.clicked(event))
				return {sceneID::mainmenu};

			this->returnButton.handleHoverEvent(event);
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->draw(this->returnButton.text);
		this->drawScoreBoard();
		this->parentWindow->display();
	}
	return {sceneID::none};
}

void Highscores::initializeButtons()
{
	/* SETTING LOOKS */
	this->returnButton.setColors
	({0x8d,0x23,0x0f},{0x9b,0x4f,0x0f});
	this->returnButton.text.setFont(TextureManager::mushyLove);
	this->returnButton.text.setString("Return");
	this->returnButton.text.setCharacterSize(18);

	/* SETTING POSITIONS */
	this->returnButton.text.setPosition(350,500);
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
	tmp.setFillColor(color);
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
	sf::Color textColor{226,184,46};
	sf::Color backgroundColor{35,34,50};

	this->header.text.setFont(TextureManager::mushyLove);
	this->header.text.setString(scoreBoardSettings::headerText);
	this->header.setPosition
		(scoreBoardSettings::headerOffsetx,
		 scoreBoardSettings::headerOffsety);
	this->header.text.setFillColor(textColor);
	this->header.text.setCharacterSize(64);
	this->header.background.setFillColor(backgroundColor);
	this->header.background.setSize
		({scoreBoardSettings::headerWidth,
		 scoreBoardSettings::headerHeight});
}

