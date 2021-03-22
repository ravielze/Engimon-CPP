#ifndef __ITEMTYPE_H__
#define __ITEMTYPE_H__
#include <iostream>
using namespace std;

enum class ItemType
{
    HM,
    TM,
    OTHER,
    UNKNOWN
};

string toString(ItemType it)
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

#endif // __ITEMTYPE_H__