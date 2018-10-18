/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 1 of 25 in the game
*/

#include "Space1.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space1::Space1()
{
	name = "Space1";
	shortForm = "You arrive in a grassy clearing. A pleasant breeze blows from seemingly nowhere.";
	longForm = "You arrive in a grassy clearing. A pleasant breeze blows from seemingly nowhere. \n\n
	To the east you see a cobblestone path\n
	To the south is a trail into the thick brush\n";
	id = 1;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space1::~Space1()
{}

string Space1::getName()
{
	return name;
}

string Space1::getShortForm()
{
	return shortForm;
}

string Space1::getLongForm()
{
	return longForm;
}

void Space1::printSpace()
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

int Space1::getId()
{
	return id;
}