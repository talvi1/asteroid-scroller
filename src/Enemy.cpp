#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include "Buffer.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;


static const int ORE_VALUE_DEAD = 0;
static const int ORE_VALUE_MIN = 1;
static const int ORE_VALUE_MAX = 80;
static char asteroidImage[Player::ROWS][Player::COLUMNS];


Enemy::Enemy() :rec(0, 0, 1, 1) //initalizes the asteroid values and adds a random value for the ore value
{
	assert(invariant());
}
Enemy::Enemy(int row1, int column1, int row_size1, int column_size1) :rec(row1, column1, row_size1, column_size1)
{
}
int Enemy::getRow() const
{
	return rec.getRow();
}
int Enemy::getColumn() const
{
	return rec.getColumn();
}
int Enemy::getRowSize() const
{
	return rec.getRowSize();
}
int Enemy::getColumnSize() const
{
	return rec.getColumnSize();
}
void Enemy::setPosition(int row1, int column1)
{
	rec.setPosition(row1, column1);
	assert(invariant());
}

void Enemy::move(int row1, int column1)
{
	rec.move(row1, column1);
	assert(invariant());
}
bool Enemy::invariant() const
{
	return(rec.getRowSize() >= 1 && rec.getColumnSize() >= 1);
}
Enemy::Enemy(const Enemy& original)
{
	rec = original.rec;
}
Enemy& Enemy::operator= (const Enemy& original)
{
	if (this != &original)
	{
		rec = original.rec;
	}
	assert(invariant());
	return *this;
}
const Rectangle& Enemy::getRectangle() const
{
	return rec;
}
Enemy::~Enemy()
{
}
void Enemy::update()
{

}

