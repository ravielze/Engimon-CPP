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
    Direction facing;

public:
    Player();
    void addEngimon(Engimon);
    void removeEngimon(Engimon);
    void battle(Engimon, Engimon);
    void switchActiveEngimon(Engimon);
    void interact();
    void setDirection(Direction);
    Direction getDirection() const;
};

#endif