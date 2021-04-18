#include <iostream>
#include <cassert>
#include "Rectangle.h"

using namespace std;

bool Rectangle::invariant() const
{
	if (row_size >= 1 && column_size >= 1)
		return true;
	else
		return false;
}

Rectangle::Rectangle()
{
	row = 0;
	column = 0;
	row_size = 1;
	column_size = 1;
}
Rectangle::Rectangle(int row1, int column1, int row_size1, int column_size1)
{
	row = row1;
	column = column1;
	row_size = row_size1;
	column_size = column_size1;
	assert(invariant());
}
Rectangle::Rectangle(const Rectangle& original)
{
	row = original.row;
	column = original.column;
	row_size = original.row_size;
	column_size = original.column_size;
	assert(invariant());
}
Rectangle& Rectangle::operator= (const Rectangle& original)
{
	if (this != &original)
	{
		row = original.row;
		column = original.column;
		row_size = original.row_size;
		column_size = original.column_size;
	}
	assert(invariant());
	return *this;
}
Rectangle::~Rectangle()
{
}
int Rectangle::getRow() const
{
	return row;
}
int Rectangle::getColumn() const
{
	return column;
}
int Rectangle::getRowSize() const
{
	return row_size;
}
int Rectangle::getColumnSize() const
{
	return column_size;
}
bool Rectangle::isOverlapping(const Rectangle& other) const
{
	int rec1Row2 = other.getRow() + other.getRowSize();
	int rec1Column2 = other.getColumn() + other.getColumnSize();
	int rec2Row2 = getRow() + getRowSize();
	int rec2Column2 = getColumn() + getColumnSize();
	if (other.getColumn() >= rec2Column2)
		return false;
	else if (other.getRow() >= rec2Row2)
		return false;
	else if (getRow() >= rec1Row2)
		return false;
	else if (rec1Row2 >= getRow() && rec1Column2 < getColumn() + 1)
		return false;
	else
		return true;
}
void Rectangle::setPosition(int row1, int column1)
{
	row = row1;
	column = column1;
	assert(invariant());
}
void Rectangle::move(int row_change, int column_change)
{
	row += row_change;
	column += column_change;
	assert(invariant());
}
void Rectangle::setSize(int row_size1, int column_size1)
{
	row_size = row_size1;
	column_size = column_size1;
	assert(invariant());
}