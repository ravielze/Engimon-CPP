#include "lib/ElementManager.hpp"

ElementManager ElementManager::instance;

void ElementManager::setMultiplier(Element attacker, Element defender, double multiplier)
{
    pair<Element, Element> elementPair(attacker, defender);
    ElementsMultiplier[elementPair] = multiplier;
}

double ElementManager::getTotalMultiplier(vector<Element> attacker, vector<Element> defender)
{
    double totalMultiplier = 0;
    for (auto ourElement : attacker)
    {
        double maxMultiplier = 0;
        for (auto enemyElement : defender)
        {
            double multiplier = ElementsMultiplier[pair<Element, Element>(ourElement, enemyElement)];
            if (multiplier > maxMultiplier)
            {
                maxMultiplier = multiplier;
            }
        }
        totalMultiplier += maxMultiplier;
    }
    return totalMultiplier > 2 ? 2 : totalMultiplier;
}
double ElementManager::getMultiplier(Element atacker, Element defender)
{
    if (atacker == Element::NONE || defender == Element::NONE)
    {
        return 0;
    }
    return ElementsMultiplier[pair<Element, Element>(atacker, defender)];
}

ElementManager &ElementManager::getInstance()
{
    return instance;
}

ElementManager::ElementManager()
{
    this->setMultiplier(Element::FIRE, Element::FIRE, 1);
    this->setMultiplier(Element::FIRE, Element::WATER, 0);
    this->setMultiplier(Element::FIRE, Element::ELECTRIC, 1);
    this->setMultiplier(Element::FIRE, Element::GROUND, 0.5);
    this->setMultiplier(Element::FIRE, Element::ICE, 2);

    this->setMultiplier(Element::WATER, Element::FIRE, 2);
    this->setMultiplier(Element::WATER, Element::WATER, 1);
    this->setMultiplier(Element::WATER, Element::ELECTRIC, 0);
    this->setMultiplier(Element::WATER, Element::GROUND, 1);
    this->setMultiplier(Element::WATER, Element::ICE, 1);

    this->setMultiplier(Element::ELECTRIC, Element::FIRE, 1);
    this->setMultiplier(Element::ELECTRIC, Element::WATER, 2);
    this->setMultiplier(Element::ELECTRIC, Element::ELECTRIC, 1);
    this->setMultiplier(Element::ELECTRIC, Element::GROUND, 0);
    this->setMultiplier(Element::ELECTRIC, Element::ICE, 1.5);

    this->setMultiplier(Element::GROUND, Element::FIRE, 1.5);
    this->setMultiplier(Element::GROUND, Element::WATER, 1);
    this->setMultiplier(Element::GROUND, Element::ELECTRIC, 2);
    this->setMultiplier(Element::GROUND, Element::GROUND, 1);
    this->setMultiplier(Element::GROUND, Element::ICE, 0);

    this->setMultiplier(Element::ICE, Element::FIRE, 0);
    this->setMultiplier(Element::ICE, Element::WATER, 1);
    this->setMultiplier(Element::ICE, Element::ELECTRIC, 0.5);
    this->setMultiplier(Element::ICE, Element::GROUND, 2);
    this->setMultiplier(Element::ICE, Element::ICE, 1);
}
