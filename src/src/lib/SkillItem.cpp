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
    cout << this->itemName << "\t";
    cout << convertItemTypeToString(this->itemType);
}

SkillItem &SkillItem::operator=(const SkillItem &x)
{
    Skill::operator=(x);
    this->itemName = x.itemName;
    this->itemType = x.itemType;
    return *this;
}

bool SkillItem::operator>(const SkillItem &other) const
{
    return this->itemName > other.itemName;
}

bool SkillItem::operator<(const SkillItem &other) const
{
    return this->itemName > other.itemName;
}
