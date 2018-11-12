/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 7 of 25 in the game
*/

#ifndef SPACE7_HPP
#define SPACE7_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space7 : public Space
{
	private:
		vector<Objects> space7;
		bool jumped;
		bool crossed;
	public:
		Space7();
		~Space7();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(char* thing);
		void jump(char* thing);
		void run(char* thing);
};
#endif // !SPACE7_HPP
