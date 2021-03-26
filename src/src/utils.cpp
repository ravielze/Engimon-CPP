#include "utils.hpp"
string convertItemTypeToString(ItemType it)
{
    switch (it)
    {
    case ItemType::HM:
        return "HM";
    case ItemType::TM:
        return "TM";
    case ItemType::OTHER:
        return "Other";
    }
    return "Unknown";
}

string convertElementToString(Element e)
{
    switch (e)
    {
    case Element::ELECTRIC:
        return "Electric";
    case Element::FIRE:
        return "Fire";
    case Element::WATER:
        return "Water";
    case Element::GROUND:
        return "Ground";
    case Element::ICE:
        return "Ice";
    }
    return "Unknown";
}

string convertEntitySourceToString(EntitySource es)
{
    switch (es)
    {
    case EntitySource::BREEDING:
        return "Breeding";
    case EntitySource::WILD:
        return "Wild";
    }
    return "Unknown";
}

string mapLegend(Entity e, MapTerrain t)
{
    switch (e)
    {
    case Entity::W:
        return "W ";
    case Entity::w:
        return "w ";
    case Entity::I:
        return "I ";
    case Entity::i:
        return "i ";
    case Entity::F:
        return "F ";
    case Entity::f:
        return "f ";
    case Entity::G:
        return "G ";
    case Entity::g:
        return "g ";
    case Entity::E:
        return "E ";
    case Entity::e:
        return "e ";
    case Entity::L:
        return "L ";
    case Entity::l:
        return "l ";
    case Entity::S:
        return "S ";
    case Entity::s:
        return "s ";
    case Entity::N:
        return "N ";
    case Entity::n:
        return "n ";
    case Entity::P:
        return "P ";
    case Entity::X:
        return "X ";
    case Entity::T:
        return "\033[37mT\033[0m ";
    case Entity::R:
        return "\033[33mR\033[0m ";
    default:
        break;
    }
    switch (t)
    {
    case MapTerrain::GL:
        return "\033[1;32m-\033[0m ";
    case MapTerrain::o:
        return "\033[1;34mo\033[0m ";
    }
    return "?";
}

EntityType mapEntityType(Entity e)
{
    switch (e)
    {
    case Entity::W:
    case Entity::w:
    case Entity::I:
    case Entity::i:
    case Entity::F:
    case Entity::f:
    case Entity::G:
    case Entity::g:
    case Entity::E:
    case Entity::e:
    case Entity::L:
    case Entity::l:
    case Entity::S:
    case Entity::s:
    case Entity::N:
    case Entity::n:
        return EntityType::WILD_ENGIMON;
    case Entity::P:
        return EntityType::PLAYER;
    case Entity::X:
        return EntityType::PLAYER_ENGIMON;
    case Entity::T:
    case Entity::R:
        return EntityType::STRUCTURE;
    }
    return EntityType::NONE;
}

bool chanceFraction(int chance)
{
    int x = rand();
    int y = rand();
    int xyxor = x ^ y;
    int ch = xyxor % chance;
    return (ch == 0);
}

bool chancePercent(int chance)
{
    int x = rand();
    int y = rand();
    int xyxor = x ^ y;
    int mod = xyxor % 100;
    return (mod < chance);
}

int randomInt(int min, int max)
{
    int x = rand();
    int y = rand();
    int xyxor = x ^ y;
    int mod = max - min + 1;
    int i = (xyxor % mod) + min;
    return i;
}