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
using namespace std;

class Map
{
private:
    vector<vector<MapTerrain>> storageTerrain;
    vector<vector<Entity>> storageEntity;
    map<pair<int, int>, Engimon> entityMData;
    int sizeMap;
    Player player;
    pair<int, int> playerLocation;
    pair<int, int> engimonLocation;

    void generateTerrain();
    void generateEngimon();
    void isObstruct(int, int);

public:
    Map();
    void show() const;
    void movePlayer(Direction);
};

#endif