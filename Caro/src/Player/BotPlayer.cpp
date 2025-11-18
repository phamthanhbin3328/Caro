#include "BotPlayer.h"

BotPlayer::BotPlayer()
	: m_enmLevel(Level::EASY)
{
}

BotPlayer::BotPlayer(const Level enmLevel)
	: m_enmLevel(enmLevel)
{
}
