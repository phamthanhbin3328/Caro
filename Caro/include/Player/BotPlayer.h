#ifndef BOTPLAYER_H
#define BOTPLAYER_H

#include "IPlayer.h"

enum Level
{
	EASY = 0
	, NORMAL
	, HARD
};

class BotPlayer : public IPlayer
{
	public:
	BotPlayer();
	BotPlayer(const Level enmLevel);
	std::pair<int, int> move();

	private:
		Level							m_enmLevel;						// Lever of bot
};



#endif