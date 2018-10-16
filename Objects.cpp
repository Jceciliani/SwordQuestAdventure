/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: All objects used in Sword Quest, includes weapons and armor
*/

#include "Objects.hpp"
#include <iostream>
#include <string>

using namespace std;

// Objects********************************************
Objects::Objects()
{
	name = "No Name";
	description = "No Description";
}

Objects::~Objects()
{}

string Objects::getName()
{
	return name;
}

string Objects::getDescription()
{
	return description;
}

void Objects::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;

}


// Two-Handed Wooden Sword *****************************************
Two_Handed_Wooden_Sword::Two_Handed_Wooden_Sword()
{
	name = "Two-Handed Wooden Sword";
	description = "";
}

Two_Handed_Wooden_Sword::~Two_Handed_Wooden_Sword()
{}

// Two-Handed Bronze Sword *****************************************
Two_Handed_Bronze_Sword::Two_Handed_Bronze_Sword()
{
	name = "Two-Handed Bronze Sword";
	description = "";
}

Two_Handed_Bronze_Sword::~Two_Handed_Bronze_Sword()
{}

// Two-Handed Silver Sword ******************************************
Two_Handed_Silver_Sword::Two_Handed_Silver_Sword()
{
	name = "Two-Handed Silver Sword";
	description = "";
}

Two_Handed_Silver_Sword::~Two_Handed_Silver_Sword()
{}

// Two-Handed Gold Sword ********************************************
Two_Handed_Gold_Sword::Two_Handed_Gold_Sword()
{
	name = "Two-Handed Gold Sword";
	description = "";
}

Two_Handed_Gold_Sword::~Two_Handed_Gold_Sword()
{}

// Two-Handed Ultimate Sword ****************************************
Two_Handed_Ultimate_Sword::Two_Handed_Ultimate_Sword()
{
	name = "Two-Handed Ultimate Sword";
	description = "";
}

Two_Handed_Ultimate_Sword::~Two_Handed_Ultimate_Sword()
{}

// Tunic Armor *****************************************************
Tunic_Armor::Tunic_Armor()
{
	name = "Tunic Armor";
	description = "";
}

Tunic_Armor::~Tunic_Armor()
{}

// Bronze Armor ****************************************************
Bronze_Armor::Bronze_Armor()
{
	name = "Bronze Armor";
	description = "";
}

Bronze_Armor::~Bronze_Armor()
{}

// Silver Armor *****************************************************
Silver_Armor::Silver_Armor()
{
	name = "Silver Armor";
	description = "";
}

Silver_Armor::~Silver_Armor()
{}

// Gold Armor *******************************************************
Gold_Armor::Gold_Armor()
{
	name = "Gold Armor";
	description = "";
}

Gold_Armor::~Gold_Armor()
{}

// Ultimate Armor ***************************************************
Ultimate_Armor::Ultimate_Armor()
{
	name = "Ultimate Armor";
	description = "";
}

Ultimate_Armor::~Ultimate_Armor()
{}

// Forge Hammer *****************************************************
Forge_Hammer::Forge_Hammer()
{
	name = "Forge Hammer";
	description = "";
}

Forge_Hammer::~Forge_Hammer()
{}

// Flint ************************************************************
Flint::Flint()
{
	name = "Flint";
	description = "";
}

Flint::~Flint()
{}

// Steel ************************************************************
Steel::Steel()
{
	name = "Steel";
	description = "";
}

Steel::~Steel()
{}

// Key *************************************************************
Key::Key()
{
	name = "Key";
	description = "";
}

Key::~Key()
{}

