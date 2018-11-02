/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 10 of 25 in the game
*/

#ifndef SPACE10_HPP
#define SPACE10_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space10 : public Space
{
	private:
		vector<Objects> space10;
	public:
		Space10();
		~Space10();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
};
#endif // !SPACE10_HPP
