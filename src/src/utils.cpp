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
Engidex createEngidex()
{
}