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
	name = "Volcano Lvl. 1";
	shortForm = "On the side of the path you see a large boulder.\n";
	longForm = "The path  widens a bit before tapering back an continuing up. Small flakes of ash \n"
		"float in the air around you. On the side of the path you see a large boulder. \n\n";

	id = 21;
	obj = new Two_Handed_Gold_Sword();
	combatEncounter = false;
	visited = false;
	boulderMoved = false;
}

Space21::~Space21()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space21::look(char* thing)
{
	if (strcmp(thing, "boulder"))
	{

			cout << "a large rock . not much to say. You could probably move it if you wanted" << endl;

	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space21::push(char* thing)
{
	if (strcmp(thing, "boulder"))
	{
		if(boulderMoved)
		{
			cout << "you had enough excitment moving it the first time" << endl;
		}
		else
		{
			cout << "like something out of a training montage you some how manage " << endl;
			cout << "to move the boulder a few feet. It feels a bit anti-climatic" << endl;
			cout << "but then you see a gold sword in the spot that the boulder used to be in. LUCKY! " << endl;
			boulderMoved = true;
		}
	}
	else
		{
			cout << "you cant do that" << endl;
		}
}