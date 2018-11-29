/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 20 of 25 in the game
*/

#include "Space20.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space20::Space20()
{
	name = "Volcano Summit";
	shortForm = "The rocks around you dimly glow from the mountains contents.\n"
	"Near the lip you see a small ornate fountain. To the east you also see a door shaped shimmering gateway.\n";
	longForm = "You have reached the mouth of the volcano. The rocks around you dimly glow from the \n"
		"mountains contents. The heat is nearly too much to bare. Near the lip you see a small ornate \n"
		"fountain. To the east you also see a door shaped shimmering gateway.\n\n";

	id = 20;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	fountianUsed = false;
}

Space20::~Space20()
{}


void Space20::look(const char* thing)
{
	if (strcmp(thing, "fountain") == 0)
	{
		if(fountianUsed)
		{
			cout << "The fountain is dry" << endl;
		}
		else
		{
			cout << "The fountain is filled with water. It looks very refreshing" << endl;
		}
	}
	else if (strcmp(thing, "rocks") == 0)
	{
		cout << "They glow because they're hot. Look but don't touch" << endl;
	}
	else if (strcmp(thing, "gateway") == 0)
	{
		cout << "Large pillars in the shape of a doorframe contain the purplish portal. You feel " << endl;
		cout << "like it will take you somewhere safe." << endl;
	}
	else
		{
			cout << "You can't do that" << endl;
		}
}
void Space20::enter(const char* thing)
{
	if (strcmp(thing, "gateway") == 0)
	{
		cout << "As you cross through, you are consumed by a bright light. You close your eyes " << endl;
		cout << "to not be blinded. You feel warm, but not in a “i'm on a volcano” way." << endl;
		cout << "When you open your eyes again, you have returned to the sanctuary." << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space20::drink(const char* thing)
{
	if (strcmp(thing, "fountain") == 0)
	{
		if (!fountianUsed)
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
