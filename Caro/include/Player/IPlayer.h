#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
enum ResultMatch
{
	WIN = 0
	, LOST
	, DRAW
};

class IPlayer
{
	public:
		virtual std::pair<int, int> move() = 0;
	protected:
};

#endif