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
	this->loadScoresFromFile();	
}

sceneID Highscores::switchScene()	
{
	puts("Switching to Highscores");
	entryType test = {"Holz","1337"};
	this->orderedInsert(test);
	this->logScores();

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

void Highscores::loadScoresFromFile
(const char *filename)
{
	std::ifstream scoresfile;
	std::string tableEntry;
	std::string score;
	entryType entry;

	scoresfile.open(filename);
	if(scoresfile.is_open())
	{
		this->highscoresTable.clear();
		while(getline(scoresfile, tableEntry, ' '))
		{
			getline(scoresfile, score);
			entry = {tableEntry, score};
			this->orderedInsert(entry);
		}
	}
	else printf("Error. Unable to open file %s.",filename);
}

void Highscores::drawScoreBoard()
{
	this->drawHeader();
	this->drawScoreBoardEntries(10);
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

	tmp.setFont(TextureManager::mushyLove);
	tmp.setCharacterSize(24);
	tmp.setColor(color);
	tmp.setPosition(scoreBoardSettings::nameOffset,currOffset);

	for(auto entry:this->highscoresTable)
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

void Highscores::debug_print_scores()
{
	for(auto i:highscoresTable)
	{
		printf("%s %s\n",
				std::get<0>(i).c_str(), std::get<1>(i).c_str());
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


void Highscores::orderedInsert(const entryType &entry)
{
	int val = std::stoi(std::get<1>(entry));
	auto it = this->highscoresTable.begin();
	auto itend = this->highscoresTable.end();

	if(this->highscoresTable.size() == 0)
	{
		this->highscoresTable.push_back(entry);
		return;
	}

	while(it != itend)
	{
		if(std::stoi(std::get<1>(*it)) <= val)
		{
			this->highscoresTable.insert(it,entry);
			return;
		}
		++it;
	}
	this->highscoresTable.push_back(entry);
}

void Highscores::addScore(const entryType &entry)
{
	this->orderedInsert(entry);
	this->logScores();
}

void Highscores::logScores(const char *filename)
{
	std::ofstream outFile;
	outFile.open(filename);
	if(not outFile.is_open())
	{
		puts("Error while saving scores. Cannot open file.");
		return;
	}

	for(auto entry:this->highscoresTable)
	{
		outFile << std::get<0>(entry) << " " << std::get<1>(entry) << '\n';
	}
}

#ifdef setColor
#undef setColor
#endif // setColor
