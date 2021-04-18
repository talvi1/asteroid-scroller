//Purpose: A side scrolling game that uses a textbased visual interface to show movement of asteroid and player 
//
//
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Game.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	Game game;
	Game gameS(game);
	Buffer buff;

	game.loadAllImages();

	//Count variable used to increment movement in the game 
	string input;
	bool flag = false;
	bool continue_game = true; //condition for game continuation
	while (continue_game) //input from user and runs until program is terminated inside the loop
	{
		game.draw();
		cout << "Next ? ";
		getline(cin, input);
		{
			if (input[0] == 'r') //saves game at a certain point in time
			{
				flag = true;
				gameS = game;
			}
			if (input[0] == 'w')
			{
				game.moveUp();

			}
			if (input[0] == 's') //keeps player ship static but moves the asteroid 
			{
				game.moveStraight();

			}
			if (input[0] == 'x') //Move player ship down
			{
				game.moveDown();

			}
			if (input[0] == 'q') //Closes the game 
				continue_game = false;

			bool val = game.isOver();

			if (val == false && flag == true) // checks if player is dead and r has been pressed and continues the game accordingly from saved position
			{
					cout << flag;
					game = gameS;
			}
			if (val == false && flag == false) //Game is over if these conditions are false
			{
				cout << "Game Over" << endl;
				continue_game = false;
			}
			else
				continue;
		}
	}
	return 0;
}