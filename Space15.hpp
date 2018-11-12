/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 15 of 25 in the game
*/

#ifndef SPACE15_HPP
#define SPACE15_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space15 : public Space
{
	private:
		vector<Objects> space15;
		bool steelFound;
		bool tombOpen;
	public:
		Space15();
		~Space15();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void look(char* thing);
		void search(char* thing);
		void open(char* thing);
		void attack(char* thing);
};
#endif // !SPACE15_HPP
