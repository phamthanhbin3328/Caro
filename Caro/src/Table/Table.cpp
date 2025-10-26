#include "Table.h"
#include<iomanip>

Table::Table()
	: m_objTableSize(0, 0), m_lstTableStatus()
{
}

Table::Table(int nLength, int nWidth)
	: m_objTableSize(nLength, nWidth)
{
	for (int i = 0 ; i < nLength ; i++)
	{
		for (int j = 0 ; j < nLength ; j++)
		{
			m_lstTableStatus.emplace(std::make_pair(i, j), CellType::NONE);
		}
	}
}

/*
 *@detail			get table size
 *@return			table size
*/
std::pair<int, int> Table::getTableSize() const
{
	return m_objTableSize;
}

/*
 *@detail			set table status
 *@param[in]		objPosition			position in table
 *@param[in]		enmCellType			cell type
 *@return			true: successed false: failed
*/
bool Table::setTableStatus(const std::pair<int, int> objPosition, const CellType enmCellType)
{
	bool blRet = false;
	// validate data input
	if (objPosition.first > m_objTableSize.first || objPosition.second > m_objTableSize.second)
	{
		return blRet;
	}
	if (m_lstTableStatus[objPosition] == CellType::NONE)
	{
		m_lstTableStatus[objPosition] = enmCellType;
		blRet = true;
	}

	return blRet;
}

/* 
 * @detail			draw table
 */
void Table::drawTable()
{
	std::cout << std::left << std::setw(5) << " ";
	for (int j = 0 ; j < m_objTableSize.first ; j++)
	{
		std::cout << "\033[35m\033[1m" << std::setw(4) << j << "\033[0m";
	}
	std::cout << std::endl;

	for (int i = 0 ; i < m_objTableSize.first ; i++)
	{
		std::cout << "   \033[1m";
		for (int j = 0 ; j < m_objTableSize.second ; j++)
		{
			std::cout << "|---";
		}
		std::cout << "|\033[0m\n";

		std::cout << "\033[35m\033[1m" << std::setw(3) << i << "\033[0m";
		for (int j = 0; j < m_objTableSize.second; j++)
		{
			std::cout << "\033[1m| \033[0m";
			switch (m_lstTableStatus[std::make_pair(i, j)])
			{
			case CellType::X:
				std::cout << "\033[31m\033[1mX\033[0m";
				break;
			case CellType::O:
				std::cout << "\033[36m\033[1mO\033[0m";
				break;
			default:
				std::cout << " "; // ô trống
				break;
			}
			std::cout << " ";
		}
		std::cout << "\033[1m|\033[0m\n";
	}

	std::cout << "   \033[1m";
	for (int j = 0; j < m_objTableSize.first; j++)
	{
		std::cout << "|---";
	}
	std::cout << "|\033[0m\n";
}
