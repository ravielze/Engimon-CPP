#ifndef __ENGIMON_H__
#define __ENGIMON_H__
#include <iostream>
#include <utility>
#include <vector>
#include "Species.hpp"
#include "Skill.hpp"
#include "ElementManager.hpp"
#include "EntitySource.hpp"
#include "Exception.hpp"

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
    EntitySource getEntitySource() const;

    //slot 0 sampe 4
    virtual Skill &getSkill(int slot);
    virtual void setSkill(int slot, const Skill &skill);

    //throw kalau cumulative udah lewat
    void addExp(int);
    int getExp() const;

    void show() const;

    double getPower(vector<Element>);

    vector<Skill> getSkills() const;

    // Untuk breeding, this dengan engimon lain, result = anak
    Engimon &operator+(const Engimon &) const;

    // Untuk battle;
    Engimon &operator*(Engimon &other);

    //Untuk buang skill pada slot ...;
    Skill &operator>>(int);
    //Untuk nambah skill;
    bool operator<<(Skill &);
};
#endif // __ENGIMON_H__