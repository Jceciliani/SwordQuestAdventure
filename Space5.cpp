/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 5 of 25 in the game
*/

#include "Space5.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space5::Space5()
{
	name = "Eastern Sewers";
	shortForm = "Foul scents waft up from the waterway, moss and mildew cover the sewer walls.\n"
	"You see a small corporeal form in the corner.\n";
	longForm = "Foul scents waft up from the waterway, moss and mildew cover the sewer walls.\n"
	"You see a small corporeal form in the corner. \n\n"
	"To the west down the walkway you see a bright light and an opening to outside. \n"
	"To the south there is a ladder leading up \n";
	id = 5;
	obj = new Two_Handed_Silver_Sword();
	combatEncounter = false;
	visited = false;
}

Space5::~Space5()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
void Space5::addToContainer(Objects obj)
{
	space5.push_back(obj);
}

void Space5::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space5.size(); i++)
	{
		if(space5[i].getName() == obj.getName())
		{
			space5.erase(space5.begin() + i);
			return;
		}
	}

}

void Space5::printContainer()
{
	for(int i = 0; i < space5.size(); i++)
	{
		cout << space5[i].getName() << endl;
	}	
}

