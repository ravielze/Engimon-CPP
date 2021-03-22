#include "lib/SkillItem.hpp"

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


SkillItem::SkillItem() : Skill()
{
    this->itemName = "";
    this->itemType = ItemType::UNKNOWN;
}

SkillItem::SkillItem(string itemName, Skill &skill, ItemType it) : Skill(skill)
{
    this->itemName = itemName;
    this->itemType = it;
}

void SkillItem::show() const
{
    cout << this->itemName << endl;
    cout << toString(this->itemType) << endl;
}

bool SkillItem::operator>>(Engimon &x)
{
    //TODO
}

SkillItem &SkillItem::operator=(const SkillItem &x)
{
    Skill::operator=(x);
    this->itemName = x.itemName;
    this->itemType = x.itemType;
}