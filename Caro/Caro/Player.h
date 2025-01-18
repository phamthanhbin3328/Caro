#pragma once

#include "Common.h"

class Player
{
	public:
		Player();
		Player(const std::string& strName);
		std::string getname();
		uint16_t getNumOfWin() const;
		uint16_t getNumOfLost() const;
		uint16_t getNumOfDraw() const;
		void setName(const std::string& strName);
		void setNumOfWin(const uint16_t uNumOfWin);
		void setNunOfLost(const uint16_t uNumOfLost);
		void setNumOfDraw(const uint16_t uNumOfDraw);
		bool addWin();
		bool addLost();
		bool addDraw();

	private:
		std::string			m_strName;
		uint16_t			m_uNumOfWin;
		uint16_t			m_uNunOfLost;
		uint16_t			m_uNumOfDraw;
};

class Move
{
	public:
		Move();
		Move(uint16_t uX, uint16_t uY);
		void input();
		void setX(const uint16_t uX);
		void setY(const uint16_t uY);
		uint16_t getX() const;
		uint16_t getY() const;

	private:
		uint16_t m_uX;
		uint16_t m_uY;
};