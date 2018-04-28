#include "GameScene.hpp"

GameScene::GameScene
(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd)
{
	puts("Creating game scene");
	this->background.assetPath = TextureManager::brickBackgroundTexPath;
	this->initializeBackground();
	this->initializeBoard();
	this->initializeButtons();
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
		this->parentWindow->draw(this->returnMainMenu.sprite);
		this->drawBoard();
		this->parentWindow->display();
	}
	return {sceneID::none};
}

void GameScene::initializeBoard()
{
	this->board.resize
	(boardSettings::boardWidth,boardSettings::boardHeight);
}

void GameScene::initializeButtons()
{
	/* SETIING TEXTURES */
	this->returnMainMenu.loadTextures
	(&TextureManager::redButtonDownTex,
	 &TextureManager::redButtonUpTex);

	/* SETTING POSITIONS */
	this->returnMainMenu.sprite.setPosition(500, 530);
}

sceneID GameScene::handleMousePressed(const sf::Event &mev)
{
	auto mousex = mev.mouseButton.x;
	auto mousey = mev.mouseButton.y;

	if(this->returnMainMenu.sprite.getGlobalBounds().contains(mousex, mousey))
	{
		this->returnMainMenu.press();
	}

	return {sceneID::none};
}

sceneID GameScene::handleMouseReleased(const sf::Event &mev)
{
	auto mousex = mev.mouseButton.x;
	auto mousey = mev.mouseButton.y;
	sceneID ret = sceneID::none;

	if(this->returnMainMenu.sprite.getGlobalBounds().contains(mousex, mousey))
	{
		ret = sceneID::mainmenu;
	}

	this->returnMainMenu.release();
	return ret;
}

void GameScene::drawBoard()
{
	// current pixel offset
	float currx = Board::boardxOffset;
	float curry = Board::boardyOffset;

	int32_t wrapCounter = 0;

	sf::RectangleShape tile;
	tile.setTexture(&TextureManager::tileTexture, true);
	tile.setSize(sf::Vector2f(Board::tileWidth,Board::tileHeight));

	for(auto i:this->board.tiles)
	{
		++wrapCounter;

		tile.setPosition(currx, curry);
		this->parentWindow->draw(tile);
		
		if(i==TileState::cherry)
		{
			tile.setTexture(&TextureManager::cherryTexture, true);
			this->parentWindow->draw(tile);
			tile.setTexture(&TextureManager::tileTexture, true);
		}

		currx += Board::tileWidth;
		if(wrapCounter == boardSettings::boardWidth)
		{
			currx = Board::boardxOffset;
			curry += Board::tileHeight;
			wrapCounter = 0;
		}
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
