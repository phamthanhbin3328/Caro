#include "GameSystem.h"

#include "HumanPlayer.h"


/*
* @brief		[VN] Control system của game
* @return		[VN] Không có giá trị trả về
*/

GameSystem::GameSystem(): m_lstMove()
{
	m_pCaroTable = std::make_unique<CaroTable>();
	m_pFileManager = std::make_shared<FileManager>();
}


/*
* @brief		[VN] Hiển thị bàn cờ
* @return		[VN] Không có giá trị trả về
*/
void GameSystem::displayBroad()
{
	system("cls");
	std::cout << "=> Player \033[35m\033[1m1\033[0m = \033[31m\033[1mX\033[0m, Player \033[35m\033[1m2\033[0m = \033[36m\033[1mO\033[0m: ";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::left << std::setw(5) << " ";
	for (int i = 0; i < 10; ++i) {
		std::cout << "\033[35m";
		std::cout << "\033[1m" << std::left << std::setw(4) << i;
		std::cout << "\033[0m";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << std::left << std::setw(3) << " ";
		std::cout << "\033[1m" << "|---|---|---|---|---|---|---|---|---|---|" << "\033[0m" << std::endl;
		std::cout << "\033[35m\033[1m" << std::left << std::setw(3) << i << "\033[0m";
		for (int j = 0; j < 10; ++j) {
			std::cout << "\033[1m| \033[0m";
			printColor(m_pCaroTable->getValueOfBroad(i, j));
			std::cout << " ";
		}
		std::cout << "\033[1m|\033[0m" << std::endl;
	}
	std::cout << std::left << std::setw(3) << " ";
	std::cout << "\033[1m" << "|---|---|---|---|---|---|---|---|---|---|" << "\033[0m" << std::endl;
}

/*
* @brief		[VN] Chế độ chơi người với người
* @return		[VN] Không có giá trị trả về
*/
void GameSystem::PlayWithHuman()
{
	// [VN] Nhập tên người chơi
	std::string strHumanNameOne, strHumanNameTwo;
	std::cout << "Nhap Ten Player 1: "; std::getline(std::cin, strHumanNameOne);
	m_pPlayerOne = std::make_shared<HumanPlayer>(strHumanNameOne);
	std::cout << "Nhap Ten Player 2: "; std::getline(std::cin, strHumanNameTwo);
	m_pPlayerTwo = std::make_shared<HumanPlayer>(strHumanNameTwo);
	fetchHistoryPlayer(strHumanNameOne, strHumanNameTwo);
	// [VN] Số lượt chơi, được giới hạn ở mức 100 lượt (100 ô)
	uint16_t nNumOfTurn;
	// row, colum
	uint16_t nRow, nColum;
	while (true)
	{
		// [VN] Reset dữ liệu
		m_pCaroTable->clear();
		m_lstMove.clear();
		nNumOfTurn = 0;
		do
		{
			displayBroad();
			// [VN] Nhập dữ liệu
			std::cout << "Player: " << nNumOfTurn % 2 + 1 << "'s Turn: ";
			std::cin >> nRow >> nColum;
			std::cin.ignore();
			// [VN] Valid dữ liệu
			if (m_pCaroTable->getValueOfBroad(nRow, nColum) == 0 || m_pCaroTable->getValueOfBroad(nRow, nColum) == 1 || nRow < 0 || nRow > 9 || nColum < 0 || nColum > 9)
			{
				std::cout << "Invalid Value!" << std::endl;
				system("pause");
			}
			else
			{
				if (nNumOfTurn % 2 == 0)
				{
					// [VN] Player 1 là X
					m_lstMove.emplace(nRow, nColum);
					m_pCaroTable->setXToTable(nRow, nColum);
					// [VN] Player 1 win
					if (checkWin(nRow, nColum, 4))
					{
						std::cout << "Player 1 win!" << std::endl;
						m_pPlayerOne->addWin();
						m_pPlayerTwo->addLost();
						break;
					}
				}
				else
				{
					// [VN] Player 2 là O
					m_lstMove.emplace(nRow, nColum);
					m_pCaroTable->setOToTable(nRow, nColum);
					// [VN] Player 2 win
					if (checkWin(nRow, nColum, 4))
					{
						std::cout << "Player 2 win!" << std::endl;
						m_pPlayerOne->addLost();
						m_pPlayerTwo->addWin();
						break;
					}
				}
				// [VN] Hiển thị bàn cờ
				displayBroad();
				nNumOfTurn++;
			}

		} while (nNumOfTurn < 100);
		if (nNumOfTurn == 100)
		{
			std::cout << "Draw" << std::endl;
			m_pPlayerOne->addDraw();
			m_pPlayerTwo->addDraw();
		}
		// [VN] Record trận đấu
		m_pFileManager->saveGameReplay(m_lstMove, strHumanNameOne, strHumanNameTwo);
		// [VN] Lựa chọn có tiếp tục hay không
		uint16_t nChoice;
		std::cout << "Ban co muon choi tiep: 1(yes), 2(no): "; std::cin >> nChoice;
		if (nChoice == 2)
		{
			/* -----------------[VN] Save Player Data------------------*/
			m_pFileManager->savePlayerData(HumanPlayer(m_pPlayerOne->getName()
					, m_pPlayerOne->getNumOfWin()
					, m_pPlayerOne->getNumOfLost()
					, m_pPlayerOne->getNumOfDraw()));
			m_pFileManager->savePlayerData(HumanPlayer(m_pPlayerTwo->getName()
					, m_pPlayerTwo->getNumOfWin()
					, m_pPlayerTwo->getNumOfLost()
					, m_pPlayerTwo->getNumOfDraw()));
			break;
		}
		else
		{
			continue;
		}
	}


}

/*
* @brief		[VN] Chế độ chơi người với máy
* @return		[VN] Không có giá trị trả về
*/
void GameSystem::playWithBot()
{
}

/*
* @brief		[VN] Tìm kiếm người chơi
* @return		[VN] Không có giá trị trả về
*/
void GameSystem::searchPlayer()
{
	std::string strName;
	std::cout << "Nhap Player ban muon tim: "; std::getline(std::cin, strName);
	std::shared_ptr<HumanPlayer> pPlayer = std::make_shared<HumanPlayer>();
	/*-------------to be continue--------------------*/
	if (pPlayer->getName() == "" && pPlayer->getNumOfWin() == 0 && pPlayer->getNumOfLost() == 0 && pPlayer->getNumOfDraw() == 0)
	{
		std::cout << "Khong thay Player!" << std::endl;
	}
	else
	{
		std::cout << "Player: " << pPlayer->getName() << "\nSo tran thang: " << pPlayer->getNumOfWin() << "\nSo tran thua: "
			<< pPlayer ->getNumOfLost() << "\nSo tran hoa:" << pPlayer ->getNumOfDraw() << std::endl;
	}
}


/*
* @brief		[VN] Xem lại
* @return		[VN] Không có giá trị trả về
*/
void GameSystem::replay()
{
	FileManager file;
	std::map<uint16_t, uint16_t> lstMove;
	std::vector<std::string> lstName;
	lstName = m_pFileManager->loadNameGame();
	uint16_t i = 1;
	int16_t nChoice;
	// [VN] Hiển thi ra các trận đã lưu cho người dùng nhập trận muốn xem
	system("cls");
	std::cout << "Cac tran da luu" << std::endl;
	for (auto& objName : lstName)
	{
		std::cout << i++ << objName << std::endl;
	}
	std::cout << "Lua chon cua ban: "; std::cin >> nChoice;

	lstMove = file.loadGameReplay(nChoice);
	resetBoard();
	displayBroad();
	system("pause");
	int j = 0;
	for (auto& objMove : lstMove)
	{
		if (j % 2 == 0)
		{
			m_pCaroTable->setXToTable(objMove.first, objMove.second);
			displayBroad();

			if (j == lstMove.size() - 1)
			{
				std::cout << "Player 1 Won" << std::endl;
			}
			j++;
		}
		else
		{
			m_pCaroTable->setOToTable(objMove.first, objMove.second);
			displayBroad();
			if (j == lstMove.size() - 1)
			{
				std::cout << "Player 2 Won" << std::endl;
			}
			j++;
		}
		system("pause");
	}
}

/*
* @brief		[VN] Hướng dẫn
* @return		[VN] Không có giá trị trả về
*/
void GameSystem::guildline()
{
	std::cout << "=================== CARO GAME INSTRUCTIONS ===================" << std::endl;
	std::cout << "1. The game is played on a 10x10 grid." << std::endl;
	std::cout << "2. There are two players: Player 1 (X) and Player 2 (O)." << std::endl;
	std::cout << "3. Players take turns to place their mark (X or O) on an empty cell." << std::endl;
	std::cout << "4. To place a mark, enter the row and column number (both from 1 to 10)." << std::endl;
	std::cout << "5. The player who first gets 4 or 5 of their marks in a row (horizontally, vertically, or diagonally) wins the game." << std::endl;
	std::cout << "6. If all cells are filled and no player has 4 in a row, the game is a draw." << std::endl;
	std::cout << "==============================================================" << std::endl;
}

/*
* @brief		[VN] Check điều kiện thắng
* @param[in]	uRow	[VN] Hàng
* @param[in]	uColum	[VN] Cột
* @return		[VN] Kết quả (true: thắng, false: thua)
*/
bool GameSystem::checkWin(const uint16_t uRow, const uint16_t uColum, uint16_t uNumOfWin)
{
	// [VN] Trạng thái của ô hiện tại
	int tmp = m_pCaroTable->getValueOfBroad(uRow, uColum);
	// [VN] 8 hướng có thể đi
	int nextX[8] = { 0,0,1,-1,-1,1,1,-1 };
	int nextY[8] = { 1,-1,0,0,1,-1,1,-1 };
	int nextR, nextC;
	// [VN] số ô giống nhau
	int num;
	for (int i = 0;i < 8;i++)
	{
		if (i % 2 == 0)
		{
			num = 1;
		}
		nextR = uRow + nextX[i];
		nextC = uColum + nextY[i];
		for (int j = 0;j < 4;j++)
		{
			if (nextR < 0 || nextR>9 || nextC < 0 || nextC>9 || m_pCaroTable->getValueOfBroad(nextR, nextC) != tmp)
			{
				break;
			}
			if (m_pCaroTable->getValueOfBroad(nextR, nextC) == tmp)
			{
				num++;
			}
			nextR += nextX[i];
			nextC += nextY[i];
			if (num == uNumOfWin)
			{
				return true;
			}
		}
	}
	return false;
}

/*
* @brief		[VN] Check điều kiện thắng
* @param[in]	uLocation	[VN] Vị trí
* @return		[VN] Không có giá trị trả về
* */
void GameSystem::printColor(const uint16_t uLocation)
{
	if (uLocation == 0) {
		std::cout << "\033[31m\033[1m" << "X" << "\033[0m";
	}
	else if (uLocation == 1) {
		std::cout << "\033[36m\033[1m" << "O" << "\033[0m";
	}
	else {
		std::cout << " ";
	}
}

/*
* @brief		[VN] Đặt lại bàn cờ
* @return		[VN] Không có giá trị trả về
*/
void GameSystem::resetBoard()
{

}

void GameSystem::fetchHistoryPlayer(const std::string& strNameOne, std::string& strNameTwo)
{
	HumanPlayer objHumanPlayer;
	m_pFileManager->loadPlayerHistory(strNameOne, objHumanPlayer);
	m_pPlayerOne->setNumOfWin(objHumanPlayer.getNumOfWin());
	m_pPlayerOne->setNunOfLost(objHumanPlayer.getNumOfLost());
	m_pPlayerOne->setNumOfDraw(objHumanPlayer.getNumOfDraw());
	
	m_pFileManager->loadPlayerHistory(strNameTwo, objHumanPlayer);
	m_pPlayerTwo->setNumOfWin(objHumanPlayer.getNumOfWin());
	m_pPlayerTwo->setNunOfLost(objHumanPlayer.getNumOfLost());
	m_pPlayerTwo->setNumOfDraw(objHumanPlayer.getNumOfDraw());
}
