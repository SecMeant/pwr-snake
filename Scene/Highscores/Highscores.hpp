#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include "../Scene.hpp"
#include "../../SaveManager/SaveManager.hpp"

#include "../../utility/stdshared.hpp"

#include <memory>

extern SaveManager saveManager;

class Highscores: public Scene
{
private:
	// returns scene that manager should switch to
	// after this scene returns, passing it to switchScene
	virtual sceneID eventLoop() override;

	TextButton returnButton;
	TableHeader header;

	inline void drawScoreBoard();
	inline void drawHeader();
	inline void drawScoreBoardEntries
	(int numberOfEntries=defScoreboardEntries);

	inline void initializeButtons();
	inline void initializeHeader();

public:
	explicit Highscores(const std::shared_ptr<sf::RenderWindow> &wnd);

	// returns id of scene that should be invoked after
	// this one returns
	virtual sceneID switchScene() override;
};

#endif // HIGHSCORES_H

