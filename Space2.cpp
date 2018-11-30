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
	"To the west you see a cobblestone path leading to some Fields\n\n";
	longForm = "You arrive at the end of the path to find what ages ago must have been a larger\n"
		"complex, now appears to be a single hulking ruin. You see various remains periodically\n"
		"peeking through the rubble. The thought that the creature that did this is likly still \n"
		"here fills you with dread \n\n"
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
			cout << "You're no architect, so you're not really sure what kind of building this could" << endl;
			cout << "have been. There are interesting remains poking through." << endl;	
		}
	else
	{
		cout << "You can't do that" << endl;
	}	
}


void Space2::search(const char* thing)
{
	if(strcmp(thing, "ruins") == 0 || strcmp(thing, "remains") == 0)
		{
		if (hammerFound == false || taken == false) {
			cout << "Most of it is less interesting upon further inspection. Broken vases," << endl;
			cout << "bones from a severed arm. There is handle that upon further inspection is" << endl;
			cout << "attached to an anvil hammer." << endl;
			hammerFound = true;
		}
		else
		{
			cout << "Most of it is less interesting upon further inspection. Broken vases," << endl;
			cout << "bones from a severed arm. Just a whole lot of garbage in your opinion" << endl;
		}
		}
	else
	{
		cout << "You can't do that" << endl;
	}
}
