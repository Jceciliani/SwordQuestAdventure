/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 1 of 25 in the game
*/

#include "Space1.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space1::Space1()
{
	name = "Fields";
	shortForm = "You arrive in a grassy clearing. A pleasant breeze blows from seemingly nowhere.\n";
	longForm = "You arrive in a grassy clearing. A pleasant breeze blows from seemingly nowhere. \n\n"
	"To the east you see a cobblestone path\n"
	"To the south is a trail into the thick brush\n";
	id = 1;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space1::~Space1()
{}

void Space1::addToContainer(Objects obj)
{
	space1.push_back(obj);
}

void Space1::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space1.size(); i++)
	{
		if(space1[i].getName() == obj.getName())
		{
			space1.erase(space1.begin() + i);
			return;
		}
	}

}

void Space1::printContainer()
{
	for(int i = 0; i < space1.size(); i++)
	{
		cout << space1[i].getName() << endl;
	}	
}


void Space1::look(char* thing)
{
	if(strcmp(thing, "grass"))
	{
		cout << "the long grass come up to your waist. Maybe there is something hidden within it." << endl; 
		cout << "Like rupees! " << endl;
	}
	else if(strcmp(thing, "wind"))
	{
		cout << "no matter where you look, the wind has zero colors." << endl;	
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}


void attack(char* thing)
{
	if(strcmp(thing, "grass"))
	{
		cout << "with a “ hiyayaya!!!” you arc your sword around trimming the grass and clearing a" << endl;
		cout << "patch around you. Unfortunatly, this is not that game, so you find zero rupees" << endl;
		cout << ". What would you even do with one?" << endl;	
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}



