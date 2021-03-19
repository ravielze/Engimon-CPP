#include "Engimon.hpp"

int Engimon::MAX_SKILL = 4;
int Engimon::MAX_CUM_EXP = 10000;

Engimon::Engimon() : livingSource(EntitySource::UNKNOWN)
{
    this->level = 0;
    this->exp = 0;
    this->cum_exp = 0;
}

Engimon::Engimon(Species &s, EntitySource es) : Species(s), livingSource(es)
{
    this->level = 1;
    this->exp = 0;
    this->cum_exp = 0;
}

//Operator Assignment
Engimon &Engimon::operator=(const Engimon &engimon)
{
    Species::operator=(engimon);
    this->parent.first = engimon.parent.first;
    this->parent.second = engimon.parent.second;
    this->level = engimon.level;
    this->exp = engimon.exp;
    this->cum_exp = engimon.cum_exp;
    this->skills = engimon.skills;

    return *this;
}

//Check apakah engimon sama atau tidak
bool Engimon::operator==(const Species &)
{
}

//Getter
string Engimon::getName() const
{
    return name;
}
string Engimon::getSpecies() const
{
    return speciesName;
}
EntitySource Engimon::getEntitySource() const
{
}

//slot 0 sampe 4
Skill &Engimon::getSkill(int slot) const
{
}
void Engimon::setSkill(int slot, const Skill &skill)
{
}

//throw kalau cumulative udah lewat
void Engimon::addExp(int)
{
}
void Engimon::removeExp(int)
{
}
int Engimon::getExp() const
{
}

// untuk rumus exp ke level
int Engimon::calculateExp(int level)
{
}

void Engimon::show() const
{
}

double Engimon::getPower(Element element) const
{
}

// Untuk breeding, this dengan engimon lain, result = anak
Engimon &Engimon::operator+(const Engimon &) const
{
}

// Untuk battle;
void Engimon::operator*(Engimon &)
{
}

//Untuk buang skill pada slot ...;
Skill &Engimon::operator>>(int)
{
}
//Untuk nambah skill;
bool Engimon::operator<<(Skill &)
{
}

// untuk rumus exp ke level
int Engimon::calculateExp(int level)
{
}

void Engimon::show() const
{
}

double Engimon::getPower(Element element) const
{
}

// Untuk breeding, this dengan engimon lain, result = anak
Engimon &Engimon::operator+(const Engimon &) const
{
}

// Untuk battle;
void Engimon::operator*(Engimon &)
{
}

//Untuk buang skill pada slot ...;
Skill &Engimon::operator>>(int)
{
}
//Untuk nambah skill;
bool Engimon::operator<<(Skill &)
{
}
