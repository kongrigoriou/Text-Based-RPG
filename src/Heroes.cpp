#include <iostream>
#include <string>
#include "../include/Heroes.h"
#include "../include/Monsters.h"

using namespace std;

//---------------------Living------------------

Living::Living(string nam, int hp)
    :name(nam),HealthPower(hp){
    Level = 1;
}

string Living::get_name(){
    return name;
}

int Living::get_level(){
    return Level;
}

int Living::get_HealthPower(){
    return HealthPower;
}

void Living::dec_hp(int dmg){
    HealthPower -= dmg;
    cout << name << " was hit for " << dmg << " points of damage." << endl;
    if(HealthPower <= 0){
        cout << name << " just fainted. :(" << endl;
    }
}

//-----------------------Heroes----------------------

Hero::Hero(string nam, int hp, int mp, int str, int ag, int dex)
    :Living(nam,hp),MagicPower(mp),Strength(str),Agility(ag),Dexterity(dex){
    Money = 500;
    exp = 0;
    NextLvlExp = 20;
    Armor_Equiped = NULL;
    Weapon_Equiped = NULL;
    Defense = 5;
}

int Hero::get_MagicPower(){
    return MagicPower;
}

int Hero::get_Strength(){
    return Strength;
}

int Hero::get_Agility(){
    return Agility;
}

int Hero::get_Dexterity(){
    return Dexterity;
}

int Hero::get_Money(){
    return Money;
}

int Hero::get_exp(){
    return exp;
}

int Hero::get_NextLvlExp(){
    return NextLvlExp;
}

void Hero::set_money(int m){
    Money+= m;
}

void Hero::set_NextLvlExp(){
    NextLvlExp += NextLvlExp*(50/100);
}

void Hero::decrease_MagicP(int m){
    MagicPower-= m;
}

void Hero::buy_Weapon(Weapon * w){
    if(Money < w->get_price()){
        cout << "Not enough money!" << endl;
        return;
    }

    Money -= w->get_price();
    Weapons.push_front(w);
    cout << "You succesfully bought a new WEAPON: " << w->get_name() << endl;
}

void Hero::buy_Armor(Armor * a){
    if(Money < a->get_price()){
        cout << "Not enough money!" << endl;
        return;
    }

    Money -= a->get_price();
    Armors.push_front(a);
    cout << "You succesfully bought a new ARMOR: " << a->get_name() << endl;
}

void Hero::buy_Potion(Potion * p){
    if(Money < p->get_price()){
        cout << "Not enough money!" << endl;
        return;
    }

    Money -= p->get_price();
    Potions.push_front(p);
    cout << "You succesfully bought a new POTION: " << p->get_name() << endl;
}

void Hero::buy_Spell(Spell * s){
    if(Money < s->get_price()){
        cout << "Not enough money!" << endl;
        return;
    }

    Money -= s->get_price();
    Spells.push_front(s);
    cout << "You succesfully bought a new SPELL: " << s->get_name() << endl;
}

void Hero::sell_Weapon(Weapon * w){
    Money += w->get_price()/2;
    Weapons.remove(w);
    cout << "You sold " << w->get_name() << " for " << w->get_price()/2 << " coins!" << endl;
}

void Hero::sell_Armor(Armor * a){
    Money += a->get_price()/2;
    Armors.remove(a);
    cout << "You sold " << a->get_name() << " for " << a->get_price()/2 << " coins!" << endl;
}

void Hero::sell_Potion(Potion * p){
    Money += p->get_price()/2;
    Potions.remove(p);
    cout << "You sold " << p->get_name() << " for " << p->get_price()/2 << " coins!" << endl;
}

void Hero::sell_Spell(Spell * s){
    Money += s->get_price()/2;
    Spells.remove(s);
    cout << "You sold " << s->get_name() << " for " << s->get_price()/2 << " coins!" << endl;
}

