#include <iostream>
#include <fstream>
#include <string>

#include "Buffer.h"

using namespace std;
static const char BUFFER_EMPTY = ' ';
static const char BUFFER_BORDER = '#';

Buffer::Buffer()
{
	rowOffSet = 0;
	colOffSet = 0;
	clear();

}
void Buffer::clear()//Clears the buffer by assigning each element the empty character
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			buff[i][j] = BUFFER_EMPTY;
		}
	}
}
void Buffer::print()//Prints the 2d buffer by first printing the border row, then printing border characters and 
//empty characters in each row and then goes onto print each row and then the last border row 
{

	for (int i = 0; i < COLUMNS; i++)
		cout << BUFFER_BORDER;
	cout << endl;
	for (int i = 0; i < ROWS; i++)
	{
		cout << BUFFER_BORDER;
		for (int j = 1; j < COLUMNS - 1; j++)
		{
			cout << buff[i][j];
		}
		cout << BUFFER_BORDER;
		cout << endl;
	}
	for (int i = 0; i < COLUMNS; i++)
		cout << BUFFER_BORDER;
	cout << endl;
}
void Buffer::setCell(char value, int row, int col) //function checks if a row or column are below zero if not assigns a 
// character to to a buffer array element corresponding to a row and a column location
{
	row = row - rowOffSet;
	col = col - colOffSet;
	if (row < 0)
		return;
	if (col < 0)
		return;
	if (row < ROWS && col < COLUMNS)
	{
		buff[row][col] = value;
	}
}
void Buffer::setOffSet(int row, int col)
{
	rowOffSet = row;
	colOffSet = col;
}