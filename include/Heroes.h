#ifndef HEROES_H
#define HEROES_H

#include <iostream>
#include <string>
#include <list>
#include "Items.h"
#include "Spells.h"

using namespace std;

class Monster;

class Living{
protected:
    string name;
    int Level;
    int HealthPower;
    int Max_HP;

public:
    Living(string, int);

    string get_name();
    void set_dedhp();
    int get_level();
    int get_HealthPower();
    int get_Max_hp();
    void regen_health();

    virtual void dec_hp(int);
    virtual void level_up() = 0;
};

class Hero: public Living{
protected:
    int MagicPower;
    int Strength;
    int Agility;
    int Dexterity;
    int Defense;
    int Money;
    int exp;
    int NextLvlExp;
    Weapon* Weapon_Equiped;
    Armor* Armor_Equiped;

    list <Weapon *> Weapons;
    list <Spell *> Spells;
    list <Armor *> Armors;
    list <Potion *> Potions;

public:
    Hero(string, int, int, int, int, int);

    int get_MagicPower();
    int get_Strength();
    int get_Agility();
    int get_Dexterity();
    int get_Money();
    int get_exp();
    int get_NextLvlExp();
    int GetWeaponsListSize();
    void set_money(int);
    void set_NextLvlExp();

    void decrease_MagicP(int);

    void buy_Weapon(Weapon *);
    void buy_Armor(Armor *);
    void buy_Potion(Potion *);
    void buy_Spell(Spell *);
    void sell_Weapon(Weapon *);
    void sell_Armor(Armor *);
    void sell_Potion(Potion *);
    void sell_Spell(Spell *);

    virtual string get_class() = 0;
    void display_inventory();
    void display_stats();
    void display_Weapons();
    void display_Armors();
    void display_Potions();
    void lost_round();
    void round_won();


    void regen_magicpower();
    void hp_tohalf();
    void get_attacked(int);

    void equip_weapon(string);
    void equip_armor(string);
    void attack(Monster*);
    Spell* castSpell(string);
    void usePotion(string);
    virtual void level_up() = 0;

};

class Warrior: public Hero{

public:
    Warrior(string, int, int, int, int, int);
    string get_class();
    void level_up();
};

class Sorcerer: public Hero{

public:
    Sorcerer(string, int, int, int, int, int);
    string get_class();
    void level_up();

};

class Paladin: public Hero{

public:
    Paladin(string, int, int, int, int, int);
    string get_class();
    void level_up();

};

#endif