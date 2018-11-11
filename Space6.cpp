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
	name = "Jungle";
	shortForm = "You are surrounded by heavy vegetation and rotting trees covered with serpentine \n"
	"vines. The canopy is so think you are not sure if there is even a ceiling anymore.\n";
	longForm = "You are surrounded by heavy vegetation and rotting trees covered with serpentine \n"
	"vines. The canopy is so think you are not sure if there is even a ceiling anymore. \n\n"
	"To the east is a small opening through the brush \n"
	"To the south is a wide path marked with broken branches \n"
	"To the north is you can see a small clearing through the brush\n";
	id = 6;
	obj = new Silver_Armor();
	combatEncounter = false;
	visited = false;
	vineCut = false;
}

Space6::~Space6()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
void Space6::addToContainer(Objects obj)
{
	space6.push_back(obj);
}

void Space6::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space6.size(); i++)
	{
		if(space6[i].getName() == obj.getName())
		{
			space6.erase(space6.begin() + i);
			return;
		}
	}

}

void Space6::printContainer()
{
	for(int i = 0; i < space6.size(); i++)
	{
		cout << space6[i].getName() << endl;
	}	
}

	void Space6::look(string thing)
	{
		if(strcmp(thing, "canopy"))
		{
			cout << "you still cant see the top, but something up above seems to be caught in a bundle of vines" << endl; 

		}
		else if(strcmp(thing, "vegitation") || strcmp(thing, "trees"))
		{
			cout << "the vegiatition seems to be growing fairly well here, barring the high number" << endl;
			cout <<  "of snags. But even those are creating holds for vines and other vegitation." << endl;	
		}
		else if(strcmp(thing, "vines"))
		{
			cout << "they are thick rope like vegitation, and it is very abundant here." << endl;
			cout << "One vine on the tree next to you seems taught." << endl;	
		}
		else
		{
			cout << "you cant do that" << endl;
		}
	}

	void Space6::attack(string thing)
	{
		if(strcmp(thing, "vines"))
		{
			cout << " you hack at the vine a few times before it separates and one end shoots into the canopy." << endl;
			cout << " A second later a ball of vines crashes down to the ground next to you." << endl;
			cout << "You see in it a set of silver armor." << endl;	
		}
		else
		{
			cout << "you cant do that" << endl;
		}
	}