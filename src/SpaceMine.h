#ifndef __SPACEMINE_H__
#define __SPACEMINE_H__

#include "Enemy.h"

class SpaceMine : public Enemy
{
private:
	unsigned int ore_value;
	unsigned int shield_cost; 
	bool dead; 
public:
	static const int ROWS = 2;
	static const int COLUMNS = 3;
	static void loadImage(); //Loads the asteroid image into a 2d array
	SpaceMine();	//intializes the asteroid values
	SpaceMine(const SpaceMine& original); //copy constructor for spacemine
	SpaceMine& operator= (const SpaceMine& original); //overloading operator for making an equal spacemine 
	virtual ~SpaceMine(); //destructor for spacemine
	virtual bool isDead() const; //checks if spacemine is dead
	virtual unsigned int getOreValue() const; //gets orevalue of spacemine
	virtual unsigned int getShieldCost() const; //gets shield cost of spacemine
	virtual void draw(Buffer& buffer) const; //draws spacemine into the buffer
	virtual Enemy* getClone() const; //clones the enemy spacemine using a pointer to a new dynamicall allocated spacemine
	virtual void markDead(); //makes orevalue zero, making spacemine dead
};

#endif
