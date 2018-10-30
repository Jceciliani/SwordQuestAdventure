/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 11 of 25 in the game
*/

#include "Space11.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space11::Space11()
{
	name = "Cave";
	shortForm = " You find a small cave. It is covered it piles of broken tools, torn clothes, and bones.\n";
	longForm = " You find a small cave. It is covered it piles of broken tools, torn clothes, and bones. \n\n"
	"To the north is a wide path marked with broken branches \n";
	id = 11;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space11::~Space11()
{}
