#include "SceneManager.hpp"

SceneManager::SceneManager()
: mainWindow()
{
	puts("Creating scene manager");
	this->mainWindow =
		std::make_unique<sf::RenderWindow>(sf::VideoMode(800,600), "Snake game");
	this->mainWindow->setFramerateLimit(60);

	this->scenes.push_back(std::make_unique<MainMenu>(this->mainWindow));
	this->currentScene = sceneID::mainmenu;
	this->scenes[0]->switchScene();
}
