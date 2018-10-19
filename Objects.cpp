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
	description = "a couple of boards nailed together. it looks more like a toy than a weapon";
}

Two_Handed_Wooden_Sword::~Two_Handed_Wooden_Sword()
{}

// Two-Handed Bronze Sword *****************************************
Two_Handed_Bronze_Sword::Two_Handed_Bronze_Sword()
{
	name = "Two-Handed Bronze Sword";
	description = " an old worn sword made of bronze. there are many chips in its toungue shaped blade";
}

Two_Handed_Bronze_Sword::~Two_Handed_Bronze_Sword()
{}

// Two-Handed Silver Sword ******************************************
Two_Handed_Silver_Sword::Two_Handed_Silver_Sword()
{
	name = "Two-Handed Silver Sword";
	description = "a large blade with made of pure silver. it feels well crafted, something you imagine \n"
	"a castle guard might use.";
}

Two_Handed_Silver_Sword::~Two_Handed_Silver_Sword()
{}

// Two-Handed Gold Sword ********************************************
Two_Handed_Gold_Sword::Two_Handed_Gold_Sword()
{
	name = "Two-Handed Gold Sword";
	description = "an ornate golden blade. patterns weave down the blade and through the hilt eventually \n"
	"swirling around the large ruby set into its pommel";
}

Two_Handed_Gold_Sword::~Two_Handed_Gold_Sword()
{}

// Two-Handed Ultimate Sword ****************************************
Two_Handed_Ultimate_Sword::Two_Handed_Ultimate_Sword()
{
	name = "Two-Handed Ultimate Sword";
	description = "The strongest sword youve ever seen. its blade glows and shimmers with a plethora \n"
	"of colors. you can feel the power contained within it.";
}

Two_Handed_Ultimate_Sword::~Two_Handed_Ultimate_Sword()
{}

// Tunic Armor *****************************************************
Tunic_Armor::Tunic_Armor()
{
	name = "Tunic Armor";
	description = " a tattered leather tunic. youre not sure if its dirty from the fall, or if it was \n"
	"always like this";
}

Tunic_Armor::~Tunic_Armor()
{}

// Bronze Armor ****************************************************
Bronze_Armor::Bronze_Armor()
{
	name = "Bronze Armor";
	description = "a bronze cheast plate. the worn straps can still hold the mass to your body suprisingly \n"
	" but the vairous puncture holes do not give you faith in its ability";
}

Bronze_Armor::~Bronze_Armor()
{}

// Silver Armor *****************************************************
Silver_Armor::Silver_Armor()
{
	name = "Silver Armor";
	description = "a set of silver armor. there are a few pieces missing, but the ones that are there are \n"
	"fairly good quality";
}

Silver_Armor::~Silver_Armor()
{}

// Gold Armor *******************************************************
Gold_Armor::Gold_Armor()
{
	name = "Gold Armor";
	description = "a complete set of golden aarmor. intricate designs weave through the plates stemming \n"
	"from a large lions head in the center of the breastplate. its very fancy, but very heavy.";
}

Gold_Armor::~Gold_Armor()
{}

// Ultimate Armor ***************************************************
Ultimate_Armor::Ultimate_Armor()
{
	name = "Ultimate Armor";
	description = "the strongest aarmor created. the surfaces are clean and smooth. it shimmers with \n"
	"the various clolors of the spectrum";
}

Ultimate_Armor::~Ultimate_Armor()
{}

// Forge Hammer *****************************************************
Forge_Hammer::Forge_Hammer()
{
	name = "Forge Hammer";
	description = " a hammer used to make weapons and aarmor. perhaps you can use this";
}

Forge_Hammer::~Forge_Hammer()
{}

// Flint ************************************************************
Flint::Flint()
{
	name = "Flint";
	description = " a substance when struck with steel creates sparks that ignite flame. maybe \n"
	"you can use this";
}

Flint::~Flint()
{}

// Steel ************************************************************
Steel::Steel()
{
	name = "Steel";
	description = "a solid hunk of steel. seems like junk.";
}

Steel::~Steel()
{}

// Key *************************************************************
Key::Key()
{
	name = "Key";
	description = "a large black iron key. you can feel sinister energy eminating from it.";
}

Key::~Key()
{}

