#ifndef __SCOUT_H__
#define __SCOUT_H__

#include "Enemy.h"

class Scout : public Enemy
{
private:
	unsigned int ore_value;
	unsigned int shield_cost;
	bool dead;
public:
	static const int ROWS = 1;
	static const int COLUMNS = 5;
	static void loadImage(); //Loads the asteroid image into a 2d array
	Scout();	//intializes the asteroid values
	Scout(const Scout& original); //copy constructor for scout
	Scout& operator= (const Scout& original); //equal overloading operator for socut
	virtual ~Scout(); //destructor for scout 
	virtual bool isDead() const; //checks if scout is dead  
	virtual unsigned int getOreValue() const; //gets ore value of scout 
	virtual unsigned int getShieldCost() const; //gets shield cost of scout
	virtual void draw(Buffer& buffer) const; //draws scout to buffer
	virtual Enemy* getClone() const; //makes another scout using dynamicall allocated space and returns a pointer to an enemy
	virtual void markDead(); //makes scout dead
	virtual void update(); //updates scout to move faster
};

#endif
