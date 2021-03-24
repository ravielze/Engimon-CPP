#ifndef __MAP_H__
#define __MAP_H__
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include "lib/constant/MapEntity.hpp"
#include "lib/constant/Direction.hpp"
#include "lib/Engimon.hpp"
#include "lib/Player.hpp"
#include "utils.hpp"
#include <unistd.h>
using namespace std;

class Map
{
private:
    vector<vector<MapTerrain>> storageTerrain;
    vector<vector<Entity>> storageEntity;
    int sizeMap;
    Player player;
    pair<int, int> playerLocation;
    pair<int, int> engimonLocation;
    map<Entity, Engimon> wildEngimonData;

    void generateTerrain();
    void generateEngimon();
    void moveWildEngimon();
    bool isObstruct(int, int);

    vector<Engimon> getSurroundingEngimon(int, int);
    Entity getEntity(int, int);

public:
    Map();
    void show() const;
    void movePlayer(Direction);
};

#endif