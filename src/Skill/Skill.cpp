#include "Skill.hpp"

Skill::Skill() : Elementum()
{
    this->name = "";
    this->power = 0;
    this->masteryLevel = 0;
}

Skill::Skill(string name, double power, int masteryLevel, vector<Element> elements) : Elementum(elements)
{
    this->name = name;
    this->power = power;
    this->masteryLevel = masteryLevel;
}

string Skill::getName() const
{
    return this->name;
}

double Skill::getPower() const
{
    return this->power;
}

void Skill::setPower(double power)
{
    this->power = power;
}

int Skill::getMasteryLevel() const
{
    return this->masteryLevel;
}

void Skill::setMasteryLevel(int masteryLevel)
{
    this->masteryLevel = masteryLevel;
}

bool Skill::operator==(const Skill &X) const
{
    this->name = x.name;
    this->power = x.power;
    this->masteryLevel = x.masteryLevel;
    return this->el
}

Skill &Skill::operator=(const Skill &)
{
}