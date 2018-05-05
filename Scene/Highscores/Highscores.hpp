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
public:
	typedef std::tuple<std::string, std::string> entryType;
	constexpr const char *defaultScoresFilePath = "./data/highscores.data";

private:
	// returns scene that manager should switch to
	// after this scene returns, passing it to switchScene
	virtual sceneID eventLoop() override;

	Button returnButton;
	TableHeader header;

	std::vector<std::tuple<std::string,std::string> > highscoresTable;

	inline void loadScoresFromFile(const char *filename=defaultScoresFilePath);
	inline void drawScoreBoard();
	inline void drawHeader();
	inline void drawScoreBoardEntries(int numberOfEntries);

	inline void initializeButtons();
	inline void initializeHeader();

	void orderedInsert(const entryType &entry);

	// Logs scores to file
	void logScores(const char *filename=defaultScoresFilePath);

public:
	explicit Highscores(const std::shared_ptr<sf::RenderWindow> &wnd);

	// returns id of scene that should be invoked after
	// this one returns
	virtual sceneID switchScene() override;

	// Adding new score to the table
	void addScore(const entryType &entry);

	// Prints scores to console
	void debug_print_scores();
};

#endif // HIGHSCORES_H

