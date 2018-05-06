#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include "../utility/stdshared.hpp"

#include <string>
#include <vector>
#include <tuple>
#include <fstream>

class SaveManager
{
public:
	typedef std::tuple<std::string, std::string> entryType;
	typedef std::vector<entryType> sBoardType;
	static constexpr const char *defaultScoresFilePath = "./data/highscores.data";

private:
	sBoardType highscoresTable;
	void orderedInsert(const entryType &entry);

public:
	void loadScoresFromFile(const char *filename=defaultScoresFilePath);

	// It saves scores from scoreboard to file.
	// numberOfTopEntries determine how many of them should be saved.
	// IT OVERWRITES FILE IF ALREADY EXISTS
	void saveScoresToFile
	(const char *filename=defaultScoresFilePath, int numberOfTopEntries=defScoreboardEntries);

	// Logs scores to file
	// Deprecated
	void logScores(const char *filename=defaultScoresFilePath);

	// Adding new score to the table
	void addScore(const entryType &entry);
	
	inline const sBoardType &getBoard()
	{return this->highscoresTable;}

	// Prints scores to console
	void debug_print_scores();
};

#endif // SAVEMANAGER_H
