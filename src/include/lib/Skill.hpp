#ifndef __SKILL_H__
#define __SKILL_H__
#include <iostream>
#include <vector>
#include "lib/Elementum.hpp"
using namespace std;

class Skill : public Elementum
{
protected:
    string name;
    double power;
    int masteryLevel;

public:
    Skill();
    Skill(const Skill &);
    Skill(string name, double power, vector<Element> elements);

    string getName() const;
    double getPower() const;
    void setPower(double);
    int getMasteryLevel() const;
    void setMasteryLevel(int);

    bool operator==(const Skill &) const;
    Skill &operator=(const Skill &);
};
#endif // __SKILL_H__