#ifndef __ENGIDEX_H__
#define __ENGIDEX_H__
#include <iostream>
#include "lib/Species.hpp"
#include "lib/Engimon.hpp"
#include "lib/Skill.hpp"
#include "lib/SkillItem.hpp"
using namespace std;

class Engidex
{
private:
    static int SPECIES_PER_PAGE;
    vector<Species> speciesStorage;
    vector<Skill> skillStorage;
    int speciesCount;
    int skillCount;
    static Engidex instance;

public:
    Engidex();

    //Menambah species ke Engidex
    bool operator+(Species);
    bool operator+(Skill);

    //Memunculkan species pada page tertentu
    void show(int page) const;

    Species getDualElementEngimon(Element, Element);
    Species getSpeciesByString(string);

    //Operator Assignment
    Engidex &operator=(const Engidex &);

    //Cek suatu species ada atau engga
    bool operator%(const Species &) const;

    // Cek suatu skill ada atau engga
    bool operator%(const Skill &) const;

    static Engidex &getInstance();

    Engimon &createRandomEngimon() const;
    SkillItem &createRandomSkillItem(Element) const;
};
#endif // __ENGIDEX_H__