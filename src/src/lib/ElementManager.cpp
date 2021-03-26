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
}
