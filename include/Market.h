#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include "Items.h"
#include <string>
#include <list>

#include "Squad.h"

using namespace std;

class Market {

private:

	list <Weapon*> Weapons;
	list <Armor*> Armors;
	list <Potion*> Potions;

	list <Spell*> Spells;
	list <Item*> ItemsToSell;
	Squad* team;

public:

	Market(Squad*);
	~Market();


	void AddWeapon(string, int, int, int, int);
	void AddArmor(string, int, int, int);
	void AddPotion(string, string, int, int, int);
	void AddIceSpell(string, int, int, int, int, int);
	void AddFireSpell(string, int, int, int, int, int);
	void AddLightingSpell(string, int, int, int, int, int);
	// void AddSpell(string,int,int,int,int,int);
	void displayItems();
	void EnterMarket();
	void buy();
	void sell();
	


};

#endif