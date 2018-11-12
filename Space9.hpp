/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 9 of 25 in the game
*/

#ifndef SPACE9_HPP
#define SPACE9_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space9 : public Space
{
	private:
		vector<Objects> space9;
		bool hatchOpen;
		bool fountianUsed;
	public:
		Space9();
		~Space9();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(char* thing);
		void drink(char* thing);
		void enter(char* thing);
		void open(char* thing);
};
#endif // !SPACE9_HPP
