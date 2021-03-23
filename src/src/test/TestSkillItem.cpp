#include "lib/SkillItem.hpp"

int main()
{
    SkillItem s1;
    Skill skill1;
    // SkillItem s2("item_name", skill1, ItemType::TM);
    
    SkillItem s2 ("Hello", skill1, ItemType::HM);
    s1 = s2;
    s1.show();
}