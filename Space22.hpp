/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 22 of 25 in the game
*/

#ifndef SPACE22_HPP
#define SPACE22_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space22 : public Space
{
	private:
		vector<Objects> space22;
		bool answered;
		bool correct;
	public:
		Space22();
		~Space22();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(string thing);
		void talk(string thing);
		void answer(string thing);
};
#endif // !SPACE22_HPP

