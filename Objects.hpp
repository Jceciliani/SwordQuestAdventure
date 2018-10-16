/* Program Name: Sword Quest
   Author: Centaurus Team 1
   Date: October 9, 2018
   Description: All objects used in Sword Quest, includes weapons and armor
   */

#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
#include <string>

using namespace std;


class Objects
{
	protected:
		string name;
		string description;
	public:
		Objects();
		~Objects();
		string getName();
		string getDescription();
		void printObject();

};
#endif // !OBJECTS_HPP


// Two Handed Wooden Sword **********************************
class Two_Handed_Wooden_Sword : public Objects
{
	public:
		Two_Handed_Wooden_Sword();
		~Two_Handed_Wooden_Sword();
};


// Two Handed Bronze Sword ***********************************
class Two_Handed_Bronze_Sword : public Objects
{
	public:
		Two_Handed_Bronze_Sword();
		~Two_Handed_Bronze_Sword();
};


// Two Handed Silver Sword ************************************
class Two_Handed_Silver_Sword : public Objects
{
	public:
		Two_Handed_Silver_Sword();
		~Two_Handed_Silver_Sword();
};


// Two Handed Gold Sword **************************************
class Two_Handed_Gold_Sword : public Objects
{
	public:
		Two_Handed_Gold_Sword();
		~Two_Handed_Gold_Sword();
};


// Two Handed Ultimate Sword **********************************
class Two_Handed_Ultimate_Sword : public Objects
{
	public:
		Two_Handed_Ultimate_Sword();
		~Two_Handed_Ultimate_Sword();
};


// Tunic Armor ************************************************
class Tunic_Armor : public Objects
{
	public:
		Tunic_Armor();
		~Tunic_Armor();
};


// Bronze Armor ***********************************************
class Bronze_Armor : public Objects
{
	public:
		Bronze_Armor();
		~Bronze_Armor();
};


// Silver Armor ************************************************
class Silver_Armor : public Objects
{
	public:
		Silver_Armor();
		~Silver_Armor();
};


// Gold Armor **************************************************
class Gold_Armor : public Objects
{
	public:
		Gold_Armor();
		~Gold_Armor();
};



// Ultimate Armor ***********************************************
class Ultimate_Armor : public Objects
{
	public:
		Ultimate_Armor();
		~Ultimate_Armor();
};



// Forge Hammer *************************************************
class Forge_Hammer : public Objects
{
	public:
		Forge_Hammer();
		~Forge_Hammer();
};



// Flint ********************************************************
class Flint : public Objects
{
	public:
		Flint();
		~Flint();
};



// Steel ********************************************************
class Steel : public Objects
{
	public:
		Steel();
		~Steel();
};



// Key **********************************************************
class Key : public Objects
{
	public:
		Key();
		~Key();
};





