#ifndef __ENGIDEX_H__
#define __ENGIDEX_H__
#include <iostream>
#include "Species.hpp"
using namespace std;

class Engidex
{
private:
    static const int SPECIES_PER_PAGE;
    vector<Species> storage;
    static int SPECIES_COUNT;

public:
    Engidex();
    ~Engidex();

    //Menambah species ke Engidex
    Engidex &operator+(const Species &);

    //Mengurangi species dari Engidex
    Engidex &operator-(const Species &);

    //Memunculkan species pada page tertentu
    void show(int page) const;

    //Operator Assignment
    Engidex &operator=(const Engidex &);
};
#endif // __ENGIDEX_H__