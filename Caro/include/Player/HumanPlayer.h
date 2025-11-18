#ifndef HUMANPLAYER_H
#defind HUMANPLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "IPlayer.h"

class HumanPlayer : public IPlayer
{
	public:
		HumanPlayer();
		HumanPlayer(std::string strName);
		std::string getPlayerName() const;
		bool saveHistory();
		bool setResultMatch(const ResultMatch enmResult);
		std::pair<int, int> move();

	private:
		std::string											m_strPlayerName;				// Player Name
		std::vector<std::string, ResultMatch>				m_lstHistory;					// History play
		uint16_t											m_unTotalWin;					// num of match wim
		uint16_t											m_unTotalLost;					// num of match lost
		uint16_t											m_unTotalDraw;					// num of match draw
};

#endif