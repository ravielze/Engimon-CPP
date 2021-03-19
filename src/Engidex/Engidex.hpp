#ifndef __ENGIDEX_H__
#define __ENGIDEX_H__
#include <iostream>
#include "Species.hpp"
using namespace std;

class Engidex
{
private:
    static int SPECIES_PER_PAGE;
    vector<Species> storage;
    int speciesCount;

public:
    Engidex();

    //Menambah species ke Engidex
    bool &operator+(const Species &);

    //Mengurangi species dari Engidex
    bool &operator-(const Species &);

    //Memunculkan species pada page tertentu
    void show(int page) const;

    //Operator Assignment
    Engidex &operator=(const Engidex &);

    //Cek suatu species ada atau engga
    bool operator%(const Engidex &) const;
};
#endif // __ENGIDEX_H__