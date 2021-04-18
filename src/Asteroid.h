#ifndef __ASTEROID_H__
#define __ASTEROID_H__

#include "Enemy.h"

class Asteroid : public Enemy
{
private:
	unsigned int ore_value;
	bool invariant() const;
public:
	static const int ROWS = 3;
	static const int COLUMNS = 4;
	static void loadImage(); //Loads the asteroid image into a 2d array
	Asteroid();	//intializes the asteroid values
	Asteroid(const Asteroid& original); //copy constructor for asteroid
	Asteroid& operator= (const Asteroid& original); //overloading equal operator for asteroid
	virtual ~Asteroid(); //virtual implementation of destructor
	virtual bool isDead() const;  //checks if asteroid is dead, returns true or false
	virtual unsigned int getOreValue() const;  //returns ore value of asteroid
	virtual unsigned int getShieldCost() const; //return shield cost of asteroid same as ore value
	virtual void draw(Buffer& buffer) const; //draws the asteroid into buffer
	virtual Enemy* getClone() const; //clones the asteroid and returns an enemy pointer
	virtual void markDead(); //makes ore value zero
};

#endif