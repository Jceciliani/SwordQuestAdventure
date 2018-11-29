/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 4 of 25 in the game
*/

#include "Space4.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space4::Space4()
{
	name = "Sewer Depths";
	shortForm = "The mouth of the sewer opens up into the ocean. There is a small wooden bridge .\n";
	longForm = "The mouth of the sewer opens up into the ocean. you can hear the gulls call somewhere in \n"
		"the distance. The waves look rough today. There is a small wooden bridge connecting the eastern and western parts of the sewers. \n\n";

	id = 4;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space4::~Space4()
{}


void Space4::look(const char* thing)
{
	if (strcmp(thing, "ocean") == 0 || strcmp(thing, "opening") == 0)
	{
		cout << "You see the ocean. Between the rough waves and glimpses of shark fins," << endl;
		cout << "it's probably best to not try your luck out there" << endl;

	}
	else if (strcmp(thing, "bridge") == 0)
	{
		cout << " The wood the bridge is made from definitely looks old, but by no means" << endl;
		cout << " rotted or weak. This seems strange considering the environment," << endl;
		cout << " but there are more pressing issues. " << endl;
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}
