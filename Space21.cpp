/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 21 of 25 in the game
*/

#include "Space21.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space21::Space21()
{
	name = "volcano lvl. 1";
	shortForm = "On the side of the path you see a large boulder.\n\n"
	"The trail to the east continues up the volcano, slowly increasing in gradient as it approaches Volcano Lvl. 2 \n"
	"The path to the north  dissapates behind you into an ominous fog. There is no turning back \n";
	longForm = "The path widens a bit before tapering back and continuing up. Small flakes of ash \n"
		"float in the air around you. On the side of the path you see a large boulder. \n\n"
	"The trail to the east continues up the volcano, slowly increasing in gradient as it approaches Volcano Lvl. 2 \n"
		"The path to the north  dissapates behind you into an ominous fog. There is no turning back \n";

	id = 21;
	obj = new Two_Handed_Gold_Sword();
	combatEncounter = false;
	visited = false;
	boulderMoved = false;
	taken = false;
}

Space21::~Space21()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space21::look(const char* thing)
{
	if (strcmp(thing, "boulder") == 0)
	{

			cout << "A large rock. Not much to say. You could probably move it if you wanted" << endl;

	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space21::push(const char* thing)
{
	if (strcmp(thing, "boulder") == 0)
	{
		if(boulderMoved == true)
		{
			cout << "You had enough excitment moving it the first time" << endl;
		}
		else
		{
			cout << "Like something out of a training montage, you some how manage " << endl;
			cout << "to move the boulder a few feet. It feels a bit anti-climatic" << endl;
			cout << "but then you see a gold sword in the spot that the boulder used to be in. LUCKY! " << endl;
			boulderMoved = true;
		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
