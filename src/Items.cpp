#include <iostream>
#include <string>
#include "../include/Items.h"

using namespace std;

//------------------Items----------------
Item::Item(string nam, int p, int m):name(nam),price(p), MinLvl(m){}

string Item::get_name(){
    return name;
}

int Item::get_price(){
    return price;
}

int Item::get_minlvl(){
    return MinLvl;
}


int Item::get_handsNeeded() {
	return 0;
}

int Item::get_damage() {
	return 0;
}

void Item::set_damage() {
	return;
}

int Item::get_protection() {
	return 0;
}

int Item::get_buff() {
	return 0;
}


Item::~Item(){
	cout << "An Item is being destroyed" << endl;
}

//-------------------Weapons-----------------------

Weapon::Weapon(string nam, int p, int m, int h, int d):Item(nam, p, m),handsNeeded(h),damage(d){
    cout << "A Weapon was just created" << endl;
}

int Weapon::get_handsNeeded(){
    return handsNeeded;
}

int Weapon::get_damage(){
    return damage;
}

void Weapon::set_damage(int str){
    damage += str;
}

string Weapon::get_class(){
    return "Weapon";
}

Weapon::~Weapon() {
	cout << "A Weapon was just destroyed" << endl;
}

//--------------------Armor--------------------------

Armor::Armor(string nam, int p, int m, int pr):Item(nam, p, m),protection(pr){
    cout << "An Armor was just created" << endl;
}

int Armor::get_protection(){
    return protection;
}

string Armor::get_class(){
    return "Armor";
}

Armor::~Armor() {
	cout << "An Armor was just destroyed" << endl;
}

//-------------------Potions--------------------------

Potion::Potion(string nam, string t, int p, int m, int b):Item(nam, p, m), buff(b), stat(t){
    cout << "A Potion was just created" << endl;
}

int Potion::get_buff(){
    return buff;
}

string Potion::get_class(){
    return "Potion";
}

string Potion::get_statname(){
	return stat;
}

Potion::~Potion() {
	cout << "A Potion was just destroyed" << endl;
}