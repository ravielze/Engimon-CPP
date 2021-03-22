#include "lib/Engimon.hpp"

int main () {
    vector<Element> lanturnElement;
    lanturnElement.push_back(Element::ELECTRIC);
    lanturnElement.push_back(Element::WATER);

    vector<Element> pikachuElement;
    pikachuElement.push_back(Element::ELECTRIC);
    
    Species lanturn ("Lanturn", lanturnElement);
    Species pikachu ("Pikachu", pikachuElement);

    vector<Element> thunderBoltElement;
    thunderBoltElement.push_back(Element::ELECTRIC);

    Skill thunderbold("Thunderbolt", 20, 0, thunderBoltElement);


    lanturn.show();
    Engimon myLanturn(lanturn, EntitySource::WILD, "mylanturn");
    Engimon myPikachu(pikachu, EntitySource::WILD);

    myPikachu<<thunderbold;
    myPikachu.show();

    return 0;
}