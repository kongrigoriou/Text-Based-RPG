#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>
#include <string>
#include "Items.h"


using namespace std;

class Spell: public Item{
protected:
    int DmgRange;
    int MagicEnergy;

public:
    Spell(string, int, int, int, int);

    int get_DmgRange();
    int get_MagicPower();

    virtual int get_Reduction(){};
    virtual string get_class(){};

};

class IceSpell: public Spell{
    int DmgReduction;

public:
    IceSpell(string, int, int ,int, int, int);
    string get_class();
    int get_Reduction();
};

class FireSpell: public Spell{
    int DefReduction;

public:
    FireSpell(string, int, int ,int, int, int);
    string get_class();
    
	int get_Reduction();
};

class LightingSpell: public Spell{
    int AgilityReduction;

public:
    LightingSpell(string, int, int ,int, int, int);
    string get_class();
    
	int get_Reduction();
};

#endif