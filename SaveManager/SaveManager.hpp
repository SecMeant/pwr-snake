#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

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

	// Logs scores to file
	void logScores(const char *filename=defaultScoresFilePath);

	// Adding new score to the table
	void addScore(const entryType &entry);
	
	inline const sBoardType &getBoard()
	{return this->highscoresTable;}

	// Prints scores to console
	void debug_print_scores();
};

#endif // SAVEMANAGER_H
