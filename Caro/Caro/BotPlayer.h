#pragma once

#include "Common.h"
#include "Player.h"
#include "CaroTable.h"

enum Level
{
	EASY = 0
	, NORMAL
	, HARD
};

class BotPlayer
{
public:
	BotPlayer();
	BotPlayer(const Level& enmLevel);
	std::string getName() const;
	std::pair<uint16_t, uint16_t> makeMove(const CaroTable& objCaroTable);
private:

	int minimax(int board[10][10], int depth, bool isMaximizing, int alpha, int beta);
	int evaluate(int board[10][10]);
	int maxDepth();

private:
	Level					m_enmLevel;				//< 
	std::string				m_strBotName;			//< 
};