/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Main source code that runs the game
*/

#include "Game.hpp"
#include <iostream>
#include <string>

int main()
{
	string choice;
	bool ifError = false;


	while (1)
	{
		cout << endl;
		cout << "You awaken." << endl;
		cout << "You are sore and broken." << endl;
		cout << "You do not recognise your surroundings" << endl;
		cout << "All you do recognise is a need deep inside you" << endl;
		cout << "A need to complete your" << endl;
		cout << endl;
		cout << "  _________                       .___ ________                          __   " << endl;
		cout << " /   _____/_  _  _____________  __| _/ \\_____  \\__  _  __ ____   _______/  |_ " << endl;
		cout << " \\_____  \\\\ \\/ \\/ /  _ \\_  __ \\/ __ |   /  / \\  \\ \\/ \\/ // __ \\ /  ___/\\   __\\ " << endl;
		cout << " /        \\\\     (  <_> )  | \\/ /_/ |  /   \\_/.  \\     /\\  ___/ \\___ \\  |  |  " << endl;
		cout << "/_______  / \\/\\_/ \\____/|__|  \\____ |  \\_____\\ \\_/\\/\\_/  \\___  >____  > |__|  " << endl;
		cout << "        \\/                         \\/         \\__>           \\/     \\/        " << endl;
		cout << endl;
		cout << "1. Play Sword Quest" << endl;
		cout << "2. Load Saved Game" << endl;
		cout << "3. Exit" << endl;
		getline(cin, choice);

		// Start game
		if (choice == "1")
		{
			Game *game = new Game();
			bool loadg = false;
			game->play(loadg);
			delete game;
		}
		else if (choice == "2")
		{
			Game *game = new Game();
			bool loadg = true;
			game->play(loadg);
			delete game;
		}
		else if (choice == "3")
		{
			return 0;
		}
		else
		{
			cout << "Invalid - Please enter 1, 2 or 3" << endl;
			ifError = true;
		}

		if (ifError)
		{
			ifError = false;
		}

	}

	return 0;
}
