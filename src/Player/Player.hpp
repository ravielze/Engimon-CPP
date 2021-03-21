#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <stdlib.h>
#include <iostream>
#include "../Inventory/Inventory.hpp"
#include "../Engimon/Engimon.hpp"
#include "../SkillItem/SkillItem.hpp"
#include "../constant/Direction.hpp"
#include "../constant/Exception.hpp"
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