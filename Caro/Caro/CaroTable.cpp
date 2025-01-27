#include "CaroTable.h"

CaroTable::CaroTable()
{
	for (int16_t i = 0; i < 10; i++)
	{
		for (int16_t j = 0; j < 10; j++)
		{
			m_Broad[i][j] = -1;
		}
	}
}

CaroTable::~CaroTable()
{
}

void CaroTable::clear()
{
	for (int16_t i = 0; i < 10; i++)
	{
		for (int16_t j = 0; j < 10; j++)
		{
			m_Broad[i][j] = -1;
		}
	}
}

int16_t CaroTable::getValueOfBroad(const int16_t uRow, const int16_t uColum) const
{
	return m_Broad[uRow][uColum];
}

void CaroTable::setXToTable(const int16_t uRow, const int16_t uColum)
{
	m_Broad[uRow][uColum] = 0;
}

void CaroTable::setOToTable(const int16_t uRow, const int16_t uColum)
{
	m_Broad[uRow][uColum] = 1;
}

