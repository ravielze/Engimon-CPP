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

enum class MapTerrain
{

    GL, // Grassland
    o   // Sea
};

string mapLegend(Entity e, MapTerrain t)
{
    switch (e)
    {
    case Entity::W:
        return "W";
    case Entity::w:
        return "w";
    case Entity::I:
        return "I";
    case Entity::i:
        return "i";
    case Entity::F:
        return "F";
    case Entity::f:
        return "f";
    case Entity::G:
        return "G";
    case Entity::g:
        return "g";
    case Entity::E:
        return "E";
    case Entity::e:
        return "e";
    case Entity::L:
        return "L";
    case Entity::l:
        return "l";
    case Entity::S:
        return "S";
    case Entity::s:
        return "s";
    case Entity::N:
        return "N";
    case Entity::n:
        return "n";
    case Entity::P:
        return "P";
    case Entity::X:
        return "X";
    case Entity::T:
        return "T";
    case Entity::R:
        return "R";
    default:
        break;
    }
    switch (t)
    {
    case MapTerrain::GL:
        return "-";
    case MapTerrain::o:
        return "o";
    }
    return "?";
}
#endif // __MAPENTITY_H__