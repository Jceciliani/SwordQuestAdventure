 /* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 6 of 25 in the game
*/

#include "Space6.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space6::Space6()
{
	name = "Space6";
	shortForm = "You are surrounded by heavy vegetation and rotting trees covered with serpentine \n
	vines. The canopy is so think you are not sure if there is even a ceiling anymore.";
	longForm = "You are surrounded by heavy vegetation and rotting trees covered with serpentine \n
	vines. The canopy is so think you are not sure if there is even a ceiling anymore. \n\n
	To the east is a small opening through the brush \n
	To the south is a wide path marked with broken branches \n
	To the north is you can see a small clearing through the brush\n";
	id = 6;
	obj = new Silver_Armor();
	combatEncounter = false;
	visited = false;
}

Space6::~Space6()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space6::getName()
{
	return name;
}

string Space6::getShortForm()
{
	return shortForm;
}

string Space6::getLongForm()
{
	return longForm;
}

void Space6::printSpace()
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

int Space6::getId()
{
	return id;
}
