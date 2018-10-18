/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 4 of 25 in the game
*/

#include "Space4.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space4::Space4()
{
	name = "Space4";
	shortForm = "The mouth of the sewer opens up into the ocean. The waves look rough today. \n
	There is a small wooden bridge connecting the eastern and western parts of the sewers.";
	longForm = "The mouth of the sewer opens up into the ocean. The waves look rough today. \n
	There is a small wooden bridge connecting the eastern and western parts of the sewers. \n\n
	To the east you see the sewer tunnels continue \n
	To the west you see the sewer tunnels continue \n";
	id = 4;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space4::~Space4()
{}

string Space4::getName()
{
	return name;
}

string Space4::getShortForm()
{
	return shortForm;
}

string Space4::getLongForm()
{
	return longForm;
}

void Space4::printSpace()
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

int Space4::getId()
{
	return id;
}
