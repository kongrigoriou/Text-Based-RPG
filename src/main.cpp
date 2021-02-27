#include <iostream>
#include <string>
#include <fstream>

#include "../include/Grid.h"

using namespace std;

int main(void){

    Squad team;
    Market m(&team);
    Grid grid(&m, &team);

    //Armors
    ifstream Armors;
    Armors.open("./data/Armors.txt");

    string name;
    int price, lvl, def;
    if(Armors.is_open()){
        while (Armors >> name >> price >> lvl >> def){
            m.AddArmor(name, price, lvl, def);
        }
    }else{
        cout << "File Armors could not be opened." << endl;
        return 1;
    }

    //Weapons
    ifstream Weapons;
    Weapons.open("./data/Weapons.txt");

    int dmg, hands;
    if(Weapons.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (Weapons >> name >> price >> lvl >> dmg >> hands){
            cout << name << price << endl;
            m.AddWeapon(name, price, lvl, hands, dmg);
        }
    }else{
        cout << "File Weapons could not be opened." << endl;
        return 1;
    }

    //Potions
    ifstream Potions;
    Potions.open("./data/Potions.txt");

    string buff;
    if(Potions.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (Potions >> name >> price >> lvl >> buff >> dmg){         //dmg aka buff%
            m.AddPotion(name, buff, lvl, price, dmg);
        }
    }else{
        cout << "File Potions could not be opened." << endl;
        return 1;
    }

    //Fire Spells
    ifstream FireSpells;
    FireSpells.open("./data/FireSpells.txt");

    int rounds, magic;
    if(FireSpells.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (FireSpells >> name >> price >> lvl >> magic >> dmg >> rounds){         //dmg aka buff%
            m.AddFireSpell(name, price, lvl, dmg, magic, rounds);
        }
    }else{
        cout << "File FireSpells could not be opened." << endl;
        return 1;
    }

    //Ice Spells
    ifstream IceSpells;
    IceSpells.open("./data/IceSpells.txt");

    if(IceSpells.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (IceSpells >> name >> price >> lvl >> magic >> dmg >> rounds){         //dmg aka buff%
            m.AddIceSpell(name, price, lvl, dmg, magic, rounds);
        }
    }else{
        cout << "File IceSpells could not be opened." << endl;
        return 1;
    }

    //Lighting Spells
    ifstream LightingSpells;
    LightingSpells.open("./data/LightingSpells.txt");

    if(LightingSpells.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (LightingSpells >> name >> price >> lvl >> magic >> dmg >> rounds){         //dmg aka buff%
            m.AddLightingSpell(name, price, lvl, dmg, magic, rounds);
        }
    }else{
        cout << "File LightingSpells could not be opened." << endl;
        return 1;
    }

    //Dragons
    ifstream Dragons;
    Dragons.open("./data/Dragons.txt");

    int hp, ag;
    if(Dragons.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (Dragons >> name >> hp >> dmg >> def >> ag >> lvl){
            grid.insert_Dragon(name, hp, dmg, def, ag, lvl);
            cout <<"Dragon here: " << name << endl;
            cout << "With Damage: " << dmg << endl; 
        }
    }else{
        cout << "File Dragons could not be opened." << endl;
        return 1;
    }

    //Exoskeletons
    ifstream Exoskeletons;
    Exoskeletons.open("./data/Exoskeletons.txt");

    if(Exoskeletons.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (Exoskeletons >> name >> hp >> dmg >> def >> ag >> lvl){
            grid.insert_Exoskeleton(name, hp, dmg, def, ag, lvl);
        }
    }else{
        cout << "File Exoskeletons could not be opened." << endl;
        return 1;
    }

    //Spirits
    ifstream Spirits;
    Spirits.open("./data/Spirits.txt");

    if(Spirits.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (Spirits >> name >> hp >> dmg >> def >> ag >> lvl){
            grid.insert_Spirit(name, hp, dmg, def, ag, lvl);
        }
    }else{
        cout << "File Spirits could not be opened." << endl;
        return 1;
    }

    //Warriors
    ifstream Warriors;
    Warriors.open("./data/Warriors.txt");

    int dex;
    if(Warriors.is_open()){
        cout << "-----------------------------------------------------------------------" << endl;
        while (Warriors >> name >> hp >> magic >> dmg >> ag >> dex){
            team.insert_Warrior(name, hp, magic, dmg, ag, dex);
        }
    }else{
        cout << "File Spirits could not be opened." << endl;
        return 1;
    }

    // //Paladins
    // ifstream Paladins;
    // Paladins.open("./data/Paladins.txt");

    // if(Paladins.is_open()){
    //     cout << "-----------------------------------------------------------------------" << endl;
    //     while (Paladins >> name >> hp >> magic >> dmg >> ag >> dex){
    //         team.insert_Paladin(name, hp, magic, dmg, ag, dex);
    //     }
    // }else{
    //     cout << "File Paladins could not be opened." << endl;
    //     return 1;
    // }

    //leipoun ta arxeia gia sorcerers/paladins

    grid.gameplay();

}