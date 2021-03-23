#include "lib/Inventory.hpp"

int main()
{
    Inventory<SkillItem> a(10);

    vector<Element> thunderBoltElement;
    thunderBoltElement.push_back(Element::ELECTRIC);

    Skill thunderbolt("Thunderbolt", 20, 0, thunderBoltElement);

    SkillItem skillItem("itemname", thunderbolt, ItemType::HM);
    a + skillItem;
    a.show(1);
    cout << "Maksimal kapasitas : " << a.getCapacity() << endl;

    //     I1 + 5;
    //     I1 + 3;
    //     I1 + 2;
    //     I1 + 3;
    //     I1 + 3;
    //     cout << "Kapasitas sekarang : " << I1.getCapacity() << endl;
    //     I1.show(1);

    //     I1 - 5;
    //     I1 - 3;
    //     cout << "Kapasitas sekarang : " << I1.getCapacity() << endl;
    //     I1.show(1);

    //     I1 % 5;
    //     I1 % 3;

    //     I1 ^ 5;
    //     I1 ^ 3;
    //
}