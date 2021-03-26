#ifndef __SKILLITEM_H__
#define __SKILLITEM_H__
#include "lib/Skill.hpp"
#include "lib/constant/ItemType.hpp"
#include <iostream>

using namespace std;

class SkillItem : public Skill
{
private:
    string itemName;
    ItemType itemType;

public:
    SkillItem();
    //TODO skillitem copy constructor
    SkillItem(string itemName, Skill skill, ItemType it);

    SkillItem(const SkillItem &other);

    void show() const;

    //Operator Assignment
    SkillItem &operator=(const SkillItem &);

    //Operator > and < for map stl
    bool operator>(const SkillItem &) const;
    bool operator<(const SkillItem &) const;
};
#endif // __SKILLITEM_H__