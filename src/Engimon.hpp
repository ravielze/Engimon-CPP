#ifndef __ENGIMON_H__
#define __ENGIMON_H__
#include <iostream>
#include <utility>
#include <vector>
#include "Species.hpp"
#include "Skill.hpp"

class Engimon : public Species
{
private:
    pair<Engimon, Engimon> parent;
    int level, exp, cum_exp;
    vector<Skill> skills;
    static const int MAX_SKILL;

public:
    Engimon(string name, string species, vector<Element> elements);
    ~Engimon();

    //Operator Assignment
    Engimon &operator=(const Engimon &);

    //Check apakah engimon sama atau tidak
    bool operator==(const Species &);

    //Getter
    string getName() const;
    string getSpecies() const;
    Engimon &getFirstParent() const;
    Engimon &getSecondParent() const;
    Species &getFirstParentSpecies() const;
    Species &getSecondParentSpecies() const;

    //slot 0 sampe 4
    Skill &getSkill(int slot) const;
    void setSkill(int slot, const Skill &skill);

    //throw kalau cumulative udah lewat
    void addExp(int);
    void removeExp(int);
    int getExp() const;

    // untuk rumus exp ke level
    static int calculateExp(int level);

    void show() const;

    double getPower(Element element) const;

    // Untuk breeding, this dengan engimon lain, result = anak
    Engimon &operator+(const Engimon &) const;

    // Untuk battle;
    void operator*(Engimon &);

    //Untuk buang skill pada slot ...;
    Skill &operator>>(int);
    //Untuk nambah skill;
    bool operator<<(Skill &);
};
#endif // __ENGIMON_H__