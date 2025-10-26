#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

enum CellType
{
	NONE = 0
	, X
	, O
};

class Table
{
	public: 
		Table();
		Table(int nLength, int nWidth);
		std::pair<int, int> getTableSize() const;
		bool setTableStatus(const std::pair<int, int> objPosition, const CellType enmCellType);
		void drawTable();
	private:
		std::pair<int, int>									m_objTableSize;					// table size, (length, width)
		std::map<std::pair<int, int>, CellType>				m_lstTableStatus;				// table status, (position, status)
};
#endif