#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
	: m_strPlayerName(""), m_lstHistory(), m_unTotalWin(0), m_unTotalLost(0), m_unTotalDraw(0)
{

}

HumanPlayer::HumanPlayer(std::string strName)
	: m_lstHistory(), m_unTotalWin(0), m_unTotalLost(0), m_unTotalDraw(0)
{
	m_strPlayerName = strName;
}

std::string HumanPlayer::getPlayerName() const
{
	return m_strPlayerName;
}

bool HumanPlayer::setResultMatch(const ResultMatch enmResult)
{
	switch(enmResult)
	{
		case ResultMatch::WIN:
		{
			m_unTotalWin++;
			break;
		}
		case ResultMatch::LOST:
		{
			m_unTotalLost++;
			break;
		}
		case ResultMatch::DRAW:
		{
			m_unTotalDraw++;
			break;
		}
		default:
			return false;
	}

	return true;
}

std::pair<int, int> HumanPlayer::move()
{
	std::cout << "Input Your Move (x,y): " << std::endl;

	return std::pair<int, int>();
}
