#include "Player.h"

Player::Player()
{
}

Player::Player(const std::string& strName)
{
}

std::string Player::getname()
{
	return std::string();
}

uint16_t Player::getNumOfWin() const
{
	return 0;
}

uint16_t Player::getNumOfLost() const
{
	return 0;
}

uint16_t Player::getNumOfDraw() const
{
	return 0;
}

void Player::setName(const std::string& strName)
{
}

void Player::setNumOfWin(const uint16_t uNumOfWin)
{
}

void Player::setNunOfLost(const uint16_t uNumOfLost)
{
}

void Player::setNumOfDraw(const uint16_t uNumOfDraw)
{
}

bool Player::addWin()
{
	return false;
}

bool Player::addLost()
{
	return false;
}

bool Player::addDraw()
{
	return false;
}

Move::Move()
{
}

Move::Move(uint16_t uX, uint16_t uY)
{
}

void Move::input()
{
}

void Move::setX(const uint16_t uX)
{
}

void Move::setY(const uint16_t uY)
{
}

uint16_t Move::getX() const
{
	return 0;
}

uint16_t Move::getY() const
{
	return 0;
}
