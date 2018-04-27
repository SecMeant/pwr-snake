#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include "../Scene.hpp"

#include "../../utility/stdshared.hpp"

#include <memory>

class Highscores: public Scene
{
private:
	// returns scene that manager should switch to
	// after this scene returns, passing it to switchScene
	virtual sceneID eventLoop() override;

	Button returnButton;
	inline void initializeButtons();
public:
	explicit Highscores(const std::shared_ptr<sf::RenderWindow> &wnd);

	// returns id of scene that should be invoked after
	// this one returns
	virtual sceneID switchScene() override;
};

#endif // HIGHSCORES_H

