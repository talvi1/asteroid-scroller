#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include "Buffer.h"
#include "Player.h"
#include "Asteroid.h"

using namespace std;


static const int ORE_VALUE_DEAD = 0;
static const int ORE_VALUE_MIN = 1;
static const int ORE_VALUE_MAX = 80;
static char asteroidImage[Asteroid::ROWS][Asteroid::COLUMNS];

void Asteroid::loadImage()
{
	string line, lines;
	ifstream asteroid;
	asteroid.open("../data/asteroid.txt");
	if (!asteroid.is_open())
	{
		cout << "Asteroid File can't be opened." << endl;
		return;
	}
	while (!asteroid.eof()) //reads file into string until end of file
	{
		getline(asteroid, line);
		lines += line;
	}
	int k = 0;
	for (int i = 0; i < ROWS; i++) // uses the string and assigns each string character to a 2d character array
	{
		for (int j = 0; j < COLUMNS; j++)
		{

			asteroidImage[i][j] = lines[k];
			k++;

		}
	}
}
Asteroid::Asteroid() :Enemy(0, 0, ROWS, COLUMNS) //initalizes the asteroid values and adds a random value for the ore value
{
	ore_value = rand() % (ORE_VALUE_MAX - ORE_VALUE_MIN) + ORE_VALUE_MIN;
	assert(invariant());
}
unsigned int Asteroid::getOreValue() const
{
	return ore_value;
}
void Asteroid::draw(Buffer&  b) const
{
	int row = getRow();
	int column = getColumn();
	stringstream s;
	s << ore_value;
	string str = s.str(); //converts the ore value from an int to a string so it can be passed as an argument to the buffer set cell function
	for (int i = 0; i < ROWS; i++) //Loads each element in ship image array to the buffer 
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			b.setCell(asteroidImage[i][j], row + i, column + j);
			if (asteroidImage[i][j] == 'X') //series of nested if statements for checking the value in the asteroid file	
			{								//if value is met then the characters are replaced by string characters corresponding to the ore value
				if (str[1] == 0)			//the characters are placed in the asteroid and move accordingly and are randomized
				{
					b.setCell('0', row + i, column + j);

				}
				else if (str[1] != 0)
				{
					b.setCell(str[0], row + i, column + j);

				}
			}
			if (asteroidImage[i][j] == 'Z')
			{
				if (str[1] == 0)
				{
					b.setCell(str[0], row + i, column + j);

				}
				else if (str[1] != 0)
				{
					b.setCell(str[1], row + i, column + j);

				}
			}


		}
	}
}
void Asteroid::markDead()
{
	ore_value = ORE_VALUE_DEAD;
	assert(invariant());
}
bool Asteroid::isDead() const
{
	if (ore_value == ORE_VALUE_DEAD)
		return true;
	else
		return false;
}
bool Asteroid::invariant() const
{
	return(getRowSize() >= 1 && getColumnSize() >= 1 && (ore_value == ORE_VALUE_DEAD || ore_value < ORE_VALUE_MAX || ore_value > ORE_VALUE_MIN));
}
Asteroid::Asteroid(const Asteroid& original) : Enemy(original)
{
	ore_value = original.ore_value;
}
Asteroid& Asteroid::operator= (const Asteroid& original) 
{
	if (this != &original)
	{
		Enemy::operator=(original);
		ore_value = original.ore_value;
	}
	assert(invariant());
	return *this;
}
Asteroid::~Asteroid()
{
}
unsigned int Asteroid::getShieldCost() const
{
	return ore_value;
}
Enemy* Asteroid::getClone() const
{
	Asteroid *pa = new Asteroid(*this);
	return pa;
}
