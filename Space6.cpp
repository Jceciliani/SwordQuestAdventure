 /* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 6 of 25 in the game
*/

#include "Space6.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space6::Space6()
{
	name = "jungle";
	shortForm = "You are surrounded by heavy vegetation and rotting trees covered with serpentine \n"
	"vines. The canopy is so thick you are not sure if there is even a ceiling anymore.\n\n"
		"To the east is a small opening through the brush leading into the Swamp \n"
		"To the south at the end of a wide path marked with broken branches you can see a small Cave \n"
		"To the north past the brush you can see a clearing of open Fields\n";
	longForm = "You are surrounded by heavy vegetation and rotting trees covered with serpentine \n"
		"vines. The canopy is so thick you are not sure if there is even a ceiling anymore. The symphony of the jungle envelops you. \n"
		"You can hear the songs of birds, the buzz of insects and the movement of mammals. Mostly small ones, though sometimes not..\n\n"
		"To the east is a small opening through the brush leading into the Swamp \n"
		"To the south at the end of a wide path marked with broken branches you can see a small Cave \n"
		"To the north past the brush you can see a clearing of open Fields\n";

	id = 6;
	obj = new Silver_Armor();
	combatEncounter = false;
	visited = false;
	vineCut = false;
	taken = false;
}

Space6::~Space6()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space6::look(const char* thing)
{
	if (strcmp(thing, "canopy") == 0)
	{
		if (vineCut == false) {
			cout << "You still can't see the top, but something up above seems to be caught in a bundle of vines" << endl;
		}
		else
		{
			cout << "You still can't see the top, but you wonder how far up it goes" << endl;
		}
	}
	else if (strcmp(thing, "vegetation") == 0 || strcmp(thing, "trees") == 0)
	{
		cout << "The vegetation seems to be growing fairly well here, barring the high number" << endl;
		cout << "of snags. But even those are creating holds for vines and other vegetation." << endl;
	}
	else if (strcmp(thing, "vines") == 0)
	{
		cout << "They are thick, rope like vegetation, and it is very abundant here." << endl;
		if (vineCut == false) 
		{
			cout << "One vine on the tree next to you seems caught." << endl;
		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space6::attack(const char* thing)
{
	if (strcmp(thing, "vines") == 0)
	{
		if (vineCut == false) {
			cout << "You hack at the vine a few times before it separates and one end shoots into the canopy." << endl;
			cout << "A second later, a ball of vines crashes down to the ground next to you." << endl;
			cout << "You see in it a set of silver armor." << endl;
			vineCut = true;
		}
		else
		{
			cout << " You hack at the vine a few times before it separates. Nothing happens" << endl;
		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
