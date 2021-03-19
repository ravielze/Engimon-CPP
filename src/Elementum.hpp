#ifndef __ELEMENTUM_H__
#define __ELEMENTUM_H__
#include <iostream>
#include <vector>
#include "Element.hpp"
using namespace std;

class Elementum
{
protected:
    static const int MAX_SKILL;
    vector<Element> elements;

public:
    Elementum();
    Elementum(vector<Element> elements);
    virtual ~Elementum();
    //Check apakah Species tersebut memiliki suatu element
    bool operator%(Element) const;

    bool operator==(const Elementum &) const;
};
#endif // __ELEMENTUM_H__