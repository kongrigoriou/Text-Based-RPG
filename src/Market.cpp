#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "../include/Market.h"
#include "../include/Items.h"
#include "../include/Spells.h"
#include "../include/Heroes.h"

using namespace std;

Market::Market(Squad* sq):team(sq){

	// cout << "A Market was just created" << endl;

}

Market::~Market() {

	Weapons.clear();
	Armors.clear();
	Potions.clear();
	Spells.clear();
	ItemsToSell.clear();	

}

void Market::AddWeapon(string name, int cost, int minLevel, int damage, int handsNeeded) {

	Weapon* newItem = new Weapon(name, cost, minLevel, damage, handsNeeded);
	Weapons.push_front(newItem);

}

void Market::AddArmor(string name, int cost, int minLevel, int dmgReduction) {

	Armor* newItem = new Armor(name, cost, minLevel, dmgReduction);
	Armors.push_front(newItem);

}

void Market::AddPotion(string name, string type, int minLevel, int cost, int buff) {

	Potion* newItem = new Potion(name,type, cost, minLevel, buff);
	Potions.push_front(newItem);

}

void Market::AddIceSpell(string name, int cost, int minLevel, int damage, int MagicPower, int dmgReduction) {

    IceSpell* newItem = new IceSpell(name,cost,minLevel, damage, MagicPower, dmgReduction);
    Spells.push_front(newItem);
}

void Market::AddFireSpell(string name, int cost, int minLevel, int damage, int MagicPower, int armorReduction) {

    FireSpell* newItem = new FireSpell(name, cost, minLevel, damage, MagicPower, armorReduction);
    Spells.push_front(newItem);
}

void Market::AddLightingSpell(string name, int cost, int minLevel, int damage, int MagicPower, int dodgeReduction) {

    LightingSpell* newItem = new LightingSpell(name, cost, minLevel, damage, MagicPower, dodgeReduction);
    Spells.push_front(newItem);

}

void Market::displayItems() {

	list<Weapon*> ::iterator it;
	cout << "WEAPONS \n" << endl;

	for (it = Weapons.begin(); it !=  Weapons.end(); ++it) {
		cout << (*it)->get_name() << " " << (*it)->get_price() << " " << (*it)->get_minlvl() << " " << (*it)->get_damage() << " " << (*it)->get_handsNeeded() << endl;
	}

	list<Armor*> ::iterator ia;
	cout << "ARMORS \n" << endl;

	for (ia = Armors.begin(); ia != Armors.end(); ++ia) {
		cout << (*ia)->get_name() << " " << (*ia)->get_price() << " " << (*ia)->get_minlvl() << " " << (*ia)->get_protection() << endl;
	}

	list<Potion*> ::iterator ip;
	cout << "POTIONS \n" << endl;

	for (ip = Potions.begin(); ip != Potions.end(); ++ip) {
		cout << (*ip)->get_name() << " " << (*ip)->get_price() << " " << (*ip)->get_minlvl() << " " << (*ip)->get_buff() << endl;
	}

	list<Spell*> :: iterator sp;
	cout << "SPELLS \n" << endl;

	for(sp = Spells.begin(); sp != Spells.end(); ++sp){
		cout << (*sp)->get_name() << " " << (*sp)->get_price()<< " " << (*sp)->get_minlvl() << " " << (*sp)->get_DmgRange() << " " << (*sp)->get_MagicPower()
			<< " " << (*sp)->get_Reduction() <<  endl;
	}
}


void Market::EnterMarket(){

	cout << "Welcome to the Market" << endl << "Press 1 to buy,2 to sell and any button to leave" << endl;
	string flag;
	cin >> flag;
	if(flag == "1"){
		buy();
	}else if(flag == "2"){
		sell();
	}
}


