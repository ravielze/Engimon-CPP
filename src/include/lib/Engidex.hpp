#ifndef __ENGIDEX_H__
#define __ENGIDEX_H__
#include <iostream>
#include "lib/Species.hpp"
using namespace std;

class Engidex
{
private:
    static int SPECIES_PER_PAGE;
    vector<Species> storage;
    int speciesCount;
    static Engidex instance;

public:
    Engidex();

    //Menambah species ke Engidex
    bool operator+(Species &);

    //Memunculkan species pada page tertentu
    void show(int page) const;

    Species getDualElementEngimon(Element, Element);
    Species getSpeciesByString(string);

    //Operator Assignment
    Engidex &operator=(const Engidex &);

    //Cek suatu species ada atau engga
    bool operator%(const Species &) const;

    static Engidex &getInstance();
};
#endif // __ENGIDEX_H__