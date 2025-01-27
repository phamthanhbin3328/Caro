#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : m_strName()
	, m_uNumOfWin(0)
	, m_uNumOfLost(0)
	, m_uNumOfDraw(0){}

HumanPlayer::HumanPlayer(const std::string & strName) : m_strName(strName)
	, m_uNumOfWin(0)
	, m_uNumOfLost(0)
	, m_uNumOfDraw(0){}

HumanPlayer::HumanPlayer(const std::string& strName, const uint16_t uWin, const uint16_t uLost, const uint16_t uDraw)
	: m_strName(strName)
	, m_uNumOfWin(uWin)
	, m_uNumOfLost(uLost)
	, m_uNumOfDraw(uDraw){}


std::string HumanPlayer::getName() const
{
	return m_strName;
}

void HumanPlayer::setName(const std::string& strName)
{
	m_strName = strName;
}

uint16_t HumanPlayer::getNumOfWin() const
{
	return m_uNumOfWin;
}

void HumanPlayer::setNumOfWin(const uint16_t uNumOfWin)
{
	m_uNumOfWin = uNumOfWin;
}

uint16_t HumanPlayer::getNumOfLost() const
{
	return m_uNumOfLost;
}

void HumanPlayer::setNunOfLost(const uint16_t uNumOfLost)
{
	m_uNumOfLost = uNumOfLost;
}

uint16_t HumanPlayer::getNumOfDraw() const
{
	return m_uNumOfDraw;
}

void HumanPlayer::setNumOfDraw(const uint16_t uNumOfDraw)
{
	m_uNumOfDraw = uNumOfDraw;
}

void HumanPlayer::addWin()
{
	m_uNumOfWin++;
}

void HumanPlayer::addLost()
{
	m_uNumOfLost++;
}

void HumanPlayer::addDraw()
{
	m_uNumOfDraw++;
}


