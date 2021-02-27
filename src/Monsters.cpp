#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "../include/Monsters.h"

using namespace std;

//---------------------Monster---------------------

Monster::Monster(string nam, int hp, int da, int de, int a, int lvl)
    :Living(nam,hp),Damage(da),Agility(a),Defence(de){
    cout << da << endl;
    Level = lvl;
}

int Monster::get_Damage(){
    return Damage;
}

int  Monster::get_Defence(){
    return Defence;
}

int Monster::get_Avoid(){
    return Agility;
}

void Monster::decrease_damage(int dmg){
    Damage-= dmg;
}

void Monster::decreade_def(int def){
    Defence-= def;
}

void Monster::decrease_Agility(int ag){
    Agility-= ag;
}

void Monster::get_attacked(Spell* sp){
    string spell;
    spell = sp->get_class();

    int red;
    red = sp->get_Reduction();

    if(spell == "IceSpell"){
        red = Damage*red/100;
        decrease_damage(red);
    }else if(spell == "FireSpell"){
        red = Defence*red/100;
        decreade_def(red);
    }else{
        red = Agility*red/100;
        decrease_Agility(red);
    }
}

void Monster::level_up(){}

void Monster::display_stats(){
    cout << name << " " << Level << " " << HealthPower << " " << Damage << " " << Defence << " " << Agility << endl;
}

void Monster::get_attacked(int dmg){
    int p = rand()%100;

    if(p <= Agility){
        cout << name << " dodged the attack!" << endl;
    }else{
        HealthPower -= dmg + Defence;
        cout << name << " was hit for " << dmg << " points of damage" << endl;
    }
}

void Monster::attack(Hero* hr){
    hr->get_attacked(Damage);
}

//----------------------Dragon-----------------------

Dragon::Dragon(string nam, int hp, int dmg, int def, int ag, int lvl)
    :Monster(nam, hp, dmg, def, ag, lvl){
}

//----------------------Exoskeleton-----------------------

Exoskeleton::Exoskeleton(string nam, int hp, int dmg, int def, int ag, int lvl)
    :Monster(nam, hp, dmg, def, ag, lvl){
}

//----------------------Spirit-----------------------

Spirit::Spirit(string nam, int hp, int dmg, int def, int ag, int lvl)
    :Monster(nam, hp, dmg, def, ag, lvl){
}

