#include "SaveManager.hpp"

SaveManager saveManager;

void SaveManager::loadScoresFromFile
(const char *filename)
{
	std::ifstream scoresfile;
	std::string tableEntry;
	std::string score;
	entryType entry;

	scoresfile.open(filename);
	if(scoresfile.is_open())
	{
		this->highscoresTable.clear();
		while(getline(scoresfile, tableEntry, ' '))
		{
			getline(scoresfile, score);
			entry = {tableEntry, score};
			this->orderedInsert(entry);
		}
	}
	else printf("Error. Unable to open file %s.",filename);
}

void SaveManager::saveScoresToFile
(const char *filename, int amount)
{
	std::ofstream scoresFile;

	scoresFile.open(filename);
	if(scoresFile.is_open())
	{
		int i =0;
		for(auto it:this->highscoresTable)
		{
			if(i >= amount)
				break;

			scoresFile << std::get<0>(it) << " " << std::get<1>(it) << "\n";
			++i;
		}
	}
	else puts("Error. Cannot open file for saving scores.");
}

void SaveManager::orderedInsert(const entryType &entry)
{
	int val = std::stoi(std::get<1>(entry));
	auto it = this->highscoresTable.begin();
	auto itend = this->highscoresTable.end();

	if(this->highscoresTable.size() == 0)
	{
		this->highscoresTable.push_back(entry);
		return;
	}

	while(it != itend)
	{
		if(std::stoi(std::get<1>(*it)) <= val)
		{
			this->highscoresTable.insert(it,entry);
			return;
		}
		++it;
	}
	this->highscoresTable.push_back(entry);
}

void SaveManager::addScore(const entryType &entry)
{
	this->orderedInsert(entry);
	this->saveScoresToFile();
}

void SaveManager::logScores(const char *filename)
{
	std::ofstream outFile;
	outFile.open(filename);
	if(not outFile.is_open())
	{
		puts("Error while saving scores. Cannot open file.");
		return;
	}

	for(auto entry:this->highscoresTable)
	{
		outFile << std::get<0>(entry) << " " << std::get<1>(entry) << '\n';
	}
}

void SaveManager::debug_print_scores()
{
	for(auto i:highscoresTable)
	{
		printf("%s %s\n",
				std::get<0>(i).c_str(), std::get<1>(i).c_str());
	}
}
