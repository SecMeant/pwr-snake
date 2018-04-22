#include "SceneManager.hpp"

SceneManager::SceneManager()
: mainWindow()
{
	puts("Creating scene manager");
	this->mainWindow =
		std::make_unique<sf::RenderWindow>(sf::VideoMode(800,600), "Snake game");
	this->mainWindow->setFramerateLimit(60);

	this->scenes.push_back(
			std::make_unique<MainMenu>(this->mainWindow));

	this->scenes.push_back(
			std::make_unique<Highscores>(this->mainWindow));

	this->currentScene = sceneID::mainmenu;
}

void SceneManager::switchScene(sceneID scene)
{
	this->currentScene = scene;
	this->scenes[scene]->switchScene();
}

void SceneManager::run()
{
	sceneID nextScene = sceneID::mainmenu;
	while(nextScene != sceneID::none)
	{
		nextScene = this->scenes[this->currentScene]->switchScene();
		this->currentScene = nextScene;
	}
}


