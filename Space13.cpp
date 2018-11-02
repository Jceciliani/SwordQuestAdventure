/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 13 of 25 in the game
*/

#include "Space13.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space13::Space13()
{
	name = "Sanctuary";
	shortForm = "In the center of the room is a small ornate fountain \n"
	"In the south western corner is an anvil and furnace. Along the northern wall there is a large wooden chest \n";
	longForm = "You awake to the sound of trickling water and the taste of rubble in your mouth. \n"
	"You are sore, but not as sore as you would expect. You wince as you stand and begin to take \n"
	"in your surroundings.The room itself seems fairly nice, despite being in an extreme state of disuse.\n"
	"The majority of the room is covered in thick coat of dust.In the center of the room is a small ornate fountain \n"
	"In the south western corner is an anvil and furnace. Along the northern wall there is a large wooden chest \n \n"
	"To the south there is a large ominously gated doorway \n"
	"To the west is a doorway that leads down a well lit corridor \n"
	"To the north is a set of moist stairs that lead downward \n"
	"To the east is a doorway that leads through a small dimly lit passage \n";
	id = 13;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space13::~Space13()
{}
void Space13::addToContainer(Objects obj)
{
	space13.push_back(obj);
}

void Space13::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space13.size(); i++)
	{
		if(space13[i].getName() == obj.getName())
		{
			space13.erase(space13.begin() + i);
			return;
		}
	}

}

void Space13::printContainer()
{
	for(int i = 0; i < space13.size(); i++)
	{
		cout << space13[i].getName() << endl;
	}	
}

