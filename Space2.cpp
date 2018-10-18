/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 2 of 25 in the game
*/

#include "Space2.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space2::Space2()
{
	name = "Space2";
	shortForm = "You arrive at the end of the path to find what ages ago must have been a larger\n
	complex, now appears to be a single hulking ruin. You see various remains periodically\n
	peeking through the rubble.";
	longForm = "You arrive at the end of the path to find what ages ago must have been a larger\n
	complex, now appears to be a single hulking ruin. You see various remains periodically\n
	peeking through the rubble. \n\n
	To the west you see a cobblestone path leading to a clearing\n";
	id = 2;
	obj = new Forge_Hammer();
	combatEncounter = false;
	visited = false;
}

Space2::~Space2()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space2::getName()
{
	return name;
}

string Space2::getShortForm()
{
	return shortForm;
}

string Space2::getLongForm()
{
	return longForm;
}

void Space2::printSpace()
{
	if (visited == false)
	{
		cout << "Current Location: " << getName() << endl;
		cout << getLongForm() << endl;
	}
	else
	{
		cout << "Current Location: " << getName() << endl;
		cout << getShortForm() << endl;
	}
}

int Space2::getId()
{
	return id;
}