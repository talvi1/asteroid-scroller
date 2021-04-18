#ifndef __GAME_H__
#define __GAME_H__

#include "Player.h"
#include "Asteroid.h"
#include "SpaceMine.h"
#include "Scout.h"

class Game
{
public:
	static const int ENEMY_COUNT = 10;
private:
	static const int SHIP_ROW = 10; 
	static const int SHIP_COLUMN = 1;
	Player play; //Composition of player class in to game class
	Enemy *enemy_array[ENEMY_COUNT]; //Composition of enemy class in game class 
	int count; //variable that keeps track of screen scrolling
	bool isCollision(const Player& play, const Enemy& en); //collision between player ship and each asteroid
	void check(); //goes through all the steps if a collision happens
	Enemy *createRandomEnemy(); //creates a random enemy with various chances of each enemy appearing
public:
	Game();
	static void loadAllImages(); //loads all images and sets position
	Game(const Game& original); //copy constructor for game class
	Game& operator= (const Game& original); //Operator overload function for game class
	~Game(); //Game destructor
	bool isOver() const; //checks if game is over by checking if player is dead
	void draw(); //draws the images into the buffer
	void moveStraight(); //if s is pressed it moves it straight
	void moveUp(); //if w is pressed it moves it up
	void moveDown(); // if x is pressed it moves it down
	

};

#endif
