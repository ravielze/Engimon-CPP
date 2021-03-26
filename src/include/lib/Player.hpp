#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <stdlib.h>
#include <iostream>
#include "lib/Inventory.hpp"
#include "lib/Engimon.hpp"
#include "lib/SkillItem.hpp"
#include "lib/constant/Direction.hpp"
#include "lib/constant/Exception.hpp"
using namespace std;

class Player
{
private:
    Inventory<Engimon> engimonList;
    Inventory<SkillItem> ItemList;
    Engimon activeEngimon;

public:
    Player();
    Engimon getActiveEngimon();
    void addEngimon(Engimon);
    void removeEngimon(Engimon);
    bool battle(Engimon);
    void switchActiveEngimon();
    void interact();
    void showEngimon();
    void showSkillItem();
    void learn();
};

#endif