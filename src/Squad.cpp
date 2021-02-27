#include <iostream>
#include <iterator>

#include "../include/Squad.h"

using namespace std;

Squad::Squad(){}

Squad::~Squad(){
    myHeroes.clear();
    Warriors.clear();
    Sorcerers.clear();
    Paladins.clear();
}

void Squad::insert_Warrior(string name, int hp, int mp, int str, int ag, int dex){

    cout << name << "\n"<< hp << "\n" << mp << "\n" << str << "\n" << ag << "\n" << dex << endl;

    Warrior* hero = new Warrior(name,hp,mp,str,ag,dex);
    Warriors.push_front(hero);
}

void Squad::insert_Sorcerer(string name, int hp, int mp, int str, int ag, int dex){

    Sorcerer* hero = new Sorcerer(name,hp,mp,str,ag,dex);
    Sorcerers.push_back(hero);
}

void Squad::insert_Paladin(string name, int hp, int mp, int str, int ag, int dex){

    Paladin* hero = new Paladin(name,hp,mp,str,ag,dex);
    Paladins.push_front(hero);
}

void Squad::display_allHeroes(){
    
    cout << "Pick your Heroes!" << endl;

    cout << "Available Warriors:" << endl;

    list <Hero*>::iterator it;

    // cout << "NAME   HP  "
    for(it = Warriors.begin(); it != Warriors.end(); ++it){
        cout << (*it)->get_name() << "\t\t" << (*it)->get_HealthPower() << "\t" << (*it)->get_MagicPower() 
        << "\t" << (*it)->get_Strength() << "\t" << (*it)->get_Agility() << "\t" << (*it)->get_Dexterity() << endl;
    }

    cout << "Available Sorcerers:" << endl;

    list <Hero*>::iterator it2;

    for(it2 = Sorcerers.begin(); it2 != Sorcerers.end(); ++it){
        cout << (*it)->get_name() << "\t" << (*it)->get_HealthPower() << "\t" << (*it)->get_MagicPower() 
        << "\t" << (*it)->get_Strength() << "\t" << (*it)->get_Agility() << "\t" << (*it)->get_Dexterity() << endl;
    }

    cout << "Available Paladins:" << endl;

    list <Hero*>::iterator it3;

    for(it3 = Paladins.begin(); it3 != Paladins.end(); ++it){
        cout << (*it)->get_name() << "\t" << (*it)->get_HealthPower() << "\t" << (*it)->get_MagicPower() 
        << "\t" << (*it)->get_Strength() << "\t" << (*it)->get_Agility() << "\t" << (*it)->get_Dexterity() << endl;
    }

}

void Squad::display_myHeroes(){
    list<Hero*>::iterator it;
    for(it = myHeroes.begin(); it != myHeroes.end(); ++it){
        cout << (*it)->get_name() << "\t" << (*it)->get_HealthPower() << "\t" << (*it)->get_MagicPower() 
        << "\t" << (*it)->get_Strength() << "\t" << (*it)->get_Agility() << "\t" << (*it)->get_Dexterity() << endl;
    }
}

void Squad::select_hero(string name){
    if(myHeroes.size() == 3){
        cout << "Your Team is full!" << endl;
        return;
    }else{
        Hero* temp;
        string type;
        temp = search_Hero(name);
        if(temp != NULL){
            myHeroes.push_front(temp);
            cout << temp->get_name() << " is now part of your team!" << endl;
        }
    }
}

Hero* Squad::search_Hero(string name){
    list<Hero*>::iterator w;
    for(w = Warriors.begin(); w != Warriors.end(); ++w){
        if((*w)->get_name() == name){
            return *w;
        }
    }

    list<Hero*>::iterator s;
    for(s = Sorcerers.begin(); s != Sorcerers.end(); ++s){
        if((*s)->get_name() == name){
            return *s;
        }
    }

    list <Hero*>::iterator p;
    for(p = Paladins.begin(); p != Paladins.end(); ++p){
        if((*p)->get_name() == name){
            return *p;
        }
    }

    cout << "I could not find this name :(" << endl;
    return NULL;
}

list <Hero*> Squad::get_HeroList(){
    return myHeroes;
}

int Squad::get_count(){
    return myHeroes.size();
}

int Squad::all_fainted(){
    int count = 0;
    list<Hero*>::iterator it;

    for(it = myHeroes.begin(); it != myHeroes.end(); ++it){
        if((*it)->get_HealthPower() <= 0)
            count++;
    }

    if(count == get_count())
        return 1;
    else
        return 0;
}