// int Hero::search_inventory(Item * item){
//     // string item->get_class()
// }

void Hero::display_inventory(){

    list<Weapon*> ::iterator it;
    list<Armor*> :: iterator ar;
    list<Potion*> :: iterator pt;
    list<Spell*> :: iterator is;
    cout << "Weapons are" << endl;
    for (it = Weapons.begin(); it !=  Weapons.end(); ++it){
        cout << (*it)->get_name() << " " ;
    }
    cout << endl;
    cout << "Armors are" << endl;
	for(ar = Armors.begin(); ar != Armors.end(); ++ar){
        cout << (*ar)->get_name() << " ";
    }
    cout << endl;
    cout << "Potions are" << endl;
    for(pt = Potions.begin(); pt != Potions.end(); ++pt){
        cout <<(*pt)->get_name() << " " ;
    }
    cout << endl;
    cout << "Spells are" << endl;
   for(is = Spells.begin(); is!= Spells.end(); ++is){
       cout << (*is)->get_name() << " ";
   }
   cout << endl;
}

void Hero::display_stats(){
    cout << name << "   Level: " << Level << endl;
    cout << "XP: " << exp << "/" << NextLvlExp << endl;
    cout << "HP: " << HealthPower << endl;
    cout << "Coins: " << Money << endl; 
    cout << "Strength: " << Strength << endl;
    cout << "Agility: " << Agility << endl;
    cout << "Dexterity: " << Dexterity << endl;
    cout << "Defense: " << Defense << endl;
    cout << "MAgic Power: " << MagicPower << endl;
}

void Hero::display_Weapons(){
    list<Weapon*>::iterator it;

    for(it = Weapons.begin(); it != Weapons.end(); ++it){
        cout << (*it)->get_name() << endl;
        cout << "Damage: " << (*it)->get_damage() << endl;
        cout << "Hands needed: " << (*it)->get_handsNeeded() << endl;
    }
}

void Hero::display_Armors(){
    list<Armor*>::iterator it;

    for(it = Armors.begin(); it != Armors.end(); ++it){
        cout << (*it)->get_name() << endl;
        cout << "Defense: " << (*it)->get_protection() << endl;
    }
}

void Hero::display_Potions(){
    list<Potion*>::iterator it;

    for(it = Potions.begin(); it != Potions.end(); ++it){
        cout << (*it)->get_name() << endl;
        cout << "Stat: " << (*it)->get_statname();
        cout << "% " << (*it)->get_buff() << endl;
    }
}

void Living::regen_health(){

    HealthPower += 10;

}


void Hero::regen_magicpower(){

    MagicPower += 10;

}


void Hero::hp_tohalf(){

    if(HealthPower <= 0){

        HealthPower = Max_HP/2;

    }
}


