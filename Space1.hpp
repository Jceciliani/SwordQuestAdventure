/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 1 of 25 in the game
*/

#ifndef SPACE1_HPP
#define SPACE1_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space1 : public Space
{
	private:
		vector<Objects> space1;
	public:
		Space1();
		~Space1();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(char* thing);
		void attack(char* thing);
};
#endif // !SPACE1_HPP


