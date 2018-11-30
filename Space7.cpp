/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 7 of 25 in the game
*/

#include "Space7.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space7::Space7()
{
	name = "swamp";
	shortForm = "The majority of the room is submerged in a murky liquid.\n"
	"There is a narrow rope bridge that crosses to the western wall. A small \n"
	"mossy island is in the middle of the room\n\n"
	"To the east is a small opening through the brush leading into the Jungle \n"
	"To the south is a path leading back to the Crossroads, thick with vegetation\n";
	longForm = "The room is covered in moss and vegetation. The hot, moist air causes \n"
		"your clothes and armor to stick uncomfortably to your skin. The majority of the room \n"
		"is submerged in a murky liquid. There is a narrow rope bridge that crosses to the western wall. A small \n"
		"mossy island is in the middle of the room \n\n"
	"To the east is a small opening through the brush leading into the Jungle \n"
	"To the south is a path leading back to the Crossroads, thick with vegetation\n";

	id = 7;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	jumped = false;
	crossed = false;
}

Space7::~Space7()
{}

void Space7::look(const char* thing)
{
	if (strcmp(thing, "moss") == 0 || strcmp(thing, "vegetation") == 0)
		{
		cout << "Plants. Not too interesting." << endl;

		}
	else if (strcmp(thing, "rope bridge") == 0 || strcmp(thing, "bridge") == 0)
	{
		cout << "A bridge made from rope and wooden planks. The bridge is fairly low," << endl;
		cout << "almost touching the water. Seems sturdy enough to cross" << endl;
	}
	else if (strcmp(thing, "liquid") == 0)
	{
		cout << "It's a pale brown-green color. That plus the thin film across the" << endl;
		cout << "top makes it difficult to discern anything beneath the surface. Mysterious bubbles" << endl;
		cout << "come up below. You might not be alone." << endl;
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}



void Space7::jump(const char* thing)
{
	if (strcmp(thing, "island") == 0)
	{
		cout << "You cross over the murky waters to the solid island." << endl;
		cout << "You could probably make it to either opening from here" << endl;
		jumped = true;

	}
	else if (strcmp(thing, "west") == 0 || strcmp(thing, "south") == 0)
	{
		if (jumped == true)
		{
			cout << "You make it to the landing" << endl;
			jumped = false;
			if (strcmp(thing, "west") == 0) 
			{
				crossed = true;
			}
			else
			{
				crossed = false;
			}
		}
		else
		{
			cout << "You cant do that" << endl;
		}
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}

void Space7::run(const char* thing)
{

	if (strcmp(thing, "bridge") == 0)
	{
		if (jumped == true)
		{
			cout << "You can't reach anything from the island. Try jumping back to a shore" << endl;
		}
		else 
		{
			cout << "You run across the bridge. You can feel something barely" << endl;
			cout << "grazing your heels but you make it across without incident." << endl;
			if (crossed)
			{
				crossed = false;
			}
			else
			{
				crossed = true;
			}
		}
	}
	else if (strcmp(thing, "west") == 0)
	{
		if (jumped == true)
		{
			cout << "You can't reach anything from the island. Try jumping back to a shore" << endl;
		}
		else
		{
			if (crossed == false)
			{
				cout << "You run across the bridge. You can feel something barely" << endl;
				cout << "grazing your heels but you make it across without incident." << endl;
				crossed = true;
			}
			else {
				cout << "You cant do that. The bridge heads south from here" << endl;
			}
		}
	}
	else if (strcmp(thing, "south") == 0)
	{
		if (jumped == true)
		{
			cout << "You cant reach anything from the island. Try jumping back to a shore" << endl;
		}
		else
		{
			if (crossed == true)
			{
				cout << "You run across the bridge. You can feel something barely" << endl;
				cout << "grazing your heels but you make it across without incident." << endl;
				crossed = false;
			}
			else {
				cout << "You cant do that. The bridge heads west from here" << endl;
			}
		}
	}
}
