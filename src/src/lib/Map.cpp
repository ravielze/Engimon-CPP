#include "lib/Map.hpp"

void Map::generateTerrain()
{
}

void Map::generateEngimon()
{
}

void Map::isObstruct(int, int)
{
}

Map::Map()
{
    this->sizeMap = 12;
    this->storageEntity = vector<vector<Entity>>(this->sizeMap, vector<Entity>(this->sizeMap, Entity::NONE));
    this->storageTerrain = vector<vector<MapTerrain>>(this->sizeMap, vector<MapTerrain>(this->sizeMap, MapTerrain::GL));
}

void Map::show() const
{
    for (int i = 0; i < this->sizeMap; i++)
    {
        for (int j = 0; j < this->sizeMap; j++)
        {
            cout << mapLegend(this->storageEntity[i][j], this->storageTerrain[i][j]);
        }
        cout << endl;
    }
}

void Map::movePlayer(Direction direct)
{
    switch (direct)
    {
    case Direction::NORTH:
        if (this->storageEntity[this->playerLocation.first][this->playerLocation.second + 1] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first, this->playerLocation.second + 1);
        }
    case Direction::WEST:
        if (this->storageEntity[this->playerLocation.first - 1][this->playerLocation.second] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first - 1, this->playerLocation.second);
        }

    case Direction::EAST:
        if (this->storageEntity[this->playerLocation.first + 1][this->playerLocation.second] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first + 1, this->playerLocation.second);
        }

    case Direction::SOUTH:
        if (this->storageEntity[this->playerLocation.first][this->playerLocation.second - 1] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first, this->playerLocation.second - 1);
        }
    }
}