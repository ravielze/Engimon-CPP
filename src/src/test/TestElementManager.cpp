#include "lib/ElementManager.hpp"

int main()
{
    vector<Element> lanturnElement;
    lanturnElement.push_back(Element::WATER);
    lanturnElement.push_back(Element::ELECTRIC);

    vector<Element> charmenderElement;
    charmenderElement.push_back(Element::FIRE);

    ElementManager::getInstance().setMultiplier(Element::ELECTRIC, Element::WATER, 2);
    ElementManager::getInstance().setMultiplier(Element::WATER, Element::ELECTRIC, 0);
    ElementManager::getInstance().setMultiplier(Element::ELECTRIC, Element::FIRE, 1);
    ElementManager::getInstance().setMultiplier(Element::FIRE, Element::ELECTRIC, 1);
    ElementManager::getInstance().setMultiplier(Element::WATER, Element::FIRE, 2);
    ElementManager::getInstance().setMultiplier(Element::FIRE, Element::WATER, 0);
    cout << "Set complete" << endl;

    cout << "Total Multiplier :" << endl;
    ElementManager::getInstance().getTotalMultiplier({Element::ELECTRIC}, {Element::WATER});
    ElementManager::getInstance().getTotalMultiplier({Element::WATER}, {Element::ELECTRIC});
    ElementManager::getInstance().getTotalMultiplier({Element::ELECTRIC}, {Element::FIRE});
    ElementManager::getInstance().getTotalMultiplier({Element::FIRE}, {Element::ELECTRIC});
    ElementManager::getInstance().getTotalMultiplier({Element::WATER}, {Element::FIRE});
    ElementManager::getInstance().getTotalMultiplier({Element::FIRE}, {Element::WATER});
    cout << "Total Multiplier Lanturn and Charmender : ";
    cout << ElementManager::getInstance().getTotalMultiplier(lanturnElement, charmenderElement);

    cout << "Multiplier :" << endl;
    ElementManager::getInstance().getMultiplier(Element::ELECTRIC, Element::WATER);
    ElementManager::getInstance().getMultiplier(Element::WATER, Element::ELECTRIC);
    ElementManager::getInstance().getMultiplier(Element::ELECTRIC, Element::FIRE);
    ElementManager::getInstance().getMultiplier(Element::FIRE, Element::ELECTRIC);
    ElementManager::getInstance().getMultiplier(Element::WATER, Element::FIRE);
    ElementManager::getInstance().getMultiplier(Element::FIRE, Element::WATER);
}
