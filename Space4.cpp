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
	name = "Sewer Depths";
	shortForm = "The mouth of the sewer opens up into the ocean. The waves look rough today. \n"
	"There is a small wooden bridge connecting the eastern and western parts of the sewers.\n";
	longForm = "The mouth of the sewer opens up into the ocean. The waves look rough today. \n"
	"There is a small wooden bridge connecting the eastern and western parts of the sewers. \n\n"
	"To the east you see the sewer tunnels continue \n"
	"To the west you see the sewer tunnels continue \n";
	id = 4;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space4::~Space4()
{}
void Space4::addToContainer(Objects obj)
{
	space4.push_back(obj);
}

void Space4::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space4.size(); i++)
	{
		if(space4[i].getName() == obj.getName())
		{
			space4.erase(space4.begin() + i);
			return;
		}
	}

}

void Space4::printContainer()
{
	for(int i = 0; i < space4.size(); i++)
	{
		cout << space4[i].getName() << endl;
	}	
}

void Space4::look(string thing)
{
	if(strcmp(thing, "ocean") || strcmp(thing, "opening"))
		{
			cout << "you see the ocean. Between the rough waves and glimpses of shark fins" << endl;
			cout << " its probably best to not try your luck out there" << endl;
			
		}
	else if (strcmp(thing, "bridge") )
		{
			cout << " The wood the bridge is made from definitely looks old, but by no means" << endl;
			cout << " rotted or weak. This seems strange considering the environment," << endl;
			cout << " but there are more pressing issues. " << endl;
		}
	else
	{
		cout << "you cant do that" << endl;
	}
}
