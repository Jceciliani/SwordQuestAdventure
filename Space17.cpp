/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 17 of 25 in the game
*/

#include "Space17.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space17::Space17()
{
	name = "Volcano Foothills";
	shortForm = "You are at the base of a large volcano. Its shadow looms over you. There is a faint \n"
	"smell of sulfur in the air. In the middle of the path there is a small ornate fountain.\n";
	longForm = "You are at the base of a large volcano. Its shadow looms over you. There is a faint \n"
	"smell of sulfur in the air. In the middle of the path there is a small ornate fountain. \n\n"
	"To the north is a path sloping down and away from the volcano \n"
	"To west is a trail leading up the volcano\n";
	id = 17;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	fountianUsed = false;
}

Space17::~Space17()
{}

void Space17::look(char* thing)
{
if (strcmp(thing, "fountian"))
	{
		if(fountianUsed)
		{
			cout << "the fountian is dry" << endl;
		}
		else
		{
			cout << "The fountian is filled with water. It looks very refreashing" << endl;
		}
	}

	else if(strcmp(thing, "volcano"))
	{
			cout << "its a volcano… in a dungeon? Anyways it seems to be still active. Maybe theres " << endl; 
			cout << "something that will help up there?" << endl; 
	}
else
		{
			cout << "you cant do that" << endl;
		}
}

void Space17::drink(char* thing)
{
if (strcmp(thing, "from fountian"))
	{
		if(!fountianUsed)
		{
		cout << "you feel strength return to your body as you drink. You quickly consume all" << endl;
		cout << "of the water with in the fountian. The foundtian is now dry." << endl;
		fountianUsed = true;
		}
		else
		{
			cout << "The fountian is dry" << endl;
		}
	}
	else
		{
			cout << "you cant do that" << endl;
		}
}