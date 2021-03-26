#include "lib/Map.hpp"
#define VEIN_CHANCE 65
#define ENGIMON_MOVE_1_PER_CHANCE 3
#define TREE_CHANCE 10
#define VEIN_TREE_CHANCE 32
#define ROCK_CHANCE 9
#define TREE_LIMIT 110

Player Map::getPlayer()
{
    return this->player;
}

bool Map::isValidCoordinate(int x, int y)
{
    return (x >= 0 && x < this->sizeMap && y >= 0 && y < this->sizeMap);
}

void Map::modifyTerrain(int x, int y, MapTerrain t)
{
    if (!isValidCoordinate(x, y))
    {
        return;
    }

    this->storageTerrain[y][x] = t;
}

void Map::modifyEntity(int x, int y, Entity e)
{
    if (!isValidCoordinate(x, y))
    {
        return;
    }
    if (e == Entity::T && this->storageTerrain[y][x] != MapTerrain::GL)
    {
        return;
    }
    if (e == Entity::R && this->storageTerrain[y][x] != MapTerrain::o)
    {
        return;
    }

    this->storageEntity[y][x] = e;
}

void Map::generateTerrain()
{
    srand(time(NULL) % getpid());
    int waterVein = randomInt(5, 10);
    int waterPond = randomInt(4, 8);
    for (int i = 0; i < waterPond; i++)
    {
        int centerX = randomInt(0, this->sizeMap - 1);
        int centerY = randomInt(0, this->sizeMap - 1);
        int currentWaterVein = waterVein;
        while (currentWaterVein > 0)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (chancePercent(VEIN_CHANCE))
                {
                    modifyTerrain(centerX, centerY + j, MapTerrain::o);
                    if (chancePercent(ROCK_CHANCE))
                    {
                        modifyEntity(centerX, centerY, Entity::R);
                    }
                }
            }
            for (int j = -1; j <= 1; j++)
            {
                if (chancePercent(VEIN_CHANCE))
                {
                    modifyTerrain(centerY + j, centerX, MapTerrain::o);
                    if (chancePercent(ROCK_CHANCE))
                    {
                        modifyEntity(centerX, centerY, Entity::R);
                    }
                }
            }
            modifyTerrain(centerY, centerX, MapTerrain::o);
            int dCenterX = randomInt(-1, 1);
            int dCenterY = randomInt(-1, 1);
            while (!(isValidCoordinate(centerX + dCenterX, centerY + dCenterY)))
            {
                dCenterY = randomInt(-1, 1);
                dCenterX = randomInt(-1, 1);
            }
            centerX += dCenterX;
            centerY += dCenterY;
            currentWaterVein--;
        }
    }

    int treeLimit = TREE_LIMIT;
    for (int i = 0; i < this->sizeMap; i++)
    {
        if (treeLimit <= 0)
        {
            break;
        }
        for (int j = 0; j < this->sizeMap; j++)
        {
            if (treeLimit <= 0)
            {
                break;
            }
            if (this->storageTerrain[j][i] == MapTerrain::GL)
            {
                if (chancePercent(TREE_CHANCE))
                {
                    int treeVein = randomInt(1, 3); //3 to 5
                    int treeCenterX = i;
                    int treeCenterY = j;
                    while (treeVein > 0)
                    {
                        for (int k = -1; k <= 1; k++)
                        {
                            if (chancePercent(VEIN_TREE_CHANCE))
                            {
                                modifyEntity(treeCenterX, treeCenterY + k, Entity::T);
                                treeLimit--;
                            }
                        }
                        for (int k = -1; k <= 1; k++)
                        {
                            if (chancePercent(VEIN_TREE_CHANCE))
                            {
                                modifyEntity(treeCenterX + k, treeCenterY, Entity::T);
                                treeLimit--;
                            }
                        }
                        modifyEntity(treeCenterY, treeCenterX, Entity::T);
                        int dCenterX = randomInt(-1, 1);
                        int dCenterY = randomInt(-1, 1);
                        while (!(isValidCoordinate(treeCenterX + dCenterX, treeCenterY + dCenterY)))
                        {
                            dCenterY = randomInt(-1, 1);
                            dCenterX = randomInt(-1, 1);
                        }
                        treeCenterX += dCenterX;
                        treeCenterY += dCenterY;
                        treeVein--;
                    }
                }
            }
        }
    }
}

