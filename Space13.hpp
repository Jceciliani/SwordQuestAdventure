/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 13 of 25 in the game
*/

#ifndef SPACE13_HPP
#define SPACE13_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space13 : public Space
{
	private:
		vector<Objects> space13;
		bool fountianUsed;
		bool gateOpened;
		bool forgeLit;
	public:
		Space13();
		~Space13();

		void look(const char* thing);
		void drink(const char* thing);
		void start(const char* thing);
		void open(const char* thing);
		void use(const char* thing);
		void setFountian(int set) { if (set == 1) { fountianUsed = true; } else { fountianUsed = false; } }
		bool getFountian() { return fountianUsed; }
		void setGate(int set) { if (set == 1) { gateOpened = true; } else { gateOpened = false; } }
		bool getGate() { return gateOpened; }
		void setForge(int set) { if (set == 1) { forgeLit = true; } else { forgeLit = false; } }
		bool getForge() { return forgeLit; }
};
#endif // !SPACE13_HPP
