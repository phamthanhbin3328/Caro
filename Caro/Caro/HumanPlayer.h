#pragma once

#include "Common.h"
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer();
	HumanPlayer(const std::string& strName);
	HumanPlayer(const std::string& strName, const uint16_t uWin, const uint16_t uLost, const uint16_t uDraw);

	// [VN] Name setter, getter
	std::string getName() const;
	void setName(const std::string& strName);
	// [VN] Num of win setter, getter
	uint16_t getNumOfWin() const;
	void setNumOfWin(const uint16_t uNumOfWin);
	// [VN] Num of lost setter, getter
	uint16_t getNumOfLost() const;
	void setNunOfLost(const uint16_t uNumOfLost);
	// [VN] Num of draw setter, getter
	uint16_t getNumOfDraw() const;
	void setNumOfDraw(const uint16_t uNumOfDraw);
	// [VN] Add num of win, lost, draw
	void addWin();
	void addLost();
	void addDraw();
	void addMove(const uint16_t uX, const uint16_t uY);

	void clearListMove();

private:
	uint16_t							m_uNumOfWin;
	uint16_t							m_uNumOfLost;
	uint16_t							m_uNumOfDraw;
	std::string							m_strName;
};