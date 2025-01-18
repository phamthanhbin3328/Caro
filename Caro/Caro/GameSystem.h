#pragma once

#include "Common.h"

// Player
#include "Player.h"

// Bot
#include "Bot.h"

// Manager
#include "Manager.h"

class GameSystem
{
	public:
		GameSystem();
		// [VN] Hiển thị bàn cờ
		void displayBroad();
		// [VN] Chế độ chơi người với người
		void PlayWithHuman();
		// [VN] Chế độ chơi người với máy
		void playWithBot();
		// [VN] Tìm kiếm người chơi
		void searchPlayer();
		// [VN] Xem lại
		void replay();
		// [VN] Hướng dẫn
		void guildline();

	private:
		// [VN] Check điều kiện thắng
		bool checkWin(const uint16_t uRow, const uint16_t uColum);
		// [VN] In màu
		void printColor(const uint16_t uLocation);
		// [VN] Đặt lại bàn cờ
		void resetBoard();

	private:
		uint16_t								m_uBroad[10][10];		//< 
		std::shared_ptr<Player>					m_PlayerOne;			//< 
		std::shared_ptr<Player>					m_PlayerTwo;			//< 
};
