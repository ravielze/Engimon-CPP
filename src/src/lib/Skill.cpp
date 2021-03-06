#include "lib/Skill.hpp"

Skill::Skill() : Elementum()
{
    this->name = "";
    this->power = 0;
    this->masteryLevel = 1;
}

Skill::Skill(string name, double power, vector<Element> elements) : Elementum(elements)
{
    this->name = name;
    this->power = power;
    this->masteryLevel = 1;
}

Skill::Skill(const Skill &other) : Elementum(other)
{
    this->name = other.name;
    this->power = other.power;
    this->masteryLevel = other.masteryLevel;
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

bool Skill::operator==(const Skill &x) const
{
    if (this->power == x.power && this->name == x.name)
    {
        return true && Elementum::operator==(x);
    }
    else
    {
        return false;
    }
}

Skill &Skill::operator=(const Skill &x)
{
    Elementum::operator=(x);
    this->name = x.name;
    this->power = x.power;
    this->masteryLevel = x.masteryLevel;
    return *this;
}