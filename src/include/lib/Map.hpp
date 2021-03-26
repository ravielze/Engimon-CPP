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
    vector<vector<Engimon>> storageWildEngimon;
    int sizeMap;
    Player player;
    pair<int, int> playerLocation;
    pair<int, int> engimonLocation;

    void generateTerrain();
    void generateEngimon();
    void moveWildEngimon();
    void spawnPlayer();
    bool isObstruct(int, int);

    Entity getEntity(int, int);

    void modifyTerrain(int, int, MapTerrain);
    void modifyEntity(int, int, Entity);
    bool isValidCoordinate(int, int);
    bool canWildEngimonWalk(int, int, Entity);

public:
    Map();
    void show() const;
    void movePlayer(Direction);
    Player getPlayer();
    map<pair<int, int>, Engimon> getSurroundingEngimon(int, int);

    pair<int, int> getPlayerLocation();
};

#endif