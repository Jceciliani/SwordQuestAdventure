/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 4 of 25 in the game
*/

#include "Space4.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space4::Space4()
{
	name = "Sewer Depths";
	shortForm = "The mouth of the sewer opens up into the ocean. The waves look rough today. \n"
	"There is a small wooden bridge connecting the eastern and western parts of the sewers.\n";
	longForm = "The mouth of the sewer opens up into the ocean. The waves look rough today. \n"
	"There is a small wooden bridge connecting the eastern and western parts of the sewers. \n\n"
	"To the east you see the sewer tunnels continue \n"
	"To the west you see the sewer tunnels continue \n";
	id = 4;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space4::~Space4()
{}
