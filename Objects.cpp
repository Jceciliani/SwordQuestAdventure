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

int Objects::getId()
{
	return id;
}

void Objects::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;

}


// Two-Handed Wooden Sword *****************************************
Two_Handed_Wooden_Sword::Two_Handed_Wooden_Sword()
{
	name = "wooden sword";
	description = "a couple of boards nailed together. it looks more like a toy than a weapon";
	id = 1;
}

Two_Handed_Wooden_Sword::~Two_Handed_Wooden_Sword()
{}

// Two-Handed Bronze Sword *****************************************
Two_Handed_Bronze_Sword::Two_Handed_Bronze_Sword()
{
	name = "bronze sword";
	description = " an old worn sword made of bronze. there are many chips in its toungue shaped blade";
	id = 2;
}

Two_Handed_Bronze_Sword::~Two_Handed_Bronze_Sword()
{}

// Two-Handed Silver Sword ******************************************
Two_Handed_Silver_Sword::Two_Handed_Silver_Sword()
{
	name = "silver sword";
	description = "a large blade with made of pure silver. it feels well crafted, something you imagine \n"
	"a castle guard might use.";
	id = 3;
}

Two_Handed_Silver_Sword::~Two_Handed_Silver_Sword()
{}

// Two-Handed Gold Sword ********************************************
Two_Handed_Gold_Sword::Two_Handed_Gold_Sword()
{
	name = "gold sword";
	description = "an ornate golden blade. patterns weave down the blade and through the hilt eventually \n"
	"swirling around the large ruby set into its pommel";
	id = 4;
}

Two_Handed_Gold_Sword::~Two_Handed_Gold_Sword()
{}

// Two-Handed Ultimate Sword ****************************************
Two_Handed_Ultimate_Sword::Two_Handed_Ultimate_Sword()
{
	name = "ultimate sword";
	description = "The strongest sword youve ever seen. its blade glows and shimmers with a plethora \n"
	"of colors. you can feel the power contained within it.";
	id = 5;
}

Two_Handed_Ultimate_Sword::~Two_Handed_Ultimate_Sword()
{}

// Tunic Armor *****************************************************
Tunic_Armor::Tunic_Armor()
{
	name = "tunic armor";
	description = " a tattered leather tunic. youre not sure if its dirty from the fall, or if it was \n"
	"always like this";
	id = 6;
}

Tunic_Armor::~Tunic_Armor()
{}

// Bronze Armor ****************************************************
Bronze_Armor::Bronze_Armor()
{
	name = "bronze armor";
	description = "a bronze cheast plate. the worn straps can still hold the mass to your body suprisingly \n"
	" but the vairous puncture holes do not give you faith in its ability";
	id = 7;
}

Bronze_Armor::~Bronze_Armor()
{}

// Silver Armor *****************************************************
Silver_Armor::Silver_Armor()
{
	name = "silver armor";
	description = "a set of silver armor. there are a few pieces missing, but the ones that are there are \n"
	"fairly good quality";
	id = 8;
}

Silver_Armor::~Silver_Armor()
{}

// Gold Armor *******************************************************
Gold_Armor::Gold_Armor()
{
	name = "gold armor";
	description = "a complete set of golden aarmor. intricate designs weave through the plates stemming \n"
	"from a large lions head in the center of the breastplate. its very fancy, but very heavy.";
	id = 9;
}

Gold_Armor::~Gold_Armor()
{}

// Ultimate Armor ***************************************************
Ultimate_Armor::Ultimate_Armor()
{
	name = "ultimate armor";
	description = "the strongest armor created. the surfaces are clean and smooth. it shimmers with \n"
	"the various colors of the spectrum";
	id = 10;
}

Ultimate_Armor::~Ultimate_Armor()
{}

// Forge Hammer *****************************************************
Forge_Hammer::Forge_Hammer()
{
	name = "anvil hammer";
	description = " a hammer used to make weapons and armor. perhaps you can use this";
	id = 11;
}

Forge_Hammer::~Forge_Hammer()
{}

// Flint ************************************************************
Flint::Flint()
{
	name = "flint";
	description = " a substance when struck with steel creates sparks that ignite flame. maybe \n"
	"you can use this";
	id = 12;
}

Flint::~Flint()
{}

// Steel ************************************************************
Steel::Steel()
{
	name = "steel";
	description = "a solid hunk of steel. seems like junk.";
	id = 13;
}

Steel::~Steel()
{}

// Key *************************************************************
Key::Key()
{
	name = "key";
	description = "a large black iron key. you can feel sinister energy eminating from it.";
	id = 14;
}

Key::~Key()
{}

// No Sword *****************************************
No_Sword::No_Sword()
{
	name = "no sword";
	description = "you have no sword. that's not great";
	id = 15;
}

No_Sword::~No_Sword()
{}

// No Armor *****************************************
No_Armor::No_Armor()
{
	name = "no armor";
	description = "you have no armor. fights are gonna hurt";
	id = 16;
}

No_Armor::~No_Armor()
{}
