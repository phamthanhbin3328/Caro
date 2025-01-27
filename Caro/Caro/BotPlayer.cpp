#include "BotPlayer.h"

BotPlayer::BotPlayer() : m_enmLevel(EASY), m_strBotName("Bot ahihi <3")
{}

BotPlayer::BotPlayer(const Level& enmLevel) : m_enmLevel(enmLevel), m_strBotName("Bot ahihi <3")
{}

std::string BotPlayer::getName() const
{
	return m_strBotName;
}

std::pair<uint16_t, uint16_t> BotPlayer::makeMove(const CaroTable& objCaroTable)
{
	// TODO: insert return statement here
	return std::make_pair<uint16_t, uint16_t>(0, 0);
}

int BotPlayer::minimax(int board[10][10], int depth, bool isMaximizing, int alpha, int beta)
{
	return 0;
}

int BotPlayer::evaluate(int board[10][10])
{
	return 0;
}

int BotPlayer::maxDepth()
{
	return 0;
}