void Map::generateEngimon()
{
    srand(time(NULL) % getpid());
    int amountsmallEngimon = randomInt(3, 10); //3 sampai 10
    int amountbigEngimon = randomInt(2, 5);    //2 sampai 5
    vector<Entity> entities(amountsmallEngimon + amountbigEngimon);
    vector<Engimon> engimon(amountsmallEngimon + amountbigEngimon);
    for (int i = 0; i < amountsmallEngimon; i++)
    {
        int randomSmall = (randomInt(0, 7) * 2) + 1;
        Entity currentEntity = static_cast<Entity>(randomSmall);
        entities.push_back(currentEntity);
        switch (currentEntity)
        {
        }
    }
}

void Map::spawnPlayer()
{
    int x, y;
    for (x = 0; x < this->sizeMap - 1; x++)
    {
        for (y = this->sizeMap - 1; y > 0; y--)
        {
            if ((this->storageTerrain[y][x] == MapTerrain::GL && !isObstruct(x, y)))
            {
                break;
            }
        }
    }
    this->storageEntity[y][x] = Entity::P;
    this->playerLocation.first = x;
    this->playerLocation.second = y;
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
    this->sizeMap = 20;
    this->storageEntity = vector<vector<Entity>>(this->sizeMap, vector<Entity>(this->sizeMap, Entity::NONE));
    this->storageTerrain = vector<vector<MapTerrain>>(this->sizeMap, vector<MapTerrain>(this->sizeMap, MapTerrain::GL));
    this->storageWildEngimon = vector<vector<Engimon>>(this->sizeMap, vector<Engimon>(this->sizeMap, Engimon()));
    this->playerLocation = pair<int, int>(-1, -1);
    this->engimonLocation = pair<int, int>(-1, -1);
    this->generateTerrain();
    this->generateEngimon();
    this->spawnPlayer();
    this->canWildEngimonWalk(0, 0, Entity::W);
    this->canWildEngimonWalk(0, 0, Entity::G);
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
    int x = this->playerLocation.first;
    int y = this->playerLocation.second;
    switch (direct)
    {
    case Direction::NORTH:
        if (isObstruct(x, y - 1))
        {
            return;
        }
        if (this->storageEntity[x][y + 1] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(x, y + 1);
            this->storageEntity[y][x] = Entity::NONE;
            this->storageEntity[y + 1][x] = Entity::P;
        }

    case Direction::WEST:
        if (isObstruct(x + 1, y))
        {
            return;
        }
        if (this->storageEntity[x - 1][y] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(x - 1, y);
            this->storageEntity[y][x] = Entity::NONE;
            this->storageEntity[y][x - 1] = Entity::P;
        }

    case Direction::EAST:
        if (isObstruct(x - 1, y))
        {
            return;
        }
        if (this->storageEntity[x + 1][y] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(x + 1, y);
            this->storageEntity[y][x] = Entity::NONE;
            this->storageEntity[y][x + 1] = Entity::P;
        }

    case Direction::SOUTH:
        if (isObstruct(x, y + 1))
        {
            return;
        }
        if (this->storageEntity[x][y - 1] == Entity::NONE)
        {
            this->playerLocation = pair<int, int>(x, y - 1);
            this->storageEntity[y][x] = Entity::NONE;
            this->storageEntity[y - 1][x] = Entity::P;
        }
    }
    this->engimonLocation.first = x;
    this->engimonLocation.second = y;
    //engimon sendiri nabrak blom dibuat

    // Engimon juga move
    moveWildEngimon();
}

