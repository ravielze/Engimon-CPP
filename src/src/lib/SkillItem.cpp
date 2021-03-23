#include "lib/SkillItem.hpp"
#include "utils.hpp"



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
    cout << convertItemTypeToString(this->itemType) << endl;
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
