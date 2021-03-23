#ifndef __ELEMENT_MANAGER_H__
#define __ELEMENT_MANAGER_H__
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include "lib/constant/Element.hpp"
using namespace std;

class ElementManager
{
private:
    map<pair<Element, Element>, double> ElementsMultiplier;
    static ElementManager instance;

public:
    ElementManager();
    void setMultiplier(Element, Element, double);
    double getTotalMultiplier(vector<Element>, vector<Element>);
    double getMultiplier(Element, Element);
    static ElementManager &getInstance();
};
#endif // __ELEMENT_NAMAGER_H__