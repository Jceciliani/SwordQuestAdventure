/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 3 of 25 in the game
*/

#ifndef SPACE3_HPP
#define SPACE3_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space3 : public Space
{
	private:
		vector<Objects> space3;
		bool ropePulled;
	public:
		Space3();
		~Space3();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(char* thing);
		void take(char* thing);
		void pull(char* thing);
};
#endif // !SPACE3_HPP
