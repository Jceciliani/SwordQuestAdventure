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
	shortForm = "The walkways are grimy and slick. There appears to be a fishing basket of some kind in the sewer waterway.\n";
	longForm = "The walkways are grimy and slick. It's not hard to imagine with what. \n"
		"Old pipes and cobwebs line the sewer walls. There appears to be a fishing basket \n"
		"of some kind in the sewer waterway. \n\n";

	id = 3;
	obj = new Bronze_Armor();
	combatEncounter = false;
	visited = false;
	ropePulled = false;
	taken = false;
}

Space3::~Space3()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space3::look(const char* thing)
{
	if (strcmp(thing, "walkways") == 0)
	{
		cout << "Don't. It's gross" << endl;

	}
	else if (strcmp(thing, "basket") == 0 || strcmp(thing, "fishing basket") == 0)
	{
		cout << " a small wooden box design to catch things flows through the dirty" << endl;
		cout << " waterways. It is tied to the side of the walkway with a rope." << endl;
	}
	else if (strcmp(thing, "rope") == 0)
	{
		cout << "Looks to be a perfectly usable rope. It is currently attached to the fishing basket" << endl;
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}
void Space3::take(const char* thing)
{
	if (strcmp(thing, "basket") == 0 || strcmp(thing, "fishing basket") == 0)
	{
		if (!ropePulled)
		{
			cout << "It is too far to reach. There must be a way to get it closer" << endl;
		}
		else
		{
			if (taken == false) {
				cout << " The basket is to big to carry. There is some bronze armor in the trap though!" << endl;
			}
			else
			{
				cout << " The basket is to big to carry." << endl;
			}
		}
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}
void Space3::pull(const char* thing)
{
	if (strcmp(thing, "rope") == 0)
	{
		if (!ropePulled)
		{

				cout << "You pull the basket up to the side of the walkway, and look" << endl;
				cout << "into the basket. Somehow bronze armor got caught in the trap. Lucky!" << endl;
				ropePulled = true;
		}
		else
		{
			if (taken == false) {
				cout << "The basket is already next to the walkway. You can reach it and see" << endl;
				cout << "that somehow bronze armor got caught in the trap. Lucky!" << endl;
			}
			else
			{
				cout << "You pull the basket up to the side of the walkway, and look" << endl;
				cout << "into the basket. It is empty" << endl;
			}
		}
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}