void Market::buy(){

	cout << "Which hero is buying?Type their name" << endl;
	string hero_name;
	Hero* h;
	list<Hero*> :: iterator hr;
	list <Hero*> hrList;
	list<Weapon*> ::iterator it;
	int flag = 0;

	int heroFlag = 0;													//check if the hero name exists
	while(heroFlag == 0){
		cin >> hero_name;
		hrList = team->get_HeroList();
		for(hr = hrList.begin(); hr != hrList.end(); ++hr){
			if((*hr)->get_name() == hero_name){
				h = *hr;
				heroFlag = 1;
				break;
			}
		}
		if(heroFlag == 0){
			cout << "I could not find that name. Try again" << endl;
			cin >> hero_name;
		}
	}

	cout << "What item do you want to buy? Press 1 for Weapon,2 for Armor,3 for Potion,4 for Spell" << endl;
	string answer;
	cin >> answer;
	while(answer != "1" && answer!= "2" && answer!="3" && answer!="4" ){
		cout <<"Wrong input,try again" << endl;
		cin >> answer;
	}
	displayItems();

	if(answer == "1"){

		cout << "Type the name of the weapon you want to buy" << endl;
		string weapon_name;
		cin >> weapon_name;
		
		while(flag == 0){
			for (it = Weapons.begin(); it !=  Weapons.end(); ++it){
				if(weapon_name == (*it)->get_name()){
					flag = 1;
					h->buy_Weapon(*it);
					cout << h->GetWeaponsListSize() << endl;
				}
			}
			if(flag==0){
				cout <<"Weapon doesnt exist.Try again" << endl;
				cin >> weapon_name;
			}	
		}

	}else if(answer == "2"){

		cout << "Type the name of the armor you want to buy" << endl;
		string armor_name;
		cin >> armor_name;
		list<Armor*> :: iterator ar;
		flag = 0;

		while(flag == 0){
			for(ar = Armors.begin(); ar != Armors.end(); ++ar){
				if(armor_name == (*ar)->get_name()){
					flag = 1;
					h->buy_Armor(*ar);
				}
			}
			if(flag==0){
				cout <<"Armor doesnt exist.Try again" << endl;
				cin >> armor_name;
			}
		}

	}else if(answer == "3"){

		cout << "Type the name of the potion you want to buy" << endl;
		string potion_name;
		cin >> potion_name;
		list<Potion*> :: iterator pt;
		flag = 0;

		while(flag == 0){
			for(pt = Potions.begin(); pt != Potions.end(); ++pt){
				if(potion_name == (*pt)->get_name()){
					flag = 1;
					h->buy_Potion(*pt);
				}
			}
			if(flag==0){
				cout <<"Potion doesnt exist.Try again" << endl;
				cin >> potion_name;
			}
		}

	}else if(answer == "4"){

		cout << "Type the name of the ice spell you want to buy" << endl;
		string spell_name;
		cin >> spell_name;
		list<Spell*> :: iterator is;
		flag = 0;

		while( flag == 0){
			for(is = Spells.begin(); is!= Spells.end(); ++is){
				if(spell_name == (*is)->get_name()){
					flag = 1;
					h->buy_Spell(*is);
				}
			}
			if(flag == 0){
				cout <<"Spell doesnt exist.Try again" << endl;
				cin >> spell_name;
			}
		}
	}
}

void Market::sell(){

	cout << "Which hero is selling?Type their name" << endl;
	string hero_name;
	Hero* h;
	list<Hero*> :: iterator hr;
	list<Hero*> hrList;
	int flag = 0;

	int heroFlag = 0;													//check if the hero name exists
	while(heroFlag == 0){
		cin >> hero_name;
		hrList = team->get_HeroList();
		for(hr = hrList.begin(); hr != hrList.end(); ++hr){
			if((*hr)->get_name() == hero_name){
				h = *hr;
				heroFlag = 1;
				break;
			}
		}
		if(heroFlag == 0){
			cout << "I could not find that name. Try again" << endl;
			cin >> hero_name;
		}
	}
	
	cout << "What item do you want to sell? Press 1 for Weapon,2 for Armor,3 for Potion,4 for IceSpell,5 for FireSpell and 6 for LightingSpell" << endl;
	string answer;
	cin >> answer;
	while(answer != "1" && answer!= "2" && answer!="3" && answer!="4" ){
		cout <<"Wrong input,try again" << endl;
		cin >> answer;
	}

	if(answer == "1"){

		cout << "Type the name of the weapon you want to sell" << endl;
		string weapon_name;
		cin >> weapon_name;
		list<Weapon*> ::iterator it;
		flag = 0;

		while(flag == 0){

			for (it = Weapons.begin(); it !=  Weapons.end(); ++it){

				if(weapon_name == (*it)->get_name()){
					flag = 1;
					h->sell_Weapon(*it);
				}	
			}
			if(flag == 0){
				cout <<"Weapon doesnt exist.Try again" << endl;
				cin >> weapon_name;
			}
		}

	}else if (answer == "2") {

		cout << "Type the name of the armor you want to sell" << endl;
		string armor_name;
		cin >> armor_name;
		list<Armor*> :: iterator ar;
		flag = 0;

		while(flag ==0){

			for (ar = Armors.begin(); ar !=  Armors.end(); ++ar){
	
				if(armor_name == (*ar)->get_name()){
					flag = 1;
					h->sell_Armor(*ar);
				}
			}

			if(flag == 0){
				cout <<"Armor doesnt exist.Try again" << endl;
				cin >> armor_name;
			}
		}	

	}else if(answer == "3"){

		cout << "Type the name of the potion you want to sell" << endl;
		string potion_name;
		cin >> potion_name;
		list<Potion*> :: iterator pt;
		flag =0;

		while(flag == 0){
			for (pt = Potions.begin(); pt !=  Potions.end(); ++pt){
	
				if(potion_name == (*pt)->get_name()){
					flag = 1;
					h->sell_Potion(*pt);
				}
			}
			if(flag == 0){
				cout <<"Potion doesnt exist.Try again" << endl;
				cin >> potion_name;
			}
		}

	}else if(answer == "4"){

		cout << "Type the name of the spell you want to sell" << endl;
		string spell_name;
		cin >> spell_name;
		list<Spell*> :: iterator sp;

		while(flag == 0){

			for(sp = Spells.begin(); sp!= Spells.end(); ++sp){

				if(spell_name == (*sp)->get_name()){
					flag = 1;
					h->sell_Spell(*sp);
				}
			}
			if(flag ==0 ){
				cout <<"Spell doesnt exist.Try again" << endl;
				cin >> spell_name;
			}

		}
	}
}