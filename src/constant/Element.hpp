#ifndef __ELEMENT_H__
#define __ELEMENT_H__

enum class Element
{
    FIRE,
    WATER,
    ELECTRIC,
    GROUND,
    ICE
};

string elementToString(Element e)
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
#endif // __ELEMENT_H__