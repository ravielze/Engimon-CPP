#ifndef __MAPENTITY_H__
#define __MAPENTITY_H__
#include <iostream>
using namespace std;

enum class Entity
{
    W,   // Large Water Engimon
    w,   // Small Water Engimon
    I,   // Large Ice Engimon
    i,   // Small Ice Engimon
    F,   // Large Fire Engimon
    f,   // Small Fire Engimon
    G,   // Large Ground Engimon
    g,   // Small Ground Engimon
    E,   // Large Electric Engimon
    e,   // Small Electric Engimon
    L,   // Large Fire,Electric Engimon
    l,   // Small Fire,Electric Engimon
    S,   // Large Water,Ice Engimon
    s,   // Small Water,Ice Engimon
    N,   // Large Water,Ground Engimon
    n,   // Small Water,Ground Engimon
    P,   // Player
    X,   // Active Engimon
    T,   // Tree
    R,   // Rock
    NONE // No Entity
};

enum class EntityType
{
    PLAYER_ENGIMON,
    WILD_ENGIMON,
    PLAYER,
    STRUCTURE,
    NONE
};

enum class MapTerrain
{

    GL, // Grassland
    o   // Sea
};

#endif // __MAPENTITY_H__