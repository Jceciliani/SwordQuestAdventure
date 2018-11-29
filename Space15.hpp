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
		bool taken;
	public:
		Space15();
		~Space15();

		void look(const char* thing);
		void search(const char* thing);
		void open(const char* thing);
		void attack(const char* thing);
		void setSteel(int set) { if (set == 1) { steelFound = true; } else { steelFound = false; } }
		bool getSteel() { return steelFound; }
		void setTomb(int set) { if (set == 1) { tombOpen = true; } else { tombOpen = false; } }
		bool getTomb() { return tombOpen; }
		void setTaken(int set) { if (set == 1) { taken = true; } else { taken = false; } }
		bool getTaken() { return taken; }
};
#endif // !SPACE15_HPP
