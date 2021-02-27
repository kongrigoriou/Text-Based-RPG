#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>


using namespace std;

class Item{
protected:
    string name;
    int price;
    int MinLvl;

public:
    Item(string, int, int);
	~Item();

    string get_name();
    int get_price();
    int get_minlvl();
	virtual int get_handsNeeded();
	virtual int get_damage();
	virtual void set_damage();
	virtual int get_protection();
	virtual int get_buff();

};

class Weapon: public Item{
    int handsNeeded;
    int damage;

public:
    Weapon(string, int, int, int, int);
    ~Weapon();

    int get_handsNeeded();
    int get_damage();
    void set_damage(int);
    string get_class();
};

class Armor: public Item{
    int protection;

public:
    Armor(string, int, int, int);
    ~Armor();

    int get_protection();
    string get_class();
};

class Potion: public Item{
    int buff;
    string stat;

public:
    Potion(string, string, int, int, int);
    ~Potion();

    int get_buff();
    string get_class();
    string get_statname();
};

#endif