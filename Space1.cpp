/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 1 of 25 in the game
*/

#include "Space1.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space1::Space1()
{
	name = "Space1";
	shortForm = "You arrive in a grassy clearing. A pleasant breeze blows from seemingly nowhere.";
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
