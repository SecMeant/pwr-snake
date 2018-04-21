#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Scene/Scene.hpp"
#include "../Scene/MainMenu/MainMenu.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include <stdio.h>

class SceneManager
{
private:
	enum class sceneID{mainmenu}currentScene;

	// Holds all available scenes
	std::vector<std::unique_ptr<Scene> > scenes;
	std::shared_ptr<sf::RenderWindow> mainWindow;

public:
	SceneManager();
};

#endif // SCENEMANAGER_H
