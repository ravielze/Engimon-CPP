#ifndef __ENGIMON_H__
#define __ENGIMON_H__
#include <iostream>
#include <utility>
#include <vector>
#include "Species.hpp"
#include "Skill.hpp"
#include "EntitySource.hpp"

class Engimon : public Species
{
private:
    pair<Engimon, Engimon> parent;
    string name;
    int level, exp, cum_exp;
    vector<Skill> skills;
    static int MAX_SKILL;
    static int MAX_CUM_EXP;
    EntitySource const livingSource;

public:
    Engimon();
    Engimon(Species &, EntitySource);

    //Operator Assignment
    Engimon &operator=(const Engimon &);

    //Check apakah engimon sama atau tidak
    bool operator==(const Species &);

    //Getter
    string getName() const;
    string getSpecies() const;
    EntitySource getEntitySource() const;

    //slot 0 sampe 4
    virtual Skill &getSkill(int slot) const;
    virtual void setSkill(int slot, const Skill &skill);

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