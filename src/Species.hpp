#ifndef __SPECIES_H__
#define __SPECIES_H__
#include <vector>
#include <iostream>
#include "Element.hpp"
#include "Elementable.hpp"
using namespace std;

class Species : public Elementable
{
protected:
    string name;
    string species;
    vector<string> message;

public:
    Species();
    Species(string name, string species, vector<Element> elements);
    virtual ~Species();

    //Show random message ke layar
    void sendMessage();

    //Show species ke layar
    void show();

    //Check apakah species sama atau tidak
    bool operator==(const Species &) const;

    //Operator Assignment
    Species &operator=(const Species &);
};
#endif // __SPECIES_H__