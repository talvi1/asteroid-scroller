#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Buffer.h"
#include "Rectangle.h"

class Enemy
{
private:
	Rectangle rec;
	bool invariant() const;
public:

	Enemy();	//intializes the asteroid values
	Enemy(int row1, int column1, int row_size1, int column_size1);
	int getRow() const; //returns the current row for asteroid
	int getColumn() const; //returns the current column for asteroid
	int getRowSize() const; //returns row size of asteroid
	void setPosition(int row1, int column1); //Sets position of the astroid row and column to values passed to the function
	int getColumnSize() const; //returns asteroid column size
	virtual bool isDead() const = 0; //returns a value of true or false depending on if ore value is 0, purely virtual, to be used in derived classes 
	virtual unsigned int getOreValue() const = 0; //returns ore value of asteroid, purely virtual, to be used in derived classes
	void move(int row_change, int column_change);  //moves the asteroid as incremented
	virtual void draw(Buffer&  b) const = 0; //purely virtual draw function, to be used in derived classes
	virtual void markDead() = 0; //marks asteroid ore value as zero, to be used in derived classes, purely virtual
	virtual unsigned int getShieldCost() const = 0; //gets shield cost, to be used in derived classes, purely virtual
	Enemy(const Enemy& original); //copy constructor
	Enemy& operator= (const Enemy& original); //overloaded equal operator
	virtual ~Enemy(); //virtual destructor, can be used 
	const Rectangle& getRectangle() const; //returns rectangle
	virtual void update(); //update function, virtual, can be used in derived classes
	virtual Enemy* getClone() const = 0; //gets a clone of enemy, purely virtual, to be used in derived classes
};

#endif
