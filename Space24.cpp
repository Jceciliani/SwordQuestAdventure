/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 24 of 25 in the game
*/

#include "Space24.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space24::Space24()
{
	name = "Volcano Lvl. 4";
	shortForm = "The path starts to wind up the mountain at a much steeper pace. There is a small\n"
	"landing before the trail cuts in and up the volcano.  In the middle of the landing is a lever.\n";
	longForm = "The path starts to wind up the mountain at a much steeper pace. There is a small\n"
	"landing before the trail cuts in and up the volcano.  In the middle of the landing is a small lever. \n\n"
	"The path to the north continues up the volcano.\n";
	id = 24;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space24::~Space24()
{}
void Space24::addToContainer(Objects obj)
{
	space24.push_back(obj);
}

void Space24::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space24.size(); i++)
	{
		if(space24[i].getName() == obj.getName())
		{
			space24.erase(space24.begin() + i);
			return;
		}
	}

}

void Space24::printContainer()
{
	for(int i = 0; i < space24.size(); i++)
	{
		cout << space24[i].getName() << endl;
	}	
}

void Space24::look(string thing)
{
	if (strcmp(thing, "lever"))
	{
			cout << "a large metal lever. the area seems bare so youre not reall sure" << endl;
			cout << "what it could trigger." << endl;
	}

	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space24::pull(string thing)
{
	if (strcmp(thing, "lever"))
	{
			cout << "as you move the lever you hear large gears begin to grinding, though you are not sure" << endl;
			cout << "where it is coming from. as you finish pulling you hear a large THUD and you feel the " << endl;
			cout << "ground shift. an instant later you feel the entire landing lift up and hurl you through" << endl;
			cout << "the air, like a catapult. you are sent soaring down the mountian and impact the ground" << endl;
			cout << "HARD. when you are able to resurvey your surrounding you find that you have been thrown" << endl;
			cout << "back to the base of the volcano." << endl;
	}

	else
		{
			cout << "you cant do that" << endl;
		}
}