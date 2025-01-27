#pragma once

#include "Common.h"

class Player
{
	public:
		Player() {};
		// [VN] Name setter, getter
		virtual std::string getName() const = 0;
		virtual void setName(const std::string& strName) = 0;
		// [VN] Num of win setter, getter
		virtual uint16_t getNumOfWin() const = 0;
		virtual void setNumOfWin(const uint16_t uNumOfWin) = 0;
		// [VN] Num of lost setter, getter
		virtual uint16_t getNumOfLost() const = 0;
		virtual void setNunOfLost(const uint16_t uNumOfLost) = 0;
		// [VN] Num of draw setter, getter
		virtual uint16_t getNumOfDraw() const = 0;
		virtual void setNumOfDraw(const uint16_t uNumOfDraw) = 0;
		// [VN] Add num of win, lost, draw
		virtual void addWin() = 0;
		virtual void addLost() = 0;
		virtual void addDraw() = 0;
};