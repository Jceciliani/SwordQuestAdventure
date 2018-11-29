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
	shortForm = "You are at the base of a large volcano.\n"
	"In the middle of the path there is a small ornate fountain.\n";
	longForm = "You are at the base of a large volcano. Its shadow looms over you. There is a faint \n"
		"smell of sulfur in the air. In the middle of the path there is a small ornate fountain. \n\n"
		"To the north is a path sloping down and away from the volcano \n";

	id = 17;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	fountianUsed = false;
}

Space17::~Space17()
{}

void Space17::look(const char* thing)
{
if (strcmp(thing, "fountian") == 0)
	{
		if(fountianUsed)
		{
			cout << "The fountian is dry" << endl;
		}
		else
		{
			cout << "The fountian is filled with water. It looks very refreshing" << endl;
		}
	}

	else if(strcmp(thing, "volcano") == 0)
	{
			cout << "Its a volcano… in a dungeon? Anyways, it seems to be still active. Maybe there's " << endl; 
			cout << "something that will help up there?" << endl; 
	}
else
		{
			cout << "You can't do that" << endl;
		}
}

void Space17::drink(const char* thing)
{
if (strcmp(thing, "fountain") == 0)
	{
		if(!fountianUsed)
		{
		cout << "You feel strength return to your body as you drink. You quickly consume all" << endl;
		cout << "of the water with in the fountain. The fountain is now dry." << endl;
		fountianUsed = true;
		}
		else
		{
			cout << "The fountain is dry" << endl;
		}
	}
	else
		{
			cout << "You can't do that" << endl;
		}
}
