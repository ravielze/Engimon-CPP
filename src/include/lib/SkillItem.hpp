#ifndef __SKILLITEM_H__
#define __SKILLITEM_H__
#include "lib/Skill.hpp"
#include "lib/constant/ItemType.hpp"
#include "lib/Engimon.hpp"
#include <iostream>
using namespace std;

class SkillItem : Skill
{
private:
    string itemName;
    ItemType itemType;

public:
    SkillItem();
    SkillItem(string itemName, Skill &skill, ItemType it);
    ~SkillItem();

    void show() const;

    //buat dilearn ke engimon
    bool operator>>(Engimon &);
    //Operator Assignment
    SkillItem &operator=(const SkillItem &);
};
#endif // __SKILLITEM_H__