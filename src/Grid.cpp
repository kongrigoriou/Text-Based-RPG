#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iterator>

#include "../include/Grid.h"

using namespace std;

//A few details...
//0: Non accessible
//1: common
//2: Market

Grid::Grid(Market* m, Squad* sq){
    market = m;
    team = sq;

    Map = new int*[HEIGHT];                 //creating the map

    for(int i = 0; i < HEIGHT; i++){
        Map[i] = new int [WIDTH];
    }
    srand(time(NULL));

    for(int x = 0; x < HEIGHT; x++){
        for(int y = 0; y < WIDTH; y++){
            int p;                          //possibility
            p = rand()%100;

            if(p <= 15 ){
                Map[x][y] = 0;
            }else if(p <= 35){
                Map[x][y] = 2;
            }else{
                Map[x][y] = 1;
            }
        }
    }
    x = 0;
    y= 0;
    Map[0][0] = 1;
    pt = 1;
}

void Grid::move_up(){

    if(y -1 < 0){
        cout << "You can not move upwards" << endl;
    }else{
        if(Map[y-1][x] == 0){
            cout << "This is a non accessible square" << endl;
            return;            
        }
        py = y;
        px = x;
        Map[py][px] = pt;
        y--;
        pt = Map[y][x];
        Map[y][x] = 3;

    }
}

void Grid::move_down(){
    cout << y << endl;
    if(y + 1 > HEIGHT-1){
        cout << "You can not move down" << endl;
    }else{
        if(Map[y+1][x] == 0){
            cout << "This is a non accessible square" << endl;
            return;            
        }
        py = y;
        px = x;
        Map[py][px] = pt;
        y++;
        pt = Map[y][x];
        Map[y][x] = 3;
        
    }
}

void Grid::move_left(){
    if(x - 1 < 0){
        cout << "You can not move to the left" << endl;
    }else{
        if(Map[y][x-1] == 0){
            cout << "This is a non accessible square" << endl;
            return;
        }
        py = y;
        px = x;
        Map[py][px] = pt;
        x--;
        pt = Map[y][x];
        Map[y][x] = 3;

    }
}

void Grid::move_right(){
    if(x + 1 > WIDTH){
        cout << "You can not move to the right" << endl;
    }else{
        if(Map[y][x+1] == 0){
            cout << "This is a non accessible square" << endl;
            return;            
        }
        py = y;
        px = x;
        Map[py][px] = pt;
        x++;
        pt = Map[y][x];
        Map[y][x] = 3;

    }
}

void Grid::insert_Dragon(string n, int hp, int dmg, int def, int ag, int l){
    Dragon* newMonster = new Dragon(n, hp, dmg, def, ag, l);
    Dragons.push_front(newMonster);
}

void Grid::insert_Exoskeleton(string n, int hp, int dmg, int def, int ag, int l){
    Exoskeleton* newMonster = new Exoskeleton(n, hp, dmg, def, ag, l);
    Dragons.push_front(newMonster);
}


void Grid::insert_Spirit(string n, int hp, int dmg, int def, int ag, int l){
    Spirit* newMonster = new Spirit(n, hp, dmg, def, ag, l);
    Dragons.push_front(newMonster);
}


void Grid::insert_Monster(Monster* m){
    Monsters.push_front(m);
}

void Grid::display_generalinfo(){
    cout << "You have entered the world of Hallownest!" << endl;
    cout << "Use w a s d to move around the map." << endl;
    cout << "To quit the game press q" << endl;
}

void Grid::get_monsters(int lvl){
    int maxlvl = 0;
    list <Monster*>::iterator it, it2, it3;
    for(it = Dragons.begin(); it != Dragons.end(); ++it){
        int mlvl = (*it)->get_level();
        if(mlvl > maxlvl){
            Monsters.push_back(*it);
        }
        if(mlvl == lvl || mlvl == lvl - 1 || mlvl == lvl + 1){
            insert_Monster(*it);
        }
    }

    for(it2 = Exoskeletons.begin(); it2 != Exoskeletons.end(); ++it2){
        int mlvl = (*it2)->get_level();
        if(mlvl == lvl || mlvl == lvl - 1 || mlvl == lvl + 1){
            insert_Monster(*it2);
        }
    }

       for(it3 = Spirits.begin(); it3 != Spirits.end(); ++it3){
        int mlvl = (*it3)->get_level();
        if(mlvl == lvl || mlvl == lvl - 1 || mlvl == lvl + 1){
            insert_Monster(*it3);
        }
    }

    if(Monsters.size() > 3)
        while(Monsters.size() > 3)
            Monsters.pop_back();
    else if(Monsters.size() == 0)
        cout << "Could not find monsters" << endl;

}

