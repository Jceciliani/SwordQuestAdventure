/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 6 of 25 in the game
*/

#ifndef SPACE6_HPP
#define SPACE6_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space6 : public Space
{
	private:
		vector<Objects> space6;
		bool vineCut;
	public:
		Space6();
		~Space6();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(string thing);
		void attack(string thing);
};
#endif // !SPACE6_HPP
