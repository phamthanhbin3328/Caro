#pragma once

#include "Common.h"

class CaroTable
{
public:
	CaroTable();
	~CaroTable();
	void clear();
	int16_t getValueOfBroad(const int16_t uRow, const int16_t uColum) const;
	void setXToTable(const int16_t uRow, const int16_t uColum);
	void setOToTable(const int16_t uRow, const int16_t uColum);
private:
	int16_t					m_Broad[10][10];
};
