#include <iostream>
#include <string>
#include "../include/Spells.h"

using namespace std;

//------------------------Spell---------------------

Spell::Spell(string nam, int p, int m, int d, int e)
    :Item(nam,p,m),DmgRange(d),MagicEnergy(e){}

int Spell::get_DmgRange(){
    return DmgRange;
}

int Spell::get_MagicPower(){
    return MagicEnergy;
}

//-------------------------Ice Spell--------------------

IceSpell::IceSpell(string nam, int p, int m, int d, int e, int r):
    Spell(nam,p,m,d,e),DmgReduction(r){
}

string IceSpell::get_class(){
    return "IceSpell";
}

int IceSpell::get_Reduction() {
	return DmgReduction;
}

//-------------------------Fire Spell----------------------

FireSpell::FireSpell(string nam, int p, int m, int d, int e, int r):
    Spell(nam,p,m,d,e),DefReduction(r){
}

string FireSpell::get_class(){
    return "FireSpell";
}

int FireSpell::get_Reduction() {
	return DefReduction;
}

//-----------------------Lighting Spell----------------------

LightingSpell::LightingSpell(string nam, int p, int m, int d, int e, int r):
    Spell(nam,p,m,d,e),AgilityReduction(r){
}

string LightingSpell::get_class(){
    return "LightingSpell";
}

int LightingSpell::get_Reduction() {
	return AgilityReduction;
}
