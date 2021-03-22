#ifndef __GAME_H__
#define __GAME_H__
#include <stdlib.h>
#include <iostream>
#include <map>
#include "lib/Map.hpp"

using namespace std;

class Game
{
private:
    Map map;

public:
    Game();
    void startGame();
    void quitGame();
};

#endif