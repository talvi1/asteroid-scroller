#include <iostream>
#include "Game.h"
#include "Buffer.h"
#include <cassert>

using namespace std;


Game::Game() :play()
{
	play.setPosition(SHIP_ROW, SHIP_COLUMN);
	for (int i = 0; i < ENEMY_COUNT; i++) //loop that loads each asteroid and sets its position to a random spot in the buffer
	{
		enemy_array[i] = createRandomEnemy();
		enemy_array[i]->setPosition(rand() % (Buffer::ROWS - 6) + 1, rand() % (Buffer::COLUMNS + 29) + (Buffer::COLUMNS / 2));
	}
	count = 0;
}
void Game::loadAllImages()
{

	for (int i = 0; i < ENEMY_COUNT; i++) //loop that loads each asteroid and sets its position to a random spot in the buffer
	{
		Asteroid::loadImage();
	}
	Player::loadImage();
	SpaceMine::loadImage();
	Scout::loadImage();
}
void Game::draw()
{
	Buffer buff;
	buff.clear();
	buff.setOffSet(0, count);
	play.draw(buff);
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		enemy_array[i]->draw(buff);
	}
	buff.print();
	play.printStatusRow();
}
bool Game::isCollision(const Player& play, const Enemy& en)
{
	return en.getRectangle().isOverlapping(play.getRectangle());
}
void Game::check()
{

	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		bool value = isCollision(play, *enemy_array[i]);// calls function to check if spaceship and asteroid collide
		if (value == true) //if collision is detected ore values are updated accordingly 
		{
			play.increaseOreCollected(enemy_array[i]->getOreValue());
			play.reduceShieldStrength(enemy_array[i]->getShieldCost());
			enemy_array[i]->markDead();
		}
	}
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if (enemy_array[i]->getColumn() + enemy_array[i]->getColumnSize() <= count) //if asteroid moves outside the buffer asteroid ore value is zero
			enemy_array[i]->markDead();
	}
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		if (enemy_array[i]->isDead()) //Detects if asteroid is dead
		{
			delete enemy_array[i];
			enemy_array[i] = createRandomEnemy();
			enemy_array[i]->setPosition(rand() % (Buffer::ROWS - 6) + 1, rand() % (count + (Buffer::COLUMNS+(Buffer::COLUMNS/2)) - 1) + (count + Buffer::COLUMNS)); //assigns random position to asteroid within the buffer
		}
	}
}
void Game::moveDown()
{

	if (play.getRow() > Buffer::ROWS - 6)
		play.move(0, 1);
	else
		play.move(1, 1);
	count++;
	play.update();
	for (int i = 0; i < ENEMY_COUNT; i++)
		enemy_array[i]->update();
	check();
}
void Game::moveStraight()
{

	play.move(0, 1);
	count++;
	play.update();
	for (int i = 0; i < ENEMY_COUNT; i++)
		enemy_array[i]->update();
	check();
}
void Game::moveUp()
{

	if (play.getRow() < 1) //No player movement if ship row is reaching top of buffer 
		play.move(0, 1);
	else
		play.move(-1, 1); //else the ship moves up if w is entered
	count++; //count variable is incremented with each movement
	play.update(); //updates the ship strength if input is detected
	for (int i = 0; i < ENEMY_COUNT; i++)
		enemy_array[i]->update();
	check();
}
bool Game::isOver() const
{
	bool val = play.isDead();
	if (val == true) // checks if player is dead, and closes the game accordingly
	{
		return false;
		cout << "Game Over" << endl;
	}
	else
		return true;
}
Game::Game(const Game& original)
{

	count = original.count;
	play = original.play;
	for (int i = 0; i < ENEMY_COUNT; i++)
		enemy_array[i] = original.enemy_array[i]->getClone();
}
Game& Game::operator= (const Game& original)
{
	if (this != &original)
	{
		count = original.count;
		play = original.play;
		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			delete enemy_array[i];
			enemy_array[i] = original.enemy_array[i]->getClone();
		}
	}
	return *this;
}
Game::~Game()
{
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		delete enemy_array[i];
		enemy_array[i] = nullptr;
	}
}
Enemy* Game::createRandomEnemy()
{
	Enemy *pe;
	int num = rand() % 30;

	if (num < 5)
	{
		pe = new SpaceMine();
	}
	if (num > 5 && num < 15)
	{
		pe = new Scout();
	}
	else
	{
		pe = new Asteroid();
	}
	return pe;
}