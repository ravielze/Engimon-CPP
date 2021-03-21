#ifndef __ELEMENTUM_H__
#define __ELEMENTUM_H__
#include <iostream>
#include <vector>
#include "../constant/Element.hpp"
using namespace std;

class Elementum
{
protected:
    vector<Element> elements;

public:
    Elementum();
    Elementum(vector<Element> elements);

    //Check apakah entitas ini memiliki suatu element
    bool operator%(Element) const;

    bool operator==(const Elementum &) const;

    Elementum &operator=(const Elementum &);

    vector<Element> getElements();

    void show() const;
};
#endif // __ELEMENTUM_H__