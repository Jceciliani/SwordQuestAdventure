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
	"vines. The canopy is so think you are not sure if there is even a ceiling anymore.";
	longForm = "You are surrounded by heavy vegetation and rotting trees covered with serpentine \n"
	"vines. The canopy is so think you are not sure if there is even a ceiling anymore. \n\n"
	"To the east is a small opening through the brush \n"
	"To the south is a wide path marked with broken branches \n"
	"To the north is you can see a small clearing through the brush\n";
	id = 6;
	obj = new Silver_Armor();
	combatEncounter = false;
	visited = false;
}

Space6::~Space6()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
