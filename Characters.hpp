/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: All characters located throughout the game - this includes the hero plus all of the enemies
*/

#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Container.hpp"

using namespace std;

class Characters
{
	protected:
		int strength;
		int level;
		string name;
		bool isDead;
	public:
		Characters();
		~Characters();
		virtual int attack() = 0;
		virtual void defense(int) = 0;
		bool fatalBlow();
		string getName();
		int getStrength();
		int getLevel();
		void levelUp();
};
#endif // !CHARACTERS_HPP

// Hero Class *************************************************
class Hero : public Characters
{
	public:
		Hero();
		~Hero();
		int attack();
		void defense(int);
};

// Rat Class ***************************************************
class Rat : public Characters
{
	public:
		Rat();
		~Rat();
		int attack();
		void defense(int);
};

// Goblin Class ************************************************
class Goblin : public Characters
{
	public:
		Goblin();
		~Goblin();
		int attack();
		void defense(int);
};

// Hobgoblin Class *********************************************
class Hobgoblin : public Characters
{
	public:
		Hobgoblin();
		~Hobgoblin();
		int attack();
		void defense(int);
};

// Naga Class **************************************************
class Naga : public Characters
{
	public:
		Naga();
		~Naga();
		int attack();
		void defense(int);
};

// Troll Class *************************************************
class Troll : public Characters
{
	public:
		Troll();
		~Troll();
		int attack();
		void defense(int);
};

// Wizard Class *************************************************
class Wizard : public Characters
{
	public:
		Wizard();
		~Wizard();
		int attack();
		void defense(int);
};

// Gang of Bandits Class
class Gang_of_Bandits : public Characters
{
	public:
		Gang_of_Bandits();
		~Gang_of_Bandits();
		int attack();
		void defense(int);
};

// Mountain Giant Class ******************************************
class Mountain_Giant : public Characters
{
	public:
		Mountain_Giant();
		~Mountain_Giant();
		int attack();
		void defense(int);
};

// Lesser Drake Class ********************************************
class Lesser_Drake : public Characters
{
	public:
		Lesser_Drake();
		~Lesser_Drake();
		int attack();
		void defense(int);
};

// Dragon Class **************************************************
class Dragon : public Characters
{
	public:
		Dragon();
		~Dragon();
		int attack();
		void defense(int);
};