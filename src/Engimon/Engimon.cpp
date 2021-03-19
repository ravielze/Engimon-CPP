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
bool Engimon::operator==(const Species &engimon)
{
}

//Getter
string Engimon::getName() const
{
    return name;
}

EntitySource Engimon::getEntitySource() const
{
    return livingSource;
}

//slot 0 sampe 4
Skill &Engimon::getSkill(int slot)
{
    if (skills.size() - 1 < slot)
    {
        return skills[slot];
    }
    else
    {
        throw ""; // skill diluar batas slot
    }
}
void Engimon::setSkill(int slot, const Skill &skill)
{
    skills[slot] = skill;
}

//throw kalau cumulative udah lewat
void Engimon::addExp(int exp)
{
    cum_exp += exp;
    this->exp += exp;

    if (cum_exp > Engimon::MAX_CUM_EXP)
    {
        throw Exception::ENGIMON_EXP_OVERFLOW;
    }

    if (exp >= level * 100)
    {
        exp -= level * 100;
        level += 1;
    }
}

int Engimon::getExp() const
{
    return exp;
}

void Engimon::show() const
{
    // Nanti lah ya hehe
}

double Engimon::getPower(vector<Element> element)
{
    double totalSkillPower = 0;
    for (int i = 0; i < skills.size(); i++)
    {
        totalSkillPower += skills[i].getPower() * skills[i].getMasteryLevel();
    }

    return totalSkillPower + level * ElementManager::getInstance().getTotalMultiplier(this->elements, element);
}

vector<Skill> Engimon::getSkills() const
{
    return this->skills;
}

// Untuk breeding, this dengan engimon lain, result = anak
Engimon &Engimon::operator+(const Engimon &) const
{
}

// Untuk battle;
Engimon &Engimon::operator*(Engimon &other)
{
    double ourPower = this->getPower(other.getElements());
    double otherPower = other.getPower(this->elements);
    if (ourPower >= otherPower) // Kita menang
    {
        this->addExp(100); // Masih statik exp yang didapatkan
        return other;
    }
    else // Musuh menang
    {
        throw Exception::ENGIMON_LOST_BATTLE;
    }
}

//Untuk buang skill pada slot ...;
Skill &Engimon::operator>>(int slot)
{
    if (slot <= this->skills.size() - 1)
    {
        this->skills.erase(this->skills.begin() + slot);

        return this->skills[slot];
    }
}
//Untuk nambah skill;
bool Engimon::operator<<(Skill &skill)
{
    if (this->skills.size() < Engimon::MAX_SKILL)
    {
        this->skills.push_back(skill);
        return true;
    }
    else
    {
        return false;
    }
}
