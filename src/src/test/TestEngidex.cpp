#include "lib/Engidex.hpp"

int main()
{
    ElementManager::getInstance().setMultiplier(Element::ELECTRIC, Element::WATER, 2);
    ElementManager::getInstance().setMultiplier(Element::WATER, Element::ELECTRIC, 0);
    ElementManager::getInstance().setMultiplier(Element::FIRE, Element::ELECTRIC, 1);
    ElementManager::getInstance().setMultiplier(Element::ELECTRIC, Element::FIRE, 1);

    vector<Element> lanturnElement;
    lanturnElement.push_back(Element::FIRE);
    // lanturnElement.push_back(Element::ELECTRIC);

    vector<Element> pikachuElement;
    pikachuElement.push_back(Element::ELECTRIC);
    // pikachuElement.push_back(Element::GROUND);
    Species lanturn("lanturn", lanturnElement);
    Species pikachu("pikachu", pikachuElement);
    Species copy_pikachu;
    Engidex e;
    e + lanturn;
    e + pikachu;
    e.show(1);
    copy_pikachu = e.getSpeciesByString("pikachu");
    cout << copy_pikachu.getSpeciesName() << endl;
    cout << "Does lanturn exists? " << e % lanturn << endl;
}