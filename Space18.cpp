/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 18 of 25 in the game
*/

#include "Space18.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space18::Space18()
{
	name = "Space18";
	shortForm = "This is the short form";
	longForm = "This is the long form";
	id = 18;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space18::~Space18()
{}
