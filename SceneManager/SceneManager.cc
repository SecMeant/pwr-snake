#include "SceneManager.hpp"

SceneManager::SceneManager()
: mainWindow()
{
	puts("Creating scene manager");
	this->mainWindow =
		std::make_unique<sf::RenderWindow>(sf::VideoMode(800,600), "Snake game");
	this->mainWindow->setFramerateLimit(60);

	this->registerScene<MainMenu>();
	this->registerScene<Highscores>();

	this->currentScene = sceneID::mainmenu;
}

void SceneManager::switchScene(sceneID scene)
{
	if(this->scenes.size() == 0)
		return;

	sceneID scenecopy = this->currentScene;
	try
	{
		this->currentScene = scene;
		this->scenes.at(scene)->switchScene();
	}
	catch(const std::out_of_range &ex)
	{
		printf("Error - cannot switch to scene with id: %llu.\n",scene);
		this->currentScene = scenecopy;
	}
}

template<typename T>
void SceneManager::registerScene()
{
	this->scenes.push_back(
			std::make_unique<T>(this->mainWindow));
}

void SceneManager::run()
{
	sceneID nextScene;
	while(this->currentScene != sceneID::none)
	{
		nextScene = this->scenes[this->currentScene]->switchScene();
		this->currentScene = nextScene;
	}
}


