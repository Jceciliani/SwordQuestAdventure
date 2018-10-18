/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 17 of 25 in the game
*/

#include "Space17.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space17::Space17()
{
	name = "Space17";
	shortForm = "You are at the base of a large volcano. Its shadow looms over you. There is a faint \n
	 smell of sulfur in the air. In the middle of the path there is a small ornate fountain.";
	longForm = "You are at the base of a large volcano. Its shadow looms over you. There is a faint \n
	smell of sulfur in the air. In the middle of the path there is a small ornate fountain. \n\n
	To the north is a path sloping down and away from the volcano \n
	To west is a trail leading up the volcano\n";
	id = 17;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space17::~Space17()
{}
