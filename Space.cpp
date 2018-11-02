/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Base Space class for all 25 spaces in the game
*/

#include "Space.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space::Space()
{
	name = "No name";
	shortForm = "";
	longForm = "";
	id = 0;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space::~Space()
{}

string Space::getName()
{
	return name;
}

string Space::getShortForm()
{
	return shortForm;
}

string Space::getLongForm()
{
	return longForm;
}

void Space::printSpace()
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

int Space::getId()
{
	return id;
}

Space* Space::getNorth()
{
	return north;
}

Space* Space::getEast()
{
	return east;
}

Space* Space::getSouth()
{
	return south;
}

Space* Space::getWest()
{
	return west;
}

Objects Space::getObject()
{
	return *obj;
}
// TEST****************************************8
void Space::addToContainer(Objects obj)
{
	space.push_back(obj);	
}

void Space::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space.size(); i++)
	{
		if(space[i].getName() == obj.getName())
		{
			space.erase(space.begin() + i);
			return;
		}
	}

}		

void Space::printContainer()
{
	for(int i = 0; i < space.size(); i++)
	{
		cout << space[i].getName() << endl;
	}	
}


void Space::setDirections(Space* N, Space* E, Space* S, Space* W)
{
	north = N;
	east = E;
	south = S;
	west = W;
}

bool Space::getEncounter()
{
/*
	if (combatEncounter == false)
	{
		combatEncounter = true;
		return false;
	}
	else
	{
		return true;
	}
*/
	return combatEncounter;
}

void Space::setEncounter()
{
	combatEncounter = true;
}

bool Space::getVisited()
{

	if (visited == false)
	{
		visited = true;
		return false;
	}
	else
	{
		return true;
	}
}
