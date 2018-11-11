/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 25 of 25 in the game
*/

#ifndef SPACE25_HPP
#define SPACE25_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space25 : public Space
{
	private:
		vector<Objects> space25;
		bool flintFound;
	public:
		Space25();
		~Space25();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(string thing);
		void attack(string thing);
};
#endif // !SPACE25_HPP
