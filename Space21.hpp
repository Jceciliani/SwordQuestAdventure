/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 21 of 25 in the game
*/

#ifndef SPACE21_HPP
#define SPACE21_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space21 : public Space
{
public:
	Space21();
	~Space21();
	string getName();
	string getShortForm();
	string getLongForm();
	void printSpace();
	int getId();

};
#endif // !SPACE21_HPP
