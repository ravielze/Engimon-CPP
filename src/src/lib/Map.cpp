#include "lib/Map.hpp"

void Map::generateTerrain()
{
}

void Map::generateEngimon()
{
}

bool Map::isObstruct(int x, int y)
{
    //Kondisi nabrak batas map
    if (x >= this->sizeMap || y >= this->sizeMap || x < 0 || y < 0)
    {
        return true;
    }
    return this->storageEntity[y][x] != Entity::NONE;
}

Map::Map()
{
    this->sizeMap = 12;
    this->storageEntity = vector<vector<Entity>>(this->sizeMap, vector<Entity>(this->sizeMap, Entity::NONE));
    this->storageTerrain = vector<vector<MapTerrain>>(this->sizeMap, vector<MapTerrain>(this->sizeMap, MapTerrain::GL));
    this->playerLocation = pair<int, int>(0, 0);
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
    // this->engimonLocation.first = this->playerLocation.first;
    // this->engimonLocation.second = this->playerLocation.second;
    pair<int, int> tempLocation;
    tempLocation.first = this->playerLocation.first;
    tempLocation.second = this->playerLocation.second;
    int x = this->playerLocation.first;
    int y = this->playerLocation.second;
    switch (direct)
    {
    case Direction::NORTH:
        if (isObstruct(x, y - 1))
        {
            return;
        }
        if (this->storageEntity[this->playerLocation.first][this->playerLocation.second + 1] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first, this->playerLocation.second + 1);
        }

    case Direction::WEST:
        if (isObstruct(x + 1, y))
        {
            return;
        }
        if (this->storageEntity[this->playerLocation.first - 1][this->playerLocation.second] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first - 1, this->playerLocation.second);
        }

    case Direction::EAST:
        if (isObstruct(x - 1, y))
        {
            return;
        }
        if (this->storageEntity[this->playerLocation.first + 1][this->playerLocation.second] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first + 1, this->playerLocation.second);
        }

    case Direction::SOUTH:
        if (isObstruct(x, y + 1))
        {
            return;
        }
        if (this->storageEntity[this->playerLocation.first][this->playerLocation.second - 1] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(this->playerLocation.first, this->playerLocation.second - 1);
        }
    }
    this->engimonLocation.first = tempLocation.first;
    this->engimonLocation.second = tempLocation.second;

    // Engimon juga move
    moveWildEngimon();

    // Kalau wild engimon nabrak player, wild engimon aja yang direposisi
}

void Map::moveWildEngimon()
{
    srand(time(0));
    // Looping untuk semua wild engimon
    int x = 0, y = 0;
    for (x = 0; x < this->storageEntity[0].size(); x++)
    {
        for (y = 0; y < this->storageEntity.size(); y++)
        {
            Entity ent = this->storageEntity[y][x];
            pair<int, int> position = pair<int, int>(x, y);

            int moveCommand = rand() % 4;

            switch (moveCommand)
            {
            // Bergerak ke north
            case (0):
                if (!isObstruct(x, y - 1))
                {
                    this->storageEntity[y][x] = Entity::NONE;
                    this->storageEntity[y - 1][x] = ent;
                    break;
                }

            // Bergerak ke west
            case (1):
                if (!isObstruct(x + 1, y))
                {
                    this->storageEntity[y][x] = Entity::NONE;
                    this->storageEntity[y][x + 1] = ent;
                    break;
                }

            // Bergerak ke east
            case (2):
                if (!isObstruct(x - 1, y))
                {
                    this->storageEntity[y][x] = Entity::NONE;
                    this->storageEntity[y][x - 1] = ent;
                    break;
                }

            // Bergerak ke south
            case (3):
                if (!isObstruct(x, y + 1))
                {
                    this->storageEntity[y][x] = Entity::NONE;
                    this->storageEntity[y + 1][x] = ent;
                    break;
                }
            }
        }
    }
}