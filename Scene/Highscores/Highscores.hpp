#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include "../Scene.hpp"

#include "../../utility/stdshared.hpp"

#include <memory>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

class Highscores: public Scene
{
private:
	// returns scene that manager should switch to
	// after this scene returns, passing it to switchScene
	virtual sceneID eventLoop() override;

	Button returnButton;
	TableHeader header;

	std::vector<std::tuple<std::string, std::string> > highscoresTable;

	inline void loadScoresFromFile(const char *filename="./data/highscores.data");
	inline void drawScoreBoard();
	inline void drawHeader();
	inline void drawScoreBoardEntries(int numberOfEntries);

	inline void initializeButtons();
	inline void initializeHeader();
public:
	explicit Highscores(const std::shared_ptr<sf::RenderWindow> &wnd);

	// returns id of scene that should be invoked after
	// this one returns
	virtual sceneID switchScene() override;

	// Prints scores to console
	void debug_print_scores();
};

#endif // HIGHSCORES_H

