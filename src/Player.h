#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Buffer.h"
#include "Rectangle.h"

class Player
{
private:
	bool invariant() const; //invariant function for making sure conditions are right
	Rectangle rec;
	unsigned int shield_strength;
	unsigned int ore_collected;
public:

	static const int ROWS = 5;
	static const int COLUMNS = 7;
	Player();
	static void loadImage(); //loads image for player
	Player(const Player& player); //copy constructor for player
	Player& operator= (const Player& player); //Overloading operator for player 
	~Player(); //Player destructor
	int getRow() const;
	int getColumn() const;
	int getRowSize() const;
	int getColumnSize() const; 
	bool isDead() const; //player is dead or not
	double getShieldStrengthFraction() const; //returns shield strength fraction
	unsigned int getOreCollected() const; //increases ore collected
	void draw(Buffer& buff) const; //draws the player to buffer
	void printStatusBar(unsigned int length, double fraction) const; //prints status bar for 
	void printStatusRow() const; //prints the whole row for status
	void setPosition(int row1, int column1); //sets position of player using rectangle class 
	void move(int row_change, int column_change); //moves the player using rectangle class
	void reduceShieldStrength(unsigned int oreValue); 
	void increaseOreCollected(unsigned int oreValue);
	void update();
	const Rectangle& getRectangle() const; //returns rectangle


};
//
// loadImage
//
// Purpose: Loads the characters from a file into a 2d array.
// Parameters(s): NA
// Precondition: Only works if player file can be opened
//				 and contains characters inside to read
// Return: NA
// Side effect: Stores character values in a string and then 
//				assigns them to a global 2d array within 
//				Player.cpp
//
//
// Player()
//
// Purpose: Initialize the values for the player structure
// Parameters(s): NA
// Precondition: NA
// Return: NA
// Side effect: Pass by reference changes values in the original 
//				declared struct in the main function
//
//
// getRow
//
// Purpose: Return a int value for current player row
// Parameters(s): NA
// Precondition: NA
// Return: int value belonging to Player row 
// Side effect: NA
//
//
// getColumn
//
// Purpose: Return a int value for current player column
// Parameters(s): NA
// Precondition: NA
// Return: int value belonging to Player column 
// Side effect: NA
//
// getRowSize
//
// Purpose: Return a int value for current player row size
// Parameters(s): NA
// Precondition: NA
// Return: int value belonging to Player row_size
// Side effect: NA
//
//
// getColumnSize
//
// Purpose: Return a int value for current player column size
// Parameters(s): NA
// Precondition: NA
// Return: int value belonging to Player column_size
// Side effect: NA
//
//
// isDead
//
// Purpose: Return a bool value of true if player shield strength is zero 
//			otherwise returns false
// Parameters(s): NA
// Precondition: NA
// Return: bool value of true or false 
// Side effect: NA
//
//
// getShieldStrengthFraction
//
// Purpose: Return a decimal double value for player shield strength
//			compared to max shield strength
// Parameters(s): NA
// Precondition: NA
// Return: double value of shield strength divided by max shield strength
// Side effect: NA
//
//
// getOreCollected
//
// Purpose: Return an unsigned int value for ore collected
// Parameters(s): NA
// Precondition: NA
// Return: unsigned int value belonging to Player ore_collected
// Side effect: NA
//
//
// draw
//
// Purpose: Adding the player image into the buffer
// Parameters(s): const reference to Buffer class
// Precondition: NA
// Return: NA
// Side effect: Uses two for loops to take individual characters from 
//				player image and adds them to buffer using buffersetcell
//
//
// setPosition
//
// Purpose: Adding the player image into the buffer
// Parameters(s): int row and column variables
// Precondition: NA
// Return: NA
// Side effect: Sets the row and column values of the player to the values
//				passed as arguments to the functions
//
//
// move
//
// Purpose: Responsible for player movement up and down
// Parameters(s): int change row and change column variables
// Precondition: NA
// Return: NA
// Side effect: Increments the row and column values in player by the values
//				passed to the function
//
//
// reduceShieldStrength
//
// Purpose: Reducing shield strength by subtracting the ore value
//			of the asteroid hitting the player
// Parameters(s): Player variable, unsigned int ore value to subtract
// Precondition: NA
// Return: NA
// Side effect: Subtracts ore value from the shield strength
//
//
// increaseOreCollected
//
// Purpose: Increases ore_collected by ore value of asteroid
// Parameters(s): unsigned int oreValue of the asteroid
// Precondition: NA
// Return: NA
// Side effect: Adds oreValue to player ore_collected
//
//
// update
//
// Purpose: Increase player shield strength
// Parameters(s): NA
// Precondition: NA
// Return: NA
// Side effect: Increase the shield strength of player after it is damaged
//				with respect to movement
//
//
// printStatusBar
//
// Purpose: Printing a bar of stars and dashes with a constant length and 
//			stars and dashes amount based on fraction value
// Parameters(s): unsigned int length, length of the bar
//				  double fraction, player shieldstrength fraction
// Precondition: NA
// Return: NA
// Side effect: Uses for loops and rounding double values to int
//				to print a number of stars and dashes in a bar
//
//
// printStatusRow
//
// Purpose: Printing the row underneath buffer to indicate player information
// Parameters(s): NA
// Precondition: NA
// Return: NA
// Side effect: prints status bars of various lengths and uses setfill
//				to also print ore value following a bunch of zeros
//
#endif
