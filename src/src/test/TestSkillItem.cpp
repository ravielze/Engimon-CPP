#include "SkillItem.hpp"

int main()
{
    SkillItem s1;
    Skill skill1();
    SkillItem s2("item_name", skill1, ItemType::TM);
    s1 = s2;
    s1.show();
}