int Grid::monsters_fainted(){
    list<Monster*>::iterator it;
    int count = 0;
    for(it = Monsters.begin(); it != Monsters.end(); ++it){
        if((*it)->get_HealthPower() <= 0){
            count++;
        }
    }

    if(count == Monsters.size()){
        return 1;
    }else{
        return 0;
    }  
        
}

Squad* Grid::get_squad(){
    return team;
}

void Grid::display_Map(){
    for(int k = 0; k < HEIGHT; k++){
        for(int l = 0; l < WIDTH; l++){
            cout << Map[k][l] << "  ";
        }

        cout << endl;
    }
}

void Grid::enter_battle(){

    int BattleFlag = 0;
    string input;
    list <Monster*>::iterator mit;

    while(BattleFlag == 0){
        cout << "You are about to fight with monsters" << endl;
        cout << "Choose your next move!" << endl;
        cout << "1: display your teams' stats \n"
            << "2: display monsters stats \n" 
            << "3: to start the battle " << endl;
        
        cin >> input;

        if(input == "1"){
            team->display_myHeroes();
        }else if(input == "2"){
            for(mit = Monsters.begin(); mit != Monsters.end(); ++mit){
                (*mit)->display_stats();
            }
        }else if(input == "3"){
            BattleFlag = battle();
            BattleFlag = 1;
        }else{
            cout << "Wrong input. Try again" << endl;
        }
    }

}

int Grid::battle(){
    int rounds = 1;
    int battleflag = 0;
    list <Hero*>::iterator it;
    list <Monster *>::iterator mit;
    list <Hero*> hr;
    string input;
    cout << "ROUND " << rounds << endl;
    cout << "Choose an action for each hero" << endl;

    while(battleflag == 0){
        hr = team->get_HeroList();
        for(it = hr.begin(); it != hr.end(); ++it){
            cout << (*it)->get_name() << "'s turn" << endl;
            cout << "attack/spell/potion/equip" << endl;
            for(mit = Monsters.begin(); mit != Monsters.end(); ++mit){
                if((*mit)->get_HealthPower() > 0)
                    break;
            }
            
            cin >> input;
            if(input == "equip"){
                cout << "Do you want to equip a Weapon or an Armor? \n"
                        << "Reply with weapon/armor" << endl;
                cin >> input;

                if(input == "weapon"){
                    cout << "Type the name of the weapon you want to equip\n"
                        << "To display the available weapons type 'display' " << endl;
                    cin >> input;
                    int flag = 0;
                    while(flag == 0){
                        if(input == "display"){
                            (*it)->display_Weapons();
                        }else{
                            (*it)->equip_weapon(input);
                            flag = 1;
                        }
                        cin >> input;
                    }

                }else if(input == "armor"){
                    cout << "Type the name of the armor you want to equip\n"
                        << "To display the available armors type 'display' " << endl;
                    cin >> input;
                    int flag = 0;
                    while(flag == 0){
                        if(input == "display"){
                            (*it)->display_Armors();
                        }else{
                            (*it)->equip_armor(input);
                            flag = 1;
                        }
                        cin >> input;
                    }
                }
            }else if(input == "potion"){
                cout << "Type the name of the potion you want to use" << endl;
                cout << "To display the available Potions type 'display'" << endl;
                cin >> input;
                int flag = 0;
                while(flag < 2){
                    if(input == "display"){
                        (*it)->display_Potions();
                        flag++;
                    }else{
                        (*it)->usePotion(input);
                        flag++;
                    }
                    // cin >> input;
                    flag++;
                }
            }else if(input == "attack"){
                (*it)->attack(*mit);
                (*mit)->attack(*it);
            }
        }
        if(team->all_fainted() == 1 || monsters_fainted() == 1){
            battleflag = 1;
            if(team->all_fainted() == 1){
                cout << "Your team lost :(" << endl;
                for(it = hr.begin(); it != hr.end(); ++it){
                   (*it)->hp_tohalf();
                   (*it)->lost_round();
                }
            }else{
                cout << "Gg your team won the monsters!" << endl;
                for(it = hr.begin(); it != hr.end(); ++it){
                   (*it)->hp_tohalf();
                   (*it)->round_won();
                }
            }
        }
    }
}


void Grid::gameplay(){
    cout << "Welcome to our game!" << endl;
    cout << "Choose heroes for your team! You can pick up to 3 heroes" << endl;

    int flag = 0;
    int BattleFlag = 0;
    int possibility;
    string input;
    while(flag == 0){
        cout << "1: to check the available heroes" << "\n" 
        << "2: if you are ready!" << "\n"
        << "if you have dicided the hero you want just write their name and he/she will be added to your squad!" << endl;
        
        cout << "3: to display your team" << endl;
        cin >> input;
        if(input == "1")
            team->display_allHeroes();
        else if(input == "3")
            team->display_myHeroes();
        else if (input == "2"){
            if(team->get_count() == 0){
                cout << "Your team is empty! You are not ready yet." << endl;
            }else{
                flag = 1;
            }
        }else if(team->search_Hero(input)){
            if(team->get_count() < 3){
                team->select_hero(input);
            }else{
                flag = 1;
            }
        }else{
            cout << "Wrong input. Try again" << endl;
        }
    }

    Map[x][y] = 3;
    display_Map();

    cout << "When you are in a common/market square you can use these commands: \n"
        << "stats: to check a hero's stats\n"
        << "inv: to ckeck a hero's inventory\n"
        << "equip: to equip a Weapon/Armor\n"
        << "use: to use a potion" << endl; 

    int play = 0;
    int monsterlvl = 0;
    list <Hero*> temp;

    display_generalinfo();
    while(play == 0){
        list <Hero*>::iterator it;
        list <Monster*>::iterator mit;
        Hero* he;
        cin >> input;
        if(input == "q" || input == "Q"){
            play = 1;
        }else {
            if(input == "W" || input == "w"){
                move_up();
                BattleFlag = 1;
            }else if(input == "A" || input == "a"){
                move_left();
                BattleFlag = 1;
            }else if(input == "S" || input == "s"){
                move_down();
                BattleFlag = 1;
            }else if(input == "D" || input == "d"){
                move_right();
                BattleFlag = 1;
            }else if(input == "stats"){
                cout << "Whose stats do you want to display?\n"
                    << "Enter the hero's name" << endl;
                cin >> input;
                he = team->search_Hero(input);
                while(he == NULL){
                    cin >> input;
                    he = team->search_Hero(input);
                }
                he->display_stats();
            }else if(input == "inv"){
                cout << "Whose inventory do you want  to display? \n"
                    << "Enter the hero's name" << endl;
                cin >> input;
                he = team->search_Hero(input);
                while(he == NULL){
                    cin >> input;
                    he = team->search_Hero(input);
                }
                he->display_inventory();
            }else if(input == "equip"){
                cout << "Do you want to equip a Weapon or an Armor? \n"
                    << "Reply with weapon/armor" << endl;
                cin >> input;

                if(input == "weapon"){
                    cout << "Type the name of the weapon you want to equip\n"
                        << "To display the available weapons type 'display' " << endl;
                    cin >> input;
                    if(input == "display"){
                        he->display_Weapons();
                    }else{
                        he->equip_weapon(input);
                    }
                }else if(input == "armor"){
                    cout << "Type the name of the armor you want to equip\n"
                        << "To display the available armors type 'display' " << endl;
                    cin >> input;
                    if(input == "display"){
                        he->display_Armors();
                    }else{
                        he->equip_armor(input);
                    }
                }
            }else if(input == "use"){
                cout << "Type the name of the potion you want to use\n"
                    << "To display the available potions type 'display'" << endl;
                cin >> input;
                if(input == "display"){
                    he->display_Potions();
                }else{
                    he->usePotion(input);
                }
            }
            display_Map();
        }

        possibility = rand()%100;

        if(possibility < 20 && pt == 1 && BattleFlag == 1 && input != "use" && input != "stats" && input != "equip" && input != "inv"){

            cout << "Possibility: "<< possibility << endl;
            temp = team->get_HeroList();
            for(it = temp.begin(); it != temp.end(); ++it){
                monsterlvl += (*it)->get_level();
                cout << (*it)->get_name() << endl;
            }
            monsterlvl = monsterlvl/3;
            get_monsters(monsterlvl);

            this->enter_battle();

        }else if(pt == 2){
            cout << "There's a Market near you, would you like to visit?" << endl;
            cout << "Reply with yes/no" << endl;
            int flag = 0;
            cin >> input;
            while(flag == 0){
                if(input == "yes"){            
                while (flag == 0){
                
                    market->EnterMarket();
                    cout << "Woould you like to leave the Market?" << endl;
                    cin >> input;
                    if(input == "yes")
                        flag = 1;
                }
                }else if (input == "no"){
                    flag = 1;
                }else{
                    cout << "Wrong input try again" << endl;
                    cin >> input;
                }
            }
            display_Map();
        }
    }
}

Grid::~Grid(){
    Dragons.clear();
    Exoskeletons.clear();
    Spirits.clear();
    Monsters.clear();
}