#pragma once

#include "Common.h"

// Player
#include "Player.h"

// Caro Table
#include "CaroTable.h"

// Manager
#include "FileManager.h"

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
	bool checkWin(const uint16_t uRow, const uint16_t uColum, uint16_t uNumOfWin = 4);
	// [VN] In màu
	void printColor(const uint16_t uLocation);
	// [VN] Đặt lại bàn cờ
	void resetBoard();

	void fetchHistoryPlayer(const std::string& strNameOne, std::string& strNameTwo);

private:
	std::unique_ptr<CaroTable>				m_pCaroTable;			//< 
	std::shared_ptr<Player>					m_pPlayerOne;			//< 
	std::shared_ptr<Player>					m_pPlayerTwo;			//< 
	std::shared_ptr<FileManager>			m_pFileManager;			//< 
	std::map<uint16_t, uint16_t>			m_lstMove;				//< 
};
