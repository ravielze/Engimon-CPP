#ifndef __ELEMENTABLE_H__
#define __ELEMENTABLE_H__
#include <iostream>
#include <vector>
#include "Element.hpp"
using namespace std;

class Elementable
{
protected:
    static const int MAX_SKILL;
    vector<Element> elements;

public:
    //Check apakah Species tersebut memiliki suatu element
    bool operator%(Element) const;

    bool operator==(const Elementable &) const;
};
#endif // __ELEMENTABLE_H__