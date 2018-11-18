/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: All characters located throughout the game - this includes the hero plus all of the enemies
*/

#include "Characters.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// Equipped Object
Equipped equip;

Characters::Characters()
{
	strength = 5;
	level = 0;
	name = "NAME";
	isDead = false;
}

Characters::~Characters()
{}

bool Characters::fatalBlow()
{
	if (strength <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Characters::getName()
{
	return name;
}

void Characters::setName(string thing)
{
	name = thing;
}

int Characters::getStrength()
{
	return strength;
}

void Characters::setStrength(int num)
{
	strength = num;
}

int Characters::getLevel()
{
	return level;
}

void Characters::setLevel(int num)
{
	level = num;
}

void Characters::levelUp()
{
	strength = strength + 2;
	level = level + 1;
}

int Characters::getHealth()
{
	return strength;
}

void Characters::setHealth(int hp)
{
	strength = hp;
}	

// Hero**********************************************************************
Hero::Hero()
{
	strength = 10;
	level = 1;
	name = "Hero";
	isDead = false;
}

Hero::~Hero()
{}

int Hero::attack()
{

	int totalAttack = 0;
	// Two-Handed Wooden Sword Equipped
	if(equip.getSword() == "Two-Handed Wooden Sword")
	{
		totalAttack = (rand() % 4) + 1;
	}
	// Two-Handed Bronze Sword Equipped
	else if(equip.getSword() == "Two-Handed Bronze Sword")
	{
		totalAttack = (rand() % 4) + 5; 
	}
	// Two-Handed Silver Sword Equipped
	else if(equip.getSword() == "Two-Handed Silver Sword")
	{
		totalAttack = (rand() % 4) + 9;
	}
	// Two-Handed Gold Sword Equipped
	else if(equip.getSword() == "Two-Handed Gold Sword")
	{
		totalAttack = (rand() % 4) + 13;
	}
	// Two-Handed Ultimate Sword Equipped
	else if(equip.getSword() == "Two-Handed Ultimate Sword")
	{
		totalAttack = (rand() % 4) + 21;
	}	
	cout << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Hero::defense(int damage)
{

	int totaldefense = 0;
	// Tunic Armor Equipped
	if(equip.getArmor() == "Tunic Armor")
	{
		totaldefense = (rand() % 4) + 3;
	}
	// Bronze Armor Equipped
	else if(equip.getArmor() == "Bronze Armor")
	{
		totaldefense = (rand() % 4) + 7;
	}
	// Silver Armor Equipped
	else if(equip.getArmor() == "Silver Armor")
	{
		totaldefense = (rand() % 4) + 11;
	}
	// Gold Armor Eqipped
	else if(equip.getArmor() == "Gold Armor")
	{
		totaldefense = (rand() % 4) + 15;
	}
	// Ultimate Armor Equipped
	else if(equip.getArmor() == "Ultimate Armor")
	{
		totaldefense = (rand() % 4) + 23;
	}
	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Rat ********************************************************************
Rat::Rat()
{
	strength = 6;
	level = 1;
	name = "Giant Rat";
	isDead = false;
}

Rat::~Rat()
{}

int Rat::attack()
{
	int totalAttack = (rand() % 3) + 2;

	cout << "The " << name << " attacked for " << totalAttack << endl;
	
	return totalAttack;
}

void Rat::defense(int damage)
{
	int totaldefense = (rand() % 2) + 1;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Goblin ******************************************************************
Goblin::Goblin()
{
	strength = 8;
	level = 2;
	name = "Goblin";
	isDead = false;
}

Goblin::~Goblin()
{}

int Goblin::attack()
{
	int totalAttack = (rand() % 4) + 2;

	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Goblin::defense(int damage)
{
	int totaldefense = (rand() % 4) + 4;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Hobgoblin *************************************************************
Hobgoblin::Hobgoblin()
{
	strength = 10;
	level = 3;
	name = "Hobgoblin";
	isDead = false;
}

Hobgoblin::~Hobgoblin()
{}

int Hobgoblin::attack()
{
	int totalAttack = (rand() % 7) + 5;

	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Hobgoblin::defense(int damage)
{
	int totaldefense = (rand() % 6) + 4;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Naga **********************************************************************
Naga::Naga()
{
	strength = 8;
	level = 4;
	name = "Naga";
	isDead = false;
}

Naga::~Naga()
{}

int Naga::attack()
{
	int totalAttack = (rand() % 7) + 9;

	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Naga::defense(int damage)
{
	int totaldefense = (rand() % 4) + 4;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Troll ******************************************************************
Troll::Troll()
{
	strength = 14;
	level = 5;
	name = "Troll";
	isDead = false;
}

Troll::~Troll()
{}

int Troll::attack()
{
	int totalAttack = (rand() % 8) + 8;

	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Troll::defense(int damage)
{
	int totaldefense = (rand() % 7) + 7;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Wizard ****************************************************************
Wizard::Wizard()
{
	strength = 10;
	level = 6;
	name = "Wizard";
	isDead = false;
}

Wizard::~Wizard()
{}

int Wizard::attack()
{
	int totalAttack = (rand() % 10) + 10;
	
	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Wizard::defense(int damage)
{
	int totaldefense = (rand() % 6) + 4;

	int d = damage - totaldefense;


	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Gang of Bandits **************************************************************
Gang_of_Bandits::Gang_of_Bandits()
{
	strength = 15;
	level = 7;
	name = "Gang of Bandits";
	isDead = false;
}

Gang_of_Bandits::~Gang_of_Bandits()
{}

int Gang_of_Bandits::attack()
{
	int attack1 = (rand() % 3) + 4;
	int attack2 = (rand() % 3) + 4;
	int attack3 = (rand() % 3) + 4;

	int twoAttack = attack1 + attack2;
	int totalAttack = attack1 + attack2 + attack3;

	if (strength > 10 && strength <= 15)
	{
		cout << "Three Bandits attacked for " << totalAttack << endl;
		return totalAttack;
	}

	else if (strength > 5 && strength <= 10)
	{
		cout << "Two Bandits attacked for " << twoAttack << endl;
		return twoAttack;
	}
	else
	{
		cout << "One Bandit attacked for " << attack1 << endl;
		return attack1;
 	}
}

void Gang_of_Bandits::defense(int damage)
{
	int defense1 = (rand() % 4) + 2;
	int defense2 = (rand() % 4) + 2;
	int defense3 = (rand() % 4) + 2;

	int twoDefense = defense1 + defense2;
	int totaldefense = defense1 + defense2 + defense3;
	int d;

	// Get damage calculation depending on bandits alive
	if (strength > 10 && strength <= 15)
	{
		d = damage - totaldefense;
	}
	else if (strength > 5 && strength <= 10)
	{
		d = damage - twoDefense;
	}
	else
	{
		d = damage - defense1;
	}

	cout << totaldefense << endl;

	// Output statements for damage	
	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " were hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}
}

// Mountain Giant ***************************************************************
Mountain_Giant::Mountain_Giant()
{
	strength = 16;
	level = 8;
	name = "Mountain Giant";
	isDead = false;
}

Mountain_Giant::~Mountain_Giant()
{}

int Mountain_Giant::attack()
{
	int totalAttack = (rand() % 9) + 12;

	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Mountain_Giant::defense(int damage)
{
	int totaldefense = (rand() % 7) + 10;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Lesser Drake ********************************************************************
Lesser_Drake::Lesser_Drake()
{
	strength = 18;
	level = 9;
	name = "Lesser Drake";
	isDead = false;
}

Lesser_Drake::~Lesser_Drake()
{}

int Lesser_Drake::attack()
{
	int totalAttack = (rand() % 7) + 14;

	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Lesser_Drake::defense(int damage)
{
	int totaldefense = (rand() % 5) + 10;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}

// Dragon ************************************************************************
Dragon::Dragon()
{
	strength = 25;
	level = 10;
	name = "Dragon";
	isDead = false;
}

Dragon::~Dragon()
{}

int Dragon::attack()
{
	int totalAttack = (rand() % 8) + 18;

	cout << "The " << name << " attacked for " << totalAttack << endl;

	return totalAttack;
}

void Dragon::defense(int damage)
{
	int totaldefense = (rand() % 11) + 13;

	int d = damage - totaldefense;

	cout << totaldefense << endl;

	if (d <= 0)
	{
		cout << "The " << name << " took no damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

	else if (d >= 1)
	{
		strength -= d;
		cout << "The " << name << " was hit for " << d << " damage" << endl;
		cout << name << " Health: " << strength << " HP" << endl;
	}

}
