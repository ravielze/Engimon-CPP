#ifndef __ENGIDEX_H__
#define __ENGIDEX_H__
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "lib/Species.hpp"
#include "lib/Engimon.hpp"
#include "lib/SkillItem.hpp"
using namespace std;

class Engidex
{
private:
    static int SPECIES_PER_PAGE;
    vector<Species> speciesStorage;
    vector<SkillItem> skillStorage;
    int speciesCount;
    int skillCount;
    static Engidex instance;

public:
    Engidex();

    //Menambah species ke Engidex
    bool operator+(Species);
    bool operator+(SkillItem);

    //Memunculkan species pada page tertentu
    void show(int page) const;

    Species getDualElementEngimon(Element, Element);
    Species getSpeciesByString(string);

    //Operator Assignment
    Engidex &operator=(const Engidex &);

    //Cek suatu species ada atau engga
    bool operator%(const Species &) const;

    // Cek suatu skill ada atau engga
    bool operator%(const SkillItem &) const;

    static Engidex &getInstance();

    Species &getRandomSpecies(Element) const;
    SkillItem createRandomSkillItem(Element) const;
};
#endif // __ENGIDEX_H__