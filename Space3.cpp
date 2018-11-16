/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 3 of 25 in the game
*/

#include "Space3.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space3::Space3()
{
	name = "Western Sewers";
	shortForm = "The sewer walkways are grimy and slick. It's not hard to imagine with what. \n"
	"There appears to be a fishing basket of some kind in the sewer waterway.\n";
	longForm = "The sewer walkways are grimy and slick. It's not hard to imagine with what. \n"
	"There appears to be a fishing basket of some kind in the sewer waterway. \n\n"
	"To the south are stairs leading up to a door \n"
	"Down the walkways to the east there is bright light and an opening to outside \n";
	id = 3;
	obj = new Bronze_Armor();
	combatEncounter = false;
	visited = false;
	ropePulled = false;
}

Space3::~Space3()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space3::look(char* thing)
{
	if (strcmp(thing, "walkways"))
	{
		cout << "dont. Its gross" << endl;

	}
	else if (strcmp(thing, "basket") || strcmp(thing, "fishing basket"))
	{
		cout << " a small wooden  box design to catch things flowing through the dirty" << endl;
		cout << " waterways. It is tied to the side of the walk way with a rope." << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}
void Space3::take(char* thing)
{
	if (strcmp(thing, "basket") || strcmp(thing, "fishing basket"))
	{
		if (!ropePulled)
		{
			cout << "it is too far to reach. There must be a way to get it closer" << endl;
		}
		else
		{
			cout << " the basket is to big to carry. there is some bronze armor in the trap though!" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}
void Space3::pull(char* thing)
{
	if (strcmp(thing, "rope"))
	{
		if (!ropePulled)
		{
			cout << "you pull the basket up to the side of the walkway, and look" << endl;
			cout << "into the basket. Somehow bronze armor got caught in the trap. Lucky!" << endl;
		}
		else
		{
			cout << "the basket is already next to the walkway. you can reach it and see" << endl;
			cout << "that Somehow bronze armor got caught in the trap. Lucky!" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}