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
	this->registerScene<GameScene>();

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
		printf("Error - cannot switch to scene with id: %i.\n",scene);
		this->currentScene = scenecopy;
	}
}

template<typename T>
void SceneManager::registerScene()
{
	static bool exists = 0;

	if(exists)
	{
		printf("Cannot create Scene.\n%s already exists.\n",
				__PRETTY_FUNCTION__);
		return;
	}

	this->scenes.push_back(
			std::make_unique<T>(this->mainWindow));
	exists = true;
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


