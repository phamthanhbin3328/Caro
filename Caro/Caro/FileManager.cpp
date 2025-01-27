#include "FileManager.h"

void FileManager::savePlayerData(const HumanPlayer& objHumanPlayer) const
{
	bool blFound = false;
	std::ifstream inFile(m_strFilePlayer);

	std::vector<HumanPlayer> lstAllHumanPlayers;
	if (inFile.is_open())
	{
		// [VN] Đọc dữ liệu từ file
		std::string strLine;
		while (std::getline(inFile, strLine))
		{
			std::istringstream iss(strLine);
			std::string strName;
			uint16_t nWin, nLoss, nDraw;
			if (std::getline(iss, strName, ':') && iss >> nWin >> nLoss >> nDraw)
			{
				HumanPlayer objExistingPlayer(strName);
				objExistingPlayer.setNumOfWin(nWin);
				objExistingPlayer.setNunOfLost(nLoss);
				objExistingPlayer.setNumOfDraw(nDraw);
				// [VN] Kiểm tra player cần thêm đã có trong file chưa
				if (objHumanPlayer.getName() == objExistingPlayer.getName())
				{
					objExistingPlayer.setNumOfWin(objHumanPlayer.getNumOfWin());
					objExistingPlayer.setNunOfLost(objHumanPlayer.getNumOfLost());
					objExistingPlayer.setNumOfDraw(objHumanPlayer.getNumOfDraw());
					blFound = true;
				}
				lstAllHumanPlayers.push_back(objExistingPlayer);
			}
		}
		inFile.close();
	}
	else
	{
		std::cout << "Unable to open player data file for reading." << std::endl;
		return;
	}
	// Nếu không tìm thấy tên của player trong tệp thì thêm vào cuối
	if (!blFound)
	{
		lstAllHumanPlayers.push_back(objHumanPlayer);
	}
	std::ofstream outFile(m_strFilePlayer);
	if (outFile.is_open())
	{
		for (auto& objHumanPlayer : lstAllHumanPlayers)
		{
			outFile << objHumanPlayer.getName() << ": "
				<< objHumanPlayer.getNumOfWin() << " "
				<< objHumanPlayer.getNumOfLost() << " "
				<< objHumanPlayer.getNumOfDraw() << "\n";
		}
			outFile.close();
			std::cout << "Saved player data to file.\n";
	}
	else
	{
		std::cout << "Unable to open player data file for writing." << std::endl;
	}
}

HumanPlayer FileManager::loadPlayerData(const std::string& strName) const
{
	std::ifstream inFile(m_strFilePlayer);
	if (inFile.is_open())
	{
		// [VN] Đọc từng dòng của file
		std::string strLine;
		while (std::getline(inFile, strLine))
		{
			std::istringstream iss(strLine);
			std::string strNameTmp;
			uint16_t nWin, nLoss, nDraw;
			if (std::getline(iss, strNameTmp, ':') && iss >> nWin >> nLoss >> nDraw)
			{
				if (strNameTmp == strName) {
					HumanPlayer objHumanPlayer(strNameTmp);
					objHumanPlayer.setNumOfWin(nWin);
					objHumanPlayer.setNunOfLost(nLoss);
					objHumanPlayer.setNumOfDraw(nDraw);
					return objHumanPlayer;
				}
			}
		}
		inFile.close();
	}
	else
	{
		std::cerr << "Unable to open player data file for reading.\n";
	}
	return HumanPlayer();
}

std::vector<std::string> FileManager::loadNameGame()
{
	return std::vector<std::string>();
}

void FileManager::savePlayerName(const std::string& strName, const HumanPlayer& objHumanPlayer) const
{
}

void FileManager::saveGameReplay(const std::map<uint16_t, uint16_t>& lstMove, const std::string& strPlayerNameOne, const std::string& strPlayerNameTwo) const
{

	std::ofstream outFile(m_strFileReplay, std::ios::app);
	if (outFile.is_open())
	{
		outFile << "#" << " " << strPlayerNameOne << " vs " << strPlayerNameTwo << ": ";
		// 
		for (auto& objMove : lstMove)
		{
			outFile << objMove.first << " " << objMove.second << " ";
		}
		// [VN] Kết thúc
		outFile << -1 << " " << -1 << "\n";
		outFile.close();
	}
	else
	{
		std::cout << "Unable to open replay file for writing.\n";
	}
}

std::map<uint16_t, uint16_t> FileManager::loadGameReplay(const uint16_t nGameID) const
{
	std::map<uint16_t, uint16_t> lstMove;
	std::ifstream inFile(m_strFileReplay);
	if (inFile.is_open())
	{
		std::string strLine;
		uint16_t nGameIDTmp = 0;
		while (std::getline(inFile, strLine))
		{
			if (strLine[0] == '#')
			{
				nGameIDTmp++;
			}
			if (nGameIDTmp == nGameID)
			{
				std::istringstream iss(strLine.substr(strLine.find(":") + 1));
				uint16_t x, y;
				while (iss >> x >> y) {
					if (x == -1 && y == -1)
					{
						break;
					}
					lstMove.emplace(x, y);
				}
				break;
			}
		}
		inFile.close();
	}
	else
	{
		std::cout << "Unable to open replay file for reading.\n";
	}
	return lstMove;
}

void FileManager::loadPlayerHistory(const std::string& strName, HumanPlayer& objHumanPlayer)
{
	std::ifstream inFile(m_strFilePlayer);
	if (inFile.is_open())
	{
		std::string strLine;
		while (std::getline(inFile, strLine))
		{
			std::istringstream iss(strLine);
			std::string strPlayerName;
			uint16_t nWin, nLoss, nDraw;
			if (std::getline(iss, strPlayerName, ':') && iss >> nWin >> nLoss >> nDraw)
			{
				if (strPlayerName == strName) {
					objHumanPlayer.setNumOfWin(nWin);
					objHumanPlayer.setNunOfLost(nLoss);
					objHumanPlayer.setNumOfDraw(nDraw);
				}
			}
		}
		inFile.close();
	}
	else
	{
		std::cout << "Khong mo duoc file!" << std::endl;
	}
}
