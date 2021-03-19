#ifndef __SKILLITEM_H__
#define __SKILLITEM_H__
#include "Skill.hpp"
#include "ItemType.hpp"
#include "Engimon.hpp"
#include <iostream>
using namespace std;

class SkillItem : Skill
{
private:
    string itemName;
    ItemType itemType;

public:
    SkillItem();
    SkillItem(string itemName, Skill &skill);

    void show() const;

    //buat dilearn ke engimon
    bool operator>>(Engimon &);
};
#endif // __SKILLITEM_H__