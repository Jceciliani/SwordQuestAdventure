/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 1 of 25 in the game
*/

#include "Space1.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space1::Space1()
{
	name = "Fields";
	shortForm = "There are many tussocks of grass. A pleasant breeze blows from seemingly nowhere.\n";
	longForm = "You arrive in a grassy clearing. There are many tussocks of grass. A pleasant breeze blows from seemingly nowhere. \n"
		"You watch it ripple through the sea of green. The sight feels oddly nostalgic.";

	id = 1;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space1::~Space1()
{}




void Space1::look(const char* thing)
{
	if(strcmp(thing, "grass") == 0)
	{
		cout << "The long grass come up to your waist. Maybe there is something hidden within it." << endl; 
		cout << "Like rupees! " << endl;
	}
	else if(strcmp(thing, "wind") == 0)
	{
		cout << "No matter where you look, the wind has zero colors." << endl;	
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}


void Space1::attack(const char* thing)
{
	if(strcmp(thing, "grass") == 0)
	{
		cout << "With a “ hiyayaya!!!” you arc your sword around trimming the grass and clearing a" << endl;
		cout << "patch around you. Unfortunatly, this is not that game, so you find zero rupees." << endl;
		cout << "What would you even do with one?" << endl;	
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}



