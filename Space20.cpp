/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 20 of 25 in the game
*/

#include "Space20.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space20::Space20()
{
	name = "Volcano Summit";
	shortForm = "You have reached the mouth of the volcano. The rocks around you dimly glow from the \n"
	"mountains contents. The heat is nearly too much to bare. Near the lip you see a small ornate \n"
	"fountain. To the east you also see a door shaped shimmering gateway.\n";
	longForm = "You have reached the mouth of the volcano. The rocks around you dimly glow from the \n"
	"mountains contents. The heat is nearly too much to bare. Near the lip you see a small ornate \n"
	"fountain. To the east you also see a door shaped shimmering gateway.\n\n"
	"To the south you can see a ledge leading into the volcano \n";
	id = 20;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space20::~Space20()
{}
