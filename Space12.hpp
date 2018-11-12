/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 12 of 25 in the game
*/

#ifndef SPACE12_HPP
#define SPACE12_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space12 : public Space
{
	private:
		vector<Objects> space12;
	public:
		Space12();
		~Space12();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(char* thing);
		void dig(char* thing);
};
#endif // !SPACE12_HPP
