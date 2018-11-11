/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 10 of 25 in the game
*/

#include "Space10.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space10::Space10()
{
	name = "Upper Maintenance";
	shortForm = "You arrive on the end of the walkway. There it is a moderately sized stone \n"
	"platform. In the corner you see a small hovel made of bone,. Metal scraps, and literal dung.\n";
	longForm = "You arrive on the end of the walkway. There it is a moderately sized stone \n"
	"platform. In the corner you see a small hovel made of bone,. Metal scraps, and literal shit. \n\n"
	"To the west there is a walkway \n"
	"To the north is a ladder leading down\n";
	id = 10;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space10::~Space10()
{}
void Space10::addToContainer(Objects obj)
{
	space10.push_back(obj);
}

void Space10::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space10.size(); i++)
	{
		if(space10[i].getName() == obj.getName())
		{
			space10.erase(space10.begin() + i);
			return;
		}
	}

}

void Space10::printContainer()
{
	for(int i = 0; i < space10.size(); i++)
	{
		cout << space10[i].getName() << endl;
	}	
}
void Space10::look(string thing)
{
if(strcmp(thing, "corner") || strcmp(thing, "hovel")))
		{
			cout << "the hovel is very disgusting, there is a small sack next to what you can" << endl; 
			cout << "guess is a bed" << endl;
			
		}

	else if(strcmp(thing, "sack"))
		{
			cout << "a small burlap full of something. you cant tell what just from looking" << endl;
		}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space10::search(string thing)
{
if(strcmp(thing, "corner") || strcmp(thing, "hovel")))
		{
			cout << "nope. Nothing useful. Just more feces." << endl; 
		}	
	else
		{
			cout << "you cant do that" << endl;
		}
}