/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 3 of 25 in the game
*/

#include "Space3.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space3::Space3()
{
	name = "Space3";
	shortForm = "The sewer walkways are grimy and slick. It's not hard to imagine with what. \n
	There appears to be a fishing basket of some kind in the sewer waterway.";
	longForm = "The sewer walkways are grimy and slick. It's not hard to imagine with what. \n
	There appears to be a fishing basket of some kind in the sewer waterway. \n\n
	To the south are stairs leading up to a door \n
	Down the walkways to the east there is bright light and an opening to outside \n";
	id = 3;
	obj = new Bronze_Armor();
	combatEncounter = false;
	visited = false;
}

Space3::~Space3()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space3::getName()
{
	return name;
}

string Space3::getShortForm()
{
	return shortForm;
}

string Space3::getLongForm()
{
	return longForm;
}

void Space3::printSpace()
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

int Space3::getId()
{
	return id;
}