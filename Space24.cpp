/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 24 of 25 in the game
*/

#include "Space24.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space24::Space24()
{
	name = "Space24";
	shortForm = "The path starts to wind up the mountain at a much steeper pace. There is a small\n
	landing before the trail cuts in and up the volcano.  In the middle of the landing is a small lever.";
	longForm = "The path starts to wind up the mountain at a much steeper pace. There is a small\n
	landing before the trail cuts in and up the volcano.  In the middle of the landing is a small lever. \n\n
	The path to the west leads back down \n
	The path to the north continues up the volcano.\n";
	id = 24;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space24::~Space24()
{}

string Space24::getName()
{
	return name;
}

string Space24::getShortForm()
{
	return shortForm;
}

string Space24::getLongForm()
{
	return longForm;
}

void Space24::printSpace()
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

int Space24::getId()
{
	return id;
}

