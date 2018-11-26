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
	name = "Swamp";
	shortForm = "the majority of the room is submerged in a murky liquid.\n"
	" There is a narrow rope bridge that crosses to the eastern wall. A small \n"
	"mossy island is in the middle of the room\n";
	longForm = "The room is covered in moss and vegetation. the hot, moist air causes \n"
		" you clothes and armor to sick uncomfortable to your skin. the majority of the room \n"
		" is submerged in a murky liquid. There is a narrow rope bridge that crosses to the eastern wall. A small \n"
		"mossy island is in the middle of the room \n\n";

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
		cout << "plants, not too interesting." << endl;

		}
	else if (strcmp(thing, "rope bridge") == 0 || strcmp(thing, "bridge") == 0)
	{
		cout << "a bridge made from rope and wooden planks. The bridge is fairly low," << endl;
		cout << "almost touching the water. Seems sturdy enough to cross" << endl;
	}
	else if (strcmp(thing, "liquid") == 0)
	{
		cout << "its a pale brown-green color. That plus the thin film across the" << endl;
		cout << " top makes it difficult to discern anything beneath the surface. Mysterious bubbles" << endl;
		cout << "come up below. You might not be alone." << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}



void Space7::jump(const char* thing)
{
	if (strcmp(thing, "island") == 0)
	{
		cout << "you cross over the murky waters to the solid island." << endl;
		cout << "You could probably make it to either opening from here" << endl;
		jumped = true;

	}
	else if (strcmp(thing, "west") == 0 || strcmp(thing, "south") == 0)
	{
		if (jumped == true)
		{
			cout << "you make it to the landing" << endl;
			jumped = false;
		}
		else
		{
			cout << "you cant do that" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space7::run(const char* thing)
{

	if (strcmp(thing, "bridge") == 0)
	{
		if (jumped == true)
		{
			cout << "you cant reach anything from the island. try jumping back to a shore" << endl;
		}
		else 
		{
			cout << "you run across the bridge. You can feel something barely" << endl;
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
			cout << "you cant reach anything from the island. try jumping back to a shore" << endl;
		}
		else
		{
			if (!crossed)
			{
				cout << "you run across the bridge. You can feel something barely" << endl;
				cout << "grazing your heels but you make it across without incident." << endl;
				crossed = true;
			}
			else {
				cout << "you cant do that. the bridge heads south from here" << endl;
			}
		}
	}
	else if (strcmp(thing, "south") == 0)
	{
		if (jumped == true)
		{
			cout << "you cant reach anything from the island. try jumping back to a shore" << endl;
		}
		else
		{
			if (crossed)
			{
				cout << "you run across the bridge. You can feel something barely" << endl;
				cout << "grazing your heels but you make it across without incident." << endl;
				crossed = false;
			}
			else {
				cout << "you cant do that. the bridge heads west from here" << endl;
			}
		}
	}
}