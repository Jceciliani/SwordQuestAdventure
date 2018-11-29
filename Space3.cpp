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
	shortForm = "The walkways are grimy and slick There appears to be a fishing basket of some kind in the sewer waterway.\n"
	"To the south are stairs leading up to the Guard Quarters \n"
		"Down the walkways to the east there is bright light coming from the Sewer Depths \n";
	longForm = "The walkways are grimy and slick. It's not hard to imagine with what. \n"
		"old pipes and cobwebs line the sewer walls. There appears to be a fishing basket \n"
		"of some kind in the sewer waterway. \n\n"
		"To the south are stairs leading up to the Guard Quarters \n"
		"Down the walkways to the east there is bright light coming from the Sewer Depths \n";

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
		cout << "dont. Its gross" << endl;

	}
	else if (strcmp(thing, "basket") == 0 || strcmp(thing, "fishing basket") == 0)
	{
		cout << " a small wooden  box design to catch things flowing through the dirty" << endl;
		cout << " waterways. It is tied to the side of the walk way with a rope." << endl;
	}
	else if (strcmp(thing, "rope") == 0)
	{
		cout << "Looks to be a perfectly usable rope. it is currently attached to the fishing basket" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}
void Space3::take(const char* thing)
{
	if (strcmp(thing, "basket") == 0 || strcmp(thing, "fishing basket") == 0)
	{
		if (!ropePulled)
		{
			cout << "it is too far to reach. There must be a way to get it closer" << endl;
		}
		else
		{
			if (taken == false) {
				cout << " the basket is to big to carry. there is some bronze armor in the trap though!" << endl;
			}
			else
			{
				cout << " the basket is to big to carry." << endl;
			}
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}
void Space3::pull(const char* thing)
{
	if (strcmp(thing, "rope") == 0)
	{
		if (!ropePulled)
		{

				cout << "you pull the basket up to the side of the walkway, and look" << endl;
				cout << "into the basket. Somehow bronze armor got caught in the trap. Lucky!" << endl;
				ropePulled = true;
		}
		else
		{
			if (taken == false) {
				cout << "the basket is already next to the walkway. you can reach it and see" << endl;
				cout << "that Somehow bronze armor got caught in the trap. Lucky!" << endl;
			}
			else
			{
				cout << "you pull the basket up to the side of the walkway, and look" << endl;
				cout << "into the basket. it is empty" << endl;
			}
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}
