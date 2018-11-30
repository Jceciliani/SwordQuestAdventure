/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 15 of 25 in the game
*/

#include "Space15.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space15::Space15()
{
	name = "crypt";
	shortForm = "The room is filled with candles and intricately painted pots and vases. In the center of the room is a large tomb\n\n"
		"To the west is a doorway to leads back to the dimly lit corridor of the Mausoleum \n";
	longForm = "The room is filled with candles that were used up long ago and a plethora of \n"
		"intricately painted pots and vases. The room feels very ceremonial. In the center of the \n"
		"room is a large tomb. An air of death lingers in the room \n\n"
		"To the west is a doorway to leads back to the dimly lit corridor of the Mausoleum \n";

	id = 15;
	obj = new Steel();
	combatEncounter = false;
	visited = false;
	steelFound = false;
	tombOpen = false;
	taken = false;
}

Space15::~Space15()
{
	if (obj != NULL)
	{
		delete obj;
	}
}


void Space15::look(const char* thing)
{
if(strcmp(thing, "candles") == 0)
		{
			cout << "Used up candles. Kind of pointless to collect the wax" << endl; 
		}

	else if(strcmp(thing, "vases") == 0)
	{
			cout << "A bunch of pots and vases. Most of them are painted very well, maybe as an" << endl; 
			cout << "offering. Or is the offering inside of them?" << endl;	
	}
	else if(strcmp(thing, "tomb") == 0)
	{
			cout << "A large tomb made of stone. The patterns on the lid makes you think it is not royalty" << endl; 
			cout << "with in, but probably someone important" << endl;	
	}
	else if(strcmp(thing, "in tomb") == 0)
	{
			if(tombOpen){
			cout << "Inside you find a skeleton. Shocker. The skeleton is dressed in simple clothes." << endl; 
			cout << "Simpler than you would expect." << endl;	
			}
			else{
				cout << "The tomb is closed" << endl;
			}
	}
	else if (strcmp(thing, "skeleton") == 0)
{
	if (tombOpen) {
		cout << "The bones of someone that used to be living. nothing special here..." << endl;
		cout << "or maybe there is? Check if they were buried with anything interesting" << endl;
	}
	else {
		cout << "The tomb is closed" << endl;
	}
}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space15::search(const char* thing)
{
	if (strcmp(thing, "vases") == 0)
	{
		cout << "Used up candles. Kind of pointless to collect the wax" << endl;
	}
	else if (strcmp(thing, "skeleton") == 0|| strcmp(thing, "clothes") == 0)
	{
		if (tombOpen) {
			cout << "In one of the skeletons pockets you find a note. It is a letter to the" << endl;
			cout << "new forge master. It reads" << endl;
			cout << "now that you are replacing me as forge master you should know a few things. Our forge is in" << endl;
			cout << "bad condition and dies every few days. It's easy enough to get restarted though. Just hit some" << endl;
			cout << "flint and steel together and that ought to spark it up! Then you can continue banging away with " << endl;
			cout << "your forge hammer as usual. Good luck!" << endl;
		}
		else {
			cout << "The tomb is closed" << endl;
		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space15::attack(const char* thing)
{
	if (strcmp(thing, "vases") == 0)
	{
		if (steelFound == false || taken == false) {
			cout << "Like a true hylian, you start hurling jar after jar at the wall. After a few, you" << endl;
			cout << "feel kinda bad so you stop. But one of the busted pots had a bunch of steel!" << endl;
			cout << "Maybe it'll be useful?" << endl;
			steelFound = true;
		}
		else
		{
			cout << "You already found something useful, but you smash another pot for the hell of it" << endl;
		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space15::open(const char* thing)
{
	if (strcmp(thing, "tomb") == 0)
	{
		if (tombOpen)
		{
			cout << "The tomb is already open" << endl;

		}
		else
		{
			cout << "With a grunt and a shove you push the top off the tomb. The tomb is now open" << endl;
			tombOpen = true;
		}
		cout << "Like a true hylian, you start hurling jar after jar at the wall. After a few, you" << endl;
		cout << "feel kinda bad so you stop. But one of the busted pots had a bunch of steel!" << endl;
		cout << "Maybe it'll be useful?" << endl;
		steelFound = true;

	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