bool Map::canWildEngimonWalk(int x, int y, Entity ent)
{
    if (!isValidCoordinate(x, y))
    {
        return false;
    }

    int entityID = static_cast<int>(ent);
    if (this->storageTerrain[y][x] == MapTerrain::GL)
    {
        return (entityID >= 6 && entityID <= 11);
    }
    else if (this->storageTerrain[y][x] == MapTerrain::o)
    {
        return (entityID < 6 && entityID > 11);
    }
    return true;
}

void Map::moveWildEngimon()
{
    srand(time(NULL));
    // Looping untuk semua wild engimon
    int x = 0, y = 0;
    for (x = 0; x < this->storageEntity[0].size(); x++)
    {
        for (y = 0; y < this->storageEntity.size(); y++)
        {
            Entity ent = this->storageEntity[y][x];
            Engimon engi;
            engi = this->storageWildEngimon[y][x];
            if (mapEntityType(ent) == EntityType::WILD_ENGIMON)
            {
                if (chanceFraction(ENGIMON_MOVE_1_PER_CHANCE))
                {
                    pair<int, int> position = pair<int, int>(x, y);

                    int moveCommand = randomInt(0, 4);

                    switch (moveCommand)
                    {
                    // Bergerak ke north
                    case (0):
                        if (!isObstruct(x, y - 1) && !canWildEngimonWalk(x, y - 1, ent))
                        {
                            this->storageEntity[y][x] = Entity::NONE;
                            this->storageEntity[y - 1][x] = ent;
                            this->storageWildEngimon[y][x] = Engimon();
                            this->storageWildEngimon[y - 1][x] = engi;
                            break;
                        }

                    // Bergerak ke west
                    case (1):
                        if (!isObstruct(x + 1, y) && !canWildEngimonWalk(x + 1, y, ent))
                        {
                            this->storageEntity[y][x] = Entity::NONE;
                            this->storageEntity[y][x + 1] = ent;
                            this->storageWildEngimon[y][x] = Engimon();
                            this->storageWildEngimon[y][x + 1] = engi;
                            break;
                        }

                    // Bergerak ke east
                    case (2):
                        if (!isObstruct(x - 1, y) && !canWildEngimonWalk(x - 1, y, ent))
                        {
                            this->storageEntity[y][x] = Entity::NONE;
                            this->storageEntity[y][x - 1] = ent;
                            this->storageWildEngimon[y][x] = Engimon();
                            this->storageWildEngimon[y][x - 1] = engi;
                            break;
                        }

                    // Bergerak ke south
                    case (3):
                        if (!isObstruct(x, y + 1) && !canWildEngimonWalk(x, y + 1, ent))
                        {
                            this->storageEntity[y][x] = Entity::NONE;
                            this->storageEntity[y + 1][x] = ent;
                            this->storageWildEngimon[y][x] = Engimon();
                            this->storageWildEngimon[y + 1][x] = engi;
                            break;
                        }
                    }
                }
            }
        }
    }
}

map<pair<int, int>, Engimon> Map::getSurroundingEngimon(int xi, int yi)
{
    map<pair<int, int>, Engimon> surroundingEngimon;

    for (int y = yi - 1; y <= yi + 1; y++)
    {
        for (int x = xi - 1; xi <= xi + 1; x++)
        {
            if (x == xi and y == yi)
            {
                continue;
            }
            if (mapEntityType(getEntity(x, y)) == EntityType::WILD_ENGIMON)
            {
                surroundingEngimon.insert({pair<int, int>(x, y), this->storageWildEngimon[y][x]});
            }
        }
    }
    return surroundingEngimon;
}

Entity Map::getEntity(int x, int y)
{
    if (x >= this->sizeMap || y >= this->sizeMap || x < 0 || y < 0)
    {
        return Entity::NONE;
    }
    return storageEntity[y][x];
}