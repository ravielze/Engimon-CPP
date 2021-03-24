#ifndef __SPECIES_H__
#define __SPECIES_H__
#include <vector>
#include <iostream>
#include "lib/constant/Element.hpp"
#include "lib/Elementum.hpp"
using namespace std;

class Species : public Elementum
{
protected:
    int speciesNumber;
    string speciesName;
    vector<string> message;

public:
    Species();
    Species(const Species &);
    Species(string name, vector<Element> elements, vector<string> messages);

    string getSpeciesName() const;

    //Show random message ke layar
    void sendMessage() const;

    //Show species ke layar
    void show() const;

    //Check apakah species sama atau tidak
    bool operator==(const Species &) const;

    //Operator Assignment
    Species &operator=(const Species &);

    void setSpeciesNumber(int);
};
#endif // __SPECIES_H__