#include "GameScene.hpp"

GameScene::GameScene
(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating game scene");
	this->background.assetPath = "./assets/default-background.png";
	this->initializeBackground();
	this->initializeBoard();
	this->loadTextures();
}

sceneID GameScene::eventLoop()
{
	while (this->parentWindow->isOpen())
	{
		sf::Event event;
		while (this->parentWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->parentWindow->close();
			
			if (event.type == sf::Event::MouseButtonPressed)
				return {sceneID::mainmenu};

			// TODO event handling
		}

		this->parentWindow->clear();
		this->parentWindow->draw(this->background.shape);
		this->drawBoard();
		this->parentWindow->display();
	}
	return {sceneID::none};
}

void GameScene::initializeBoard()
{
	this->board.resize(12,12);
}

void GameScene::loadTextures()
{
	this->tileTexture.loadFromFile(tileTexturePath);
	this->cherryTexture.loadFromFile(cherryTexturePath);
}

void GameScene::drawBoard()
{
	// current pixel offset
	float currx = Board::boardxOffset;
	float curry = Board::boardyOffset;

	int32_t wrapCounter = 0;

	sf::RectangleShape tile;
	tile.setTexture(&this->tileTexture, true);
	tile.setSize(sf::Vector2f(Board::tileWidth,Board::tileHeight));

	for(auto i:this->board.tiles)
	{
		tile.setPosition(currx, curry);
		printf("%f %f\n",currx, curry);
		this->parentWindow->draw(tile);
		
		if(i==TileState::cherry)
		{
			tile.setTexture(&this->cherryTexture, true);
			this->parentWindow->draw(tile);
			tile.setTexture(&this->tileTexture, true);
		}

		currx += Board::tileWidth;
		if(wrapCounter == 11)
		{
			currx = Board::boardxOffset;
			curry += Board::tileHeight;
			wrapCounter = 0;
		}
		++wrapCounter;
	}

	return;
}

sceneID GameScene::switchScene()
{
	puts("Switching to GameScene");

	// TODO
	// Some returning animation ?

	return this->eventLoop();
}
