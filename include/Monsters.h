#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <string>
#include "Heroes.h"


using namespace std;

class Monster: public Living{
protected:
    int Damage;
    int Defence;
    int Agility;

public:
    Monster(string, int, int, int, int, int);

    int get_Damage();
    int get_Defence();
    int get_Avoid();
    void decrease_damage(int);
    void decreade_def(int);
    void decrease_Agility(int);
    void get_attacked(Spell*);
    void get_attacked(int);
    void attack(Hero*);
    void display_stats();

    void level_up();
};

class Dragon: public Monster{

public:
    Dragon(string, int, int, int, int, int);
};

class Exoskeleton: public Monster{

public:
    Exoskeleton(string, int, int, int, int, int);
};

class Spirit: public Monster{

public:
    Spirit(string, int, int, int, int, int);
};

#endif
