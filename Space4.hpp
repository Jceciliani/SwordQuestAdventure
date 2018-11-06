/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 4 of 25 in the game
*/

#ifndef SPACE4_HPP
#define SPACE4_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space4 : public Space
{
	private:
		vector<Objects> space4;
	public:
		Space4();
		~Space4();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(string thing);
};
#endif // !SPACE4_HPP
