#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>

#include "Monsters.h"
#include "Market.h"
#include "Squad.h"

#define HEIGHT 5
#define WIDTH 5

using namespace std;

class Grid{
    list <Monster *> Dragons;
    list <Monster *> Exoskeletons;
    list <Monster *> Spirits;
    list <Monster *> Monsters;

    int** Map;
    Market* market;        
    Squad* team;
    int x,y;                            //to keep track of the current location of the players
    int px, py, pt;                     //previous location


public:
    Grid(Market*, Squad*);
    ~Grid();

    void move_up();
    void move_down();
    void move_right();
    void move_left();
    int battle();
    void enter_battle();

    void insert_Dragon(string, int , int, int, int, int);
    void insert_Exoskeleton(string, int , int, int, int, int);
    void insert_Spirit(string, int , int, int, int, int);
    void insert_Monster(Monster *);
    void display_generalinfo();
    void get_monsters(int);
    int monsters_fainted();

    Squad* get_squad();

    void display_Map();
    void gameplay();
};

#endif