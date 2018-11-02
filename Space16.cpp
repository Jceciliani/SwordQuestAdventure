/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 16 of 25 in the game
*/

#include "Space16.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space16::Space16()
{
	name = "Volcano Base";
	shortForm = " The path continues to curl up the volcano. The scent of sulfur has grown stronger. \n"
        "In the middle of the path there is a large sign post. There is a pile of bones at its base.\n";
	longForm = " The path continues to curl up the volcano. The scent of sulfur has grown stronger. \n"
	"In the middle of the path there is a large sign post. There is a pile of bones at its base. \n\n"
	"The path to the east leads back down. \n"
	"The path to the south continues up the volcano\n";
	id = 16;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space16::~Space16()
{}
void Space16::addToContainer(Objects obj)
{
	space16.push_back(obj);
}

void Space16::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space16.size(); i++)
	{
		if(space16[i].getName() == obj.getName())
		{
			space16.erase(space16.begin() + i);
			return;
		}
	}

}

void Space16::printContainer()
{
	for(int i = 0; i < space16.size(); i++)
	{
		cout << space16[i].getName() << endl;
	}	
}