void Hero::equip_weapon(string weapon_name){

    int flag = 0;
    list<Weapon*> :: iterator wp;
    cout << GetWeaponsListSize() << endl;
    for(wp = Weapons.begin(); wp != Weapons.end(); ++wp){

        if( (*wp)->get_name() == weapon_name){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        Strength += (*wp)->get_damage();
        Weapon_Equiped = (*wp);
    }else{
        cout << "You dont have that weapon in your inventory" << endl;
    }
}

void Hero::equip_armor(string armor_name){

    int flag = 0;
    list<Armor*> :: iterator ar;
    for(ar = Armors.begin(); ar != Armors.end(); ++ar){

        if( (*ar)->get_name() == armor_name){
            flag =1;
            break;
        }
    }

    if(flag == 1){
        Defense += (*ar)->get_protection();
        Armor_Equiped = (*ar);
    }else{

        cout << "You dont have that armor in your inventory" << endl;
    }
}

int Hero::GetWeaponsListSize(){

    return Weapons.size();

}

Spell * Hero::castSpell(string spell_name){
    int flag = 0;
    list<Spell*> :: iterator is;

    for(is = Spells.begin(); is!= Spells.end(); ++is){
          
        if((*is)->get_name() == spell_name){
            flag = 1;
            break;
        }

    }


    if(flag == 1){

         if(MagicPower >= (*is)->get_MagicPower()){

            MagicPower -= (*is)->get_MagicPower();

         }
         return *is;

    }else{

        cout << "You dont have that spell in your inventory" << endl;
    }



}

void Hero::usePotion(string potion_name){

    int flag = 0;
    list<Potion*> :: iterator pt;
    for(pt = Potions.begin(); pt != Potions.end(); ++pt){

        if( (*pt)->get_name() == potion_name) {
            flag = 1;
            break;
            
        }

    }

    if(flag == 1){
        if( (*pt)->get_statname() == "MagicPower"){

            MagicPower += (*pt)->get_buff();

        }else if( (*pt)->get_statname() == "HealthPower"){

            HealthPower = HealthPower + (*pt)->get_buff()*HealthPower/100;


        }else if((*pt)->get_statname() == "Strength"){

            Strength = Strength + (*pt)->get_buff()*Strength/100;


        }else if((*pt)->get_statname() == "Agility"){

            Agility = Agility + (*pt)->get_buff()*Agility/100;


        }else if((*pt)->get_statname() == "Dexterity"){

            Dexterity = Dexterity + (*pt)->get_buff()*Dexterity/100;

        }
        Potions.remove(*pt);

    }else{

         cout << "You dont have that potion in your inventory" << endl;
    }
}

void Hero::attack(Monster* m){
    m->get_attacked(Strength);
}

void Hero::get_attacked(int dmg){
    int p = rand()%100;

    if(p <= Agility){
        cout << name << " dodged the Monster's attack!" << endl;
    }else{
        dec_hp(dmg);
        HealthPower += Defense;
    }
}

void Hero::lost_round(){
    Money -= Money/2;
}

void Hero::round_won(){
    Money += Level*25;
    exp += Level*20;
    if(exp >= NextLvlExp){
        Level++;
        exp = 0;
        set_NextLvlExp();
    }
}


//-----------------------Warrior-----------------------

Warrior::Warrior(string nam, int hp, int mp, int str, int ag, int dex)
    :Hero(nam, hp, mp, str, ag, dex){
    cout << "A Warrior was just created" << endl;
}

string Warrior::get_class(){
    return "Warrior";
}

void Warrior::level_up(){
    Strength += Strength*0.3;
    Agility += Agility*0.3;
    Dexterity += Dexterity*0.2;
    Level++;
    set_NextLvlExp();

    cout << "The WARRIOR " << name << " just LEVELED UP. New LEVEL: " << Level << endl;
}

//-----------------------Sorcerer----------------------

Sorcerer::Sorcerer(string nam, int hp, int mp, int str, int ag, int dex)
    :Hero(nam, hp, mp, str, ag, dex){
    cout << "A Sorcerer was just created" << endl;
}

string Sorcerer::get_class(){
    return "Sorcerer";
}

void Sorcerer::level_up(){
    Strength += Strength*0.2;
    Agility += Agility*0.3;
    Dexterity += Dexterity*0.3;
    Level++;
    set_NextLvlExp();

    cout << "The SORCERER " << name << " just LEVELED UP. New LEVEL: " << Level << endl;
}

//-----------------------Paladin----------------------

Paladin::Paladin(string nam, int hp, int mp, int str, int ag, int dex)
    :Hero(nam, hp, mp, str, ag, dex){
    cout << "A Paladin was just created" << endl;
}

string Paladin::get_class(){
    return "Paladin";
}

void Paladin::level_up(){
    Strength += Strength*0.3;
    Agility += Agility*0.2;
    Dexterity += Dexterity*0.3;
    Level++;
    set_NextLvlExp();

    cout << "The PALADIN " << name << " just LEVELED UP. New LEVEL: " << Level << endl;
}
    
    