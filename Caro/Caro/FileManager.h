#pragma once

#include "Common.h"

#include "HumanPlayer.h"

class FileManager
{
public:

	void savePlayerData(const HumanPlayer& objHumanPlayer) const;
	HumanPlayer loadPlayerData(const std::string& strName) const;
	std::vector<std::string> loadNameGame();
	void savePlayerName(const std::string& strName, const HumanPlayer& objHumanPlayer) const;
	void saveGameReplay(const std::map<uint16_t, uint16_t>& lstMove, const std::string& strPlayerNameOne, const std::string& strPlayerNameTwo) const;
	std::map<uint16_t, uint16_t> loadGameReplay(uint16_t nGameID) const;
	void loadPlayerHistory(const std::string& strName, HumanPlayer& objHumanPlayer);
private:
	std::string							m_strFilePlayer = "Player.txt";		//< 
	std::string							m_strFileReplay = "Replay.txt";		//< 
};