/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 16 of 25 in the game
*/

#ifndef SPACE16_HPP
#define SPACE16_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space16 : public Space
{
	private:
		vector<Objects> space16;
	public:
		Space16();
		~Space16();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
};
#endif // !SPACE16_HPP
