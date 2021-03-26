#ifndef __ELEMENTUM_H__
#define __ELEMENTUM_H__
#include <iostream>
#include <vector>
#include "lib/constant/Element.hpp"
#include "lib/ElementManager.hpp"
using namespace std;

class Elementum
{
protected:
    vector<Element> elements;

public:
    Elementum();
    //TODO Elementum copy constructor
    Elementum(vector<Element> otherElements);

    Elementum(const Elementum &other);

    //Check apakah entitas ini memiliki suatu element
    bool operator%(Element) const;
    bool operator%(const Elementum &el) const;

    bool operator==(const Elementum &) const;

    Elementum &operator=(const Elementum &);

    void show() const;

    int getElementCount() const;
    double getTotalMultiplier(const Elementum &other) const;
};
#endif // __ELEMENTUM_H__l