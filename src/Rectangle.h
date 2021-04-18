#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__


class Rectangle
{
private: 
	int row;
	int column;
	int row_size;
	int column_size;
	bool invariant() const;
public: 
	Rectangle(); //default constructor for rectangle class
	Rectangle(int row1, int column1, int row_size1, int column_size1); //Initializing constructor sets it to specific values
	Rectangle(const Rectangle& original); //Copy constructor for rectange
	Rectangle& operator=(const Rectangle& original); //Overloading operator for transferring values to another rectangle
	~Rectangle(); //Rectangle destructor
	int getRow() const; //gets rectangle row
	int getColumn() const; //gets rectangle column
	int getRowSize() const; //gets rectangle row size
	int getColumnSize() const; //gets rectangle column size
	bool isOverlapping(const Rectangle& other) const; //checks overlapping inbetween two rectangles 
	void setPosition(int row1, int column1); //sets position for a rectangle
	void move(int row_change, int column_change); //moves the rectangle 
	void setSize(int row_size1, int column_size1); //sets the size of the rectangle 
};

#endif
