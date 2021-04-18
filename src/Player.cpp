#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include "Buffer.h"
#include "Player.h"
#include "Game.h"

using namespace std;

static const int MAX_shield_strength = 50;
static char playerImage[Player::ROWS][Player::COLUMNS]; //array for storing ship image

void Player::loadImage()
{
	string line, lines;
	ifstream player;
	player.open("../data/player.txt");
	if (!player.is_open())
	{
		cout << "Player File can't be opened." << endl;
		return;
	}
	while (!player.eof()) //reads file into string until end of file
	{
		getline(player, line);
		lines += line;
	}
	int k = 0;
	for (int i = 0; i < ROWS; i++) // uses the string and assigns each string character to a 2d character array
	{
		for (int j = 0; j < COLUMNS; j++)
		{

			playerImage[i][j] = lines[k];
			k++;

		}
	}
}
Player::Player() :rec(0, 0, ROWS, COLUMNS) //initializes the player structure with proper values 
{
	shield_strength = MAX_shield_strength;
	ore_collected = 0;
}
bool Player::invariant() const
{
	return (rec.getRowSize() >= 1 && rec.getColumnSize() >= 1 && shield_strength <= MAX_shield_strength);
}
int Player::getRow() const
{
	return rec.getRow();
}
int Player::getColumn() const
{
	return rec.getColumn();
}
int Player::getRowSize() const
{
	return rec.getRowSize();
}
int Player::getColumnSize() const
{
	return rec.getColumnSize();
}
bool Player::isDead() const
{
	if (shield_strength == 0)
		return true;
	else
		return false;
}
double Player::getShieldStrengthFraction() const //returns the fraction of strength left as ore reduces player shield strength
{
	double strength;
	strength = (shield_strength) / 50.0;
	return strength;
}
unsigned int Player::getOreCollected() const
{
	return ore_collected;
}
void Player::draw(Buffer& buff) const
{
	int row = rec.getRow();
	int column = rec.getColumn();
	for (int i = 0; i < Player::ROWS; i++)
	{
		for (int j = 0; j < Player::COLUMNS; j++)
		{
			buff.setCell(playerImage[i][j], row + i, column + j);//Loads each element in ship image array to the buffer 
		}
	}
}
void Player::setPosition(int row1, int column1)
{
	rec.setPosition(row1, column1);
	assert(invariant());

}
void Player::move(int row_change, int column_change)
{
	rec.move(row_change, column_change);
	assert(invariant());

}
void Player::reduceShieldStrength(unsigned int reduceOreValue) //reduces player shield strength by ore value or 0 if ore value is greater than shield strength
{
	if (shield_strength >= reduceOreValue)
		shield_strength = shield_strength - reduceOreValue;
	else if (shield_strength < reduceOreValue)
		shield_strength = 0;
	assert(invariant());
}
void Player::increaseOreCollected(unsigned int oreValue)
{
	ore_collected += oreValue;
	assert(invariant());
}
void Player::update() //makes the shield strength increment with movement of ship 
{
	if (shield_strength < MAX_shield_strength)
		shield_strength = shield_strength + 1;
	assert(invariant());
}
void Player::printStatusBar(unsigned int length, double fraction) const //prints a bar of stars and dashes based on length of line and the fraction passed to the function
{
	cout << "|";
	double star = (length - 2)*fraction;
	int x = round(star);  //rounds the fractions into nearest int values to be nicely used in the for loops, x used as a temp variable
	double dash = (length - 2)*(1 - fraction);
	int x1 = round(dash); //rounds the fractions into nearest int values to be nicely used in the for loops, x1 used as a temp variable
	for (int i = 0; i < x; i++)
		cout << "*";
	for (int i = 0; i < x1; i++)
		cout << "-";
	cout << "|";
}
void Player::printStatusRow() const //Prints the row under the buffer with shield strength, power and the ore collected value
{
	cout << "Shields ";
	printStatusBar(22, Player::getShieldStrengthFraction());
	cout << "   Power: ";
	printStatusBar(7, 1);
	cout << "   Ore: ";
	cout << setw(5) << setfill('0') << Player::getOreCollected() << endl;
}
Player::Player(const Player& original)
{
	rec = original.rec;
}
Player& Player::operator= (const Player& original)
{
	if (this != &original)
	{
		rec = original.rec;
		shield_strength = original.shield_strength;
		ore_collected = original.ore_collected;
	}
	assert(invariant());
	return *this;
}
const Rectangle& Player::getRectangle() const
{
	return rec;
}
Player::~Player()
{
}