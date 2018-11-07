/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: All containers used throughout the game
*/

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Objects.hpp"
using namespace std;

class Container
{
	private:
		vector<Objects> tester;
	public:
		Container();
		~Container();
		virtual void addToContainer(Objects obj);
		virtual void deleteFromContainer(Objects obj);
		virtual void printContainer();

};
#endif // !CONTAINER_HPP

// Bag*********************************************************************************
class Bag : public Container
{
	private:
		vector<Objects> bag;
	public:
		Bag();
		~Bag();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void transferToForge(Objects obj);
		void transferToStash(Objects obj);
		void transferToEquipped(Objects obj1, Objects obj2);
		void insert(int, Objects obj);
};

// Forge*******************************************************************************
class Forge: public Container
{
	private:
		vector<Objects> forge;
		bool forgeStart;
		bool craftUltWeapon;
		bool craftUltArmor;
	public:
		Forge();
		~Forge();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		bool getForgeStart();
		bool startForge();
		bool ultWeaponCrafted();
		bool ultArmorCrafted();
		void transferToBag(Objects obj);
};

// Stash*******************************************************************************
class Stash : public Container
{
	private:
		vector<Objects> stash;
	public:
		Stash();
		~Stash();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void transferToBag(Objects obj);
};

// Equipped****************************************************************************
class Equipped : public Container
{
	private:
		vector<Objects> equipped;
		Objects *obj1;
		Objects *obj2;
	public:
		Equipped();
		~Equipped();
		void addToContainer(Objects obj);
		void deleteFromContainer(Objects obj);
		void printContainer();
		void transferToBag(Objects obj1, Objects obj2);
		string getSword();
		string getArmor();
		void insert(int, Objects obj);
};
