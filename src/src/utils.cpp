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
        return "\033[35mW\033[0m ";
    case Entity::w:
        return "\033[35mw\033[0m ";
    case Entity::I:
        return "\033[35mI\033[0m ";
    case Entity::i:
        return "\033[35mi\033[0m ";
    case Entity::F:
        return "\033[35mF\033[0m ";
    case Entity::f:
        return "\033[35mf\033[0m ";
    case Entity::G:
        return "\033[35mG\033[0m ";
    case Entity::g:
        return "\033[35mg\033[0m ";
    case Entity::E:
        return "\033[35mE\033[0m ";
    case Entity::e:
        return "\033[35me\033[0m ";
    case Entity::L:
        return "\033[35mL\033[0m ";
    case Entity::l:
        return "\033[35ml\033[0m ";
    case Entity::S:
        return "\033[35mS\033[0m ";
    case Entity::s:
        return "\033[35ms\033[0m ";
    case Entity::N:
        return "\033[35mN\033[0m ";
    case Entity::n:
        return "\033[35mn\033[0m ";
    case Entity::P:
        return "\033[31mP\033[0m ";
    case Entity::X:
        return "\033[31mX\033[0m ";
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
    int mod = max - min + 1;
    int i = (rand() % mod) + min;
    return i;
}