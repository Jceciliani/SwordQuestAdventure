/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 10 of 25 in the game
*/

#include "Space10.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space10::Space10()
{
	name = "Upper Maintenance";
	shortForm = " In the corner you see a small hovel made of bone,. Metal scraps, and dung.\n";
	longForm = "You arrive on the end of the walkway. There it is a moderately sized stone \n"
		"platform. In the corner you see a small hovel made of bone,. Metal scraps, and dung. \n\n";

	id = 10;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}
Space10::~Space10()
{}

void Space10::look(const char* thing)
{
	if (strcmp(thing, "corner") == 0|| strcmp(thing, "hovel") == 0)
		{
		cout << "the hovel is very disgusting, there is a small sack next to what you can" << endl;
		cout << "guess is a bed" << endl;

		}

	else if (strcmp(thing, "sack") == 0)
	{
		cout << "a small burlap full of something. you cant tell what just from looking" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space10::search(const char* thing)
{
	if (strcmp(thing, "sack") == 0)
		{
		cout << "nope. Nothing useful. Just more feces." << endl;
		}
	else
	{
		cout << "you cant do that" << endl;
	}
}