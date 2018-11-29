/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 2 of 25 in the game
*/

#include "Space2.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space2::Space2()
{
	name = "Ruins";
	shortForm = "You arrive at a ruin. You see various remains periodically peeking through the rubble.\n"
	"To the west you see a cobblestone path leading to some Fields\n";
	longForm = "You arrive at the end of the path to find what ages ago must have been a larger\n"
		"complex, now appears to be a single hulking ruin. You see various remains periodically\n"
		"peeking through the rubble. the thought that the creature that did this is likly still \n"
		"here fills you with dread \n"
		"To the west you see a cobblestone path leading to some Fields\n";

	id = 2;
	obj = new Forge_Hammer();
	combatEncounter = false;
	visited = false;
	hammerFound = false;
	taken = false;
}

Space2::~Space2()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space2::look(const char* thing)
{
	if(strcmp(thing, "ruins") == 0 || strcmp(thing, "remains") == 0 )
		{
			cout << "youre no architect, so youre not really sure what kind of building this could" << endl;
			cout << "have been. The are interesting remains poking through." << endl;	
		}
	else
	{
		cout << "you cant do that" << endl;
	}	
}


void Space2::search(const char* thing)
{
	if(strcmp(thing, "ruins") == 0 || strcmp(thing, "remains") == 0)
		{
		if (hammerFound == false || taken == false) {
			cout << "most of it is less interesting upon further inspection. Broken vases," << endl;
			cout << "bones from a severed arm. There is handle that upon further inspection is" << endl;
			cout << "attached to a forge hammer." << endl;
			hammerFound = true;
		}
		else
		{
			cout << "most of it is less interesting upon further inspection. Broken vases," << endl;
			cout << "bones from a severed arm. just a whole lot of garbage in your opinion" << endl;
		}
		}
	else
	{
		cout << "you cant do that" << endl;
	}
}
