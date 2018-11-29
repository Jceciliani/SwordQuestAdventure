/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 23 of 25 in the game
*/

#include "Space23.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space23::Space23()
{
	name = "Volcano Lvl. 3";
	shortForm = "There is a small alcove in the face of the volcano containing various piles of valuables and trinkets.\n"
		"To the side of the alcove, there is a table of meager bread \n\n";
		longForm = "The path continues forward. You question the trails integrity as you see a few \n"
		"chunks separate themselves from the mountain. There is a small alcove in the face of the volcano\n"
		"containing various piles of valuables and trinkets. To the side of the alcove, there is a table of meager bread \n\n";
	id = 23;
	obj = new Gold_Armor();
	combatEncounter = false;
	visited = false;
	armorFound = false;
	taken = false;
}

Space23::~Space23()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space23::look(const char* thing)
{
	if (strcmp(thing, "trail") == 0)
	{
			cout << "The path ahead looks perilous. Be cautious." << endl;
	}
	else if (strcmp(thing, "piles") == 0 || strcmp(thing, "valuables") == 0 )
	{
			cout << "A small hoard that could rival king Midas. It must have taken ages" << endl;
			cout << "to collect it all. Maybe there is something useful in there, besides gold" << endl;
	}
	else if (strcmp(thing, "bread") == 0)
	{
		cout << "Bandits must have been eating before you arrived. Though not well." << endl;
		cout << "The bread appears slightly moldy and very stale" << endl;
	}
	else
		{
			cout << "You can't do that" << endl;
		}
}

void Space23::search(const char* thing)
{
	if (strcmp(thing, "piles") == 0 || strcmp(thing, "valuables") == 0 )
	{
		if (armorFound == false || taken == false) {
			cout << "Shoveling through piles of coins like they were dirt gets old really quickly." << endl;
			cout << "Luckily it doesn't take too long to find something useful. The coins and chalices part to" << endl;
			cout << "reveal a fancy set of golden armor" << endl;
			armorFound = true;
		}
		else
		{
			cout << "Shoveling through piles of coins like they were dirt gets old really quickly. You give up." << endl;
		}
	}
	else
		{
			cout << "You can't do that" << endl;
		}
}

void Space23::eat(const char* thing)
{
	if (strcmp(thing, "bread") == 0)
	{
		cout << "Moldy bread! YUM! You do not feel healthier but you feel full \n" << endl;

	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
