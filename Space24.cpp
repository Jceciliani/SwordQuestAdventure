/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 24 of 25 in the game
*/

#include "Space24.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space24::Space24()
{
	name = "Volcano Lvl. 4";
	shortForm = "There is a small landing before the trail cuts in and up the volcano.\n"
	"In the middle of the landing is a lever.\n";
	longForm = "The path starts to wind up the mountain at a much steeper pace. There is a small\n"
		"landing before the trail cuts in and up the volcano. In the middle of the landing is a small lever. \n"
		"It's hard to tell what it could do.\n\n";

	id = 24;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space24::~Space24()
{}

void Space24::look(const char* thing)
{
	if (strcmp(thing, "lever"))
	{
			cout << "A large metal lever. The area seems bare so youre not really sure" << endl;
			cout << "what it could trigger." << endl;
	}
	if (strcmp(thing, "landing"))
	{
		cout << "There isn't really anything on the landing besides the lever, though the fact that there" << endl;
		cout << "is a landing at all is strange. Almost like a hunk of the mountian was torn out" << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space24::pull(const char* thing)
{
	if (strcmp(thing, "lever") == 0)
	{
			cout << "As you move the lever you hear large gears begin to grinding, though you are not sure" << endl;
			cout << "where it is coming from. As you finish pulling you hear a large THUD and you feel the " << endl;
			cout << "ground shift. An instant later you feel the entire landing lift up and hurl you through" << endl;
			cout << "the air, like a catapult. you are sent soaring down the mountian and impact the ground" << endl;
			cout << "HARD. When you are able to resurvey your surrounding, you find that you have been thrown" << endl;
			cout << "back to the base of the volcano." << endl;
	}

	else
	{
		cout << "You can't do that" << endl;
	}
}
