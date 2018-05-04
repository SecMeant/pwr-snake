#include "GameScene.hpp"

GameScene::GameScene
(const std::shared_ptr<sf::RenderWindow> &wnd)
:Scene(wnd), board() /*initialized later*/, snake(),
 logic(this, snakeSettings::moveInterval), cherryCoords({0,0}),
 pointsCount(0)
{
	puts("Creating game scene");
	this->background.assetPath = TextureManager::brickBackgroundTexPath;
	this->initializeBackground();
	this->initializeBoard();
	this->initializeButtons();
	this->initializeLabels();
}

sceneID GameScene::eventLoop()
{
	this->logic.resetGameState();
	this->snake.spawn(0,2);
	this->logic.spawnCherry();

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
				continue;
			}

			if(event.type == sf::Event::MouseButtonReleased)
			{
				if(this->handleMouseReleased(event) != sceneID::none)
					return this->handleMouseReleased(event);
				continue;
			}

			if(event.type == sf::Event::KeyPressed)
			{
				this->handleKeyPressed(event);
				continue;
			}
		}

		if(this->logic.getGameState() == GameState::Pending)
			this->logic.intervalMove();

		this->logic.checkEating();
		this->parentWindow->clear();
		this->renderGameTick();
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

void GameScene::initializeLabels()
{
	this->updateScoreString();
	this->scoreString.setFont(TextureManager::defaultFont);
	this->scoreString.setCharacterSize(42);
	this->scoreString.setColor(sf::Color::White);
	this->scoreString.setPosition(50,530);
}

void GameScene::updateScoreString() const
{
	std::string labelString("Score: ");
	labelString += std::to_string(this->pointsCount);
	this->scoreString.setString(labelString.c_str());
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

void GameScene::handleKeyPressed(const sf::Event &kev)
{
	switch(kev.key.code)
	{
		case sf::Keyboard::Up:
			if(this->snake.movementDirection == Direction::Down)
				break;
			this->snake.movementDirection = Direction::Up;
			break;
		
		case sf::Keyboard::Down:
			if(this->snake.movementDirection == Direction::Up)
				break;
			this->snake.movementDirection = Direction::Down;
			break;
		
		case sf::Keyboard::Left:
			if(this->snake.movementDirection == Direction::Right)
				break;
			this->snake.movementDirection = Direction::Left;
			break;
	
		case sf::Keyboard::Right:
			if(this->snake.movementDirection == Direction::Left)
				break;
			this->snake.movementDirection = Direction::Right;
			break;

		default:
			this->snake.addBodyPart();
			break;
	}
}

void GameScene::drawBoard() const
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

void GameScene::drawSnake() const
{
	sf::RectangleShape snakePart;
	snakePart.setTexture(&TextureManager::snakeHeadTex, true);
	snakePart.setSize(sf::Vector2f(30.0f,30.0f));
	
	auto it = this->snake.getBodyBegin();
	auto itend = this->snake.getBodyEnd();
	
	// drawing head
	snakePart.setPosition
		(Board::boardxOffset+it->first*Board::tileWidth+5,
		 Board::boardyOffset+it->second*Board::tileHeight+5);
	this->parentWindow->draw(snakePart);
	++it;

	snakePart.setTexture(&TextureManager::snakeBodyTex, true);
	snakePart.setSize(sf::Vector2f(30.0f,30.0f));
	// drawing body
	while(it != itend)
	{
		snakePart.setPosition
			(Board::boardxOffset+it->first*Board::tileWidth+5,
			 Board::boardyOffset+it->second*Board::tileHeight+5);
		this->parentWindow->draw(snakePart);
		++it;
	}
}

void GameScene::drawCherry() const
{
	sf::RectangleShape cherry;
	cherry.setTexture(&TextureManager::cherryTexture, true);
	cherry.setSize(sf::Vector2f(40.0f, 40.0f));
	cherry.setPosition
		(Board::boardxOffset+this->cherryCoords.first*Board::tileWidth,
		 Board::boardyOffset+this->cherryCoords.second*Board::tileHeight);
	this->parentWindow->draw(cherry);
}

void GameScene::drawScore() const
{
	this->parentWindow->draw(this->scoreString);
}

sceneID GameScene::switchScene()
{
	puts("Switching to GameScene");
	return this->eventLoop();
}

void GameScene::renderGameTick() const
{
		this->parentWindow->draw(this->background.shape);
		this->parentWindow->draw(this->returnMainMenu.sprite);
		this->drawBoard();
		this->drawSnake();
		this->drawCherry();
		this->updateScoreString();
		this->drawScore();
}




