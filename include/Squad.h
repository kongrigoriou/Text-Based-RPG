#ifndef SQUAD_H
#define SQUAD_H

#include <iostream>
#include <string>
#include "Heroes.h"

class Squad {
    list <Hero*> myHeroes;
    list <Hero*> Warriors;
    list <Hero*> Sorcerers;
    list <Hero*> Paladins;

public:
    Squad();
    ~Squad();

    void insert_Warrior(string, int, int, int, int, int);
    void insert_Sorcerer(string, int, int, int, int, int);
    void insert_Paladin(string, int, int, int, int, int);
    void inser_Hero(Hero*);

    void display_allHeroes();
    void display_myHeroes();
    void select_hero(string);
    Hero* search_Hero(string);
    list <Hero*> get_HeroList();
    int get_count();
    int all_fainted();
};

#endif