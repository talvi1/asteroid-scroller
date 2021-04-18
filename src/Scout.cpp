#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include "Buffer.h"
#include "Player.h"
#include "Scout.h"

using namespace std;


static char ScoutImage[Scout::ROWS][Scout::COLUMNS];

void Scout::loadImage()
{
	string line, lines;
	ifstream Scout;
	Scout.open("../data/scout.txt");
	if (!Scout.is_open())
	{
		cout << "Scout File can't be opened." << endl;
		return;
	}
	while (!Scout.eof()) //reads file into string until end of file
	{
		getline(Scout, line);
		lines += line;
	}
	int k = 0;
	for (int i = 0; i < ROWS; i++) // uses the string and assigns each string character to a 2d character array
	{
		for (int j = 0; j < COLUMNS; j++)
		{

			ScoutImage[i][j] = lines[k];
			k++;

		}
	}
}
Scout::Scout() :Enemy(0, 0, ROWS, COLUMNS) //initalizes the Scout values and adds a random value for the ore value
{
	ore_value = 45;
	shield_cost = 15;
	dead = false;
}
unsigned int Scout::getOreValue() const
{
	return ore_value;
}
unsigned int Scout::getShieldCost() const
{
	return shield_cost;
}
void Scout::draw(Buffer&  b) const
{
	int row = getRow();
	int column = getColumn();
	for (int i = 0; i < ROWS; i++) //Loads each element in ship image array to the buffer 
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			b.setCell(ScoutImage[i][j], row + i, column + j);
		}
	}
}
void Scout::markDead()
{
	dead = true;
}
bool Scout::isDead() const
{
	if (dead == true)
		return true;
	else
		return false;
}
Scout::Scout(const Scout& original) : Enemy(original)
{
	shield_cost = original.shield_cost;
	ore_value = original.ore_value;
}
Scout& Scout::operator= (const Scout& original)
{
	if (this != &original)
	{
		Enemy::operator=(original);
		ore_value = original.ore_value;
		shield_cost = original.shield_cost;
	}
	return *this;
}
Scout::~Scout()
{
}
Enemy* Scout::getClone() const
{
	Scout *pa = new Scout(*this);
	return pa;
}
void Scout::update()
{
	move(0, -2);
}