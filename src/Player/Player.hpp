#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <stdlib.h>
#include <iostream>
#include "../Inventory/Inventory.hpp"
#include "../Engimon/Engimon.hpp"
#include "../SkillItem/SkillItem.hpp"
using namespace std;

class Player
{
private:
    pair<int, int> playerPosition;
    Inventory<Engimon> engimonList;
    Inventory<SkillItem> ItemList;
    Engimon activeEngimon;
    pair<int, int> engimonPosition;

public:
    Player();
    void addEngimon(Engimon);
    void removeEngimon(Engimon);
    void move();
    void battle();
    void switchActiveEngimon();
    void interact();
};

#endif