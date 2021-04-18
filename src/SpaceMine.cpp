#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include "Buffer.h"
#include "Player.h"
#include "SpaceMine.h"

using namespace std;


static char SpaceMineImage[SpaceMine::ROWS][SpaceMine::COLUMNS];

void SpaceMine::loadImage()
{
	string line, lines;
	ifstream SpaceMine;
	SpaceMine.open("../data/space_mine.txt");
	if (!SpaceMine.is_open())
	{
		cout << "SpaceMine File can't be opened." << endl;
		return;
	}
	while (!SpaceMine.eof()) //reads file into string until end of file
	{
		getline(SpaceMine, line);
		lines += line;
	}
	int k = 0;
	for (int i = 0; i < ROWS; i++) // uses the string and assigns each string character to a 2d character array
	{
		for (int j = 0; j < COLUMNS; j++)
		{

			SpaceMineImage[i][j] = lines[k];
			k++;

		}
	}
}
SpaceMine::SpaceMine() :Enemy(0, 0, ROWS, COLUMNS) //initalizes the SpaceMine values and adds a random value for the ore value
{
	ore_value = 0;
	shield_cost = 30;
	dead = false;
}
unsigned int SpaceMine::getOreValue() const
{
	return ore_value;
}
unsigned int SpaceMine::getShieldCost() const
{
	return shield_cost;
}
void SpaceMine::draw(Buffer&  b) const
{
	int row = getRow();
	int column = getColumn();
	for (int i = 0; i < ROWS; i++) //Loads each element in ship image array to the buffer 
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			b.setCell(SpaceMineImage[i][j], row + i, column + j);
		}
	}
}
void SpaceMine::markDead()
{
	dead = true;
}
bool SpaceMine::isDead() const
{
	if (dead == true)
		return true;
	else
		return false;
}
SpaceMine::SpaceMine(const SpaceMine& original) : Enemy(original)
{
	shield_cost = original.shield_cost;
	ore_value = original.ore_value;
}
SpaceMine& SpaceMine::operator= (const SpaceMine& original)
{
	if (this != &original)
	{
		Enemy::operator=(original);
		ore_value = original.ore_value;
		shield_cost = original.shield_cost;
	}
	return *this;
}
SpaceMine::~SpaceMine()
{
}
Enemy* SpaceMine::getClone() const
{
	SpaceMine *pa = new SpaceMine(*this);
	return pa;
}
