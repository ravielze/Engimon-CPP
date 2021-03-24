#ifndef __ENGIMON_H__
#define __ENGIMON_H__
#include <vector>
#include <utility>
#include <string>
#include "utils.hpp"
#include "lib/Engidex.hpp"
#include "lib/Species.hpp"
#include "lib/ElementManager.hpp"
#include "lib/Skill.hpp"
#include "lib/SkillItem.hpp"
#include "lib/constant/EntitySource.hpp"
#include "lib/constant/Exception.hpp"

using namespace std;

class Engimon : public Species
{
private:
    pair<string, string> parent;
    string name;
    int level, exp, cum_exp;
    vector<Skill> skills;
    static int MAX_SKILL;
    static int MAX_CUM_EXP;
    EntitySource const livingSource;

public:
    Engimon();
    Engimon(Species &, EntitySource);
    Engimon(Species &, EntitySource, string);

    //Operator Assignment
    Engimon &operator=(const Engimon &);

    //Check apakah engimon sama atau tidak
    bool operator==(const Engimon &);

    //Getter
    string getName() const;
    EntitySource getEntitySource() const;

    //slot 0 sampe 4
    Skill &getSkill(int slot);
    void setSkill(int slot, const Skill &skill);

    //throw kalau cumulative udah lewat
    void addExp(int);
    int getExp() const;

    void setFirstParent(string);
    void setSecondParent(string);

    void show() const;

    double getPower(const Elementum &);

    vector<Skill> getSkills() const;

    // Untuk breeding, this dengan engimon lain, result = anak
    virtual Engimon operator+(const Engimon &) const;

    // Untuk battle;
    Engimon &operator*(Engimon &other);
    //Untuk nambah skill;
    bool operator<<(Skill &);

    bool operator>(const Engimon &) const;
    bool operator<(const Engimon &) const;

    void learn(const SkillItem &);
};
#endif // __ENGIMON_H__