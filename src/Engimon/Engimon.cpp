#include "Engimon.hpp"
#include <iostream>
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
bool Engimon::operator==(const Engimon &engimon)
{
    return Species::operator==(engimon) && name == engimon.name && level == engimon.level && exp == engimon.exp && cum_exp == engimon.cum_exp && parent.first == engimon.parent.first && parent.second == engimon.parent.second;
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

//slot 0 sampe 3
Skill &Engimon::getSkill(int slot)
{
    return skills[slot];
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
    Species::show();
    cout << "Name \t: " << name << endl;
    
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
Engimon &Engimon::operator+(const Engimon &other) const
{
    // GET SKILLS
    vector<Skill> parentASkills = this->getSkills();
    vector<Skill> parentBSkills = other.getSkills();
    vector<Skill> choosenSkills;
    int maxSkills = parentASkills.size() + parentBSkills.size() > 4 ? 4 : parentASkills.size() + parentBSkills.size();
    for (int i = 0; i < maxSkills; i++)
    {
        
        bool parentAChoosen = false;
        int parentAMaxMastery = -1;
        int parentBMaxMastery = -1;
        int parentASlot = -1;
        int parentBSlot = -1;
        for (int j = parentASkills.size() - 1; j >= 0;j--)
        {
            if (parentASkills[j].getMasteryLevel() >= parentAMaxMastery)
            {
                parentAMaxMastery = parentASkills[j].getMasteryLevel();
                parentASlot = j;
            }
        }
        for (int j = parentBSkills.size() - 1; j >= 0;j--)
        {
            if (parentBSkills[j].getMasteryLevel() >= parentBMaxMastery)
            {
                parentBMaxMastery = parentBSkills[j].getMasteryLevel();
                parentBSlot = j;
            }
        }
        // Sampe sekarang, slot yang dipilih itu udh slot dengan mastery level tertinggi dan kalau ada yg
        // sama, dipilih slot terdepan
        if (parentASlot == -1) // YANG KEPILIH DARI PARENT B karena parentA udh habis slotnya
        {
            choosenSkills.push_back(parentBSkills[parentBSlot]);
            parentBSkills.erase(parentBSkills.begin() + parentBSlot);
        }
        else if (parentBSlot == -1) // YANG KEPILIH DARI PARENT A karena parentB udh habis slotnya
        {
            choosenSkills.push_back(parentASkills[parentASlot]);
            parentASkills.erase(parentASkills.begin() + parentASlot);

        }
        else
        {
            Skill choosen;
            if (parentAMaxMastery >= parentBMaxMastery) // Poin 5.d.i.2
            {
                choosen = parentASkills[parentASlot];
                parentAChoosen = true;
            }
            else
            {
                choosen = parentBSkills[parentBSlot];
                parentAChoosen = false;
            }
            vector<Skill> toCheck = parentAChoosen ? parentBSkills : parentASkills;
            for (int j = 0; j < toCheck.size();j++)
            {
                if (toCheck[j] == choosen)
                {
                    if (toCheck[j].getMasteryLevel() == choosen.getMasteryLevel())// poin 5.d.ii.2
                    {
                        choosen.setMasteryLevel(choosen.getMasteryLevel() + 1);
                    }
                    else // poin 5.d.ii.2
                    {
                        choosen.setMasteryLevel(max(choosen.getMasteryLevel(), toCheck[j].getMasteryLevel()));
                    }
                    break;
                }
            }
            choosenSkills.push_back(choosen);
            if (parentAChoosen)
            {
                parentASkills.erase(parentASkills.begin() + parentASlot);
            }
            else
            {
                parentBSkills.erase(parentBSkills.begin() + parentBSlot);
            }

        }
    }
    // GET ELEMENT AND SPESIES
    ElementManager elementManager = ElementManager::getInstance();
    Element parentAElement;
    Element parentBElement;
    Element childElement;
    string childSpecies;
    if (this->elements.size() > 1)
    {
        if (elementManager.getMultiplier(this->elements[0], this->elements[1]) > elementManager.getMultiplier(this->elements[1], this->elements[0]))
        {
            parentAElement = this->elements[0];
        }
        else
        {
            parentAElement = this->elements[1];
        }
    }
    else
    {
        parentAElement = this->elements[0];
    }

    if (other.elements.size() > 1)
    {
        if (elementManager.getMultiplier(other.elements[0], other.elements[1]) > elementManager.getMultiplier(other.elements[1], other.elements[0]))
        {
            parentBElement = other.elements[0];
        }
        else
        {
            parentBElement = other.elements[1];
        }
    }
    else
    {
        parentBElement = other.elements[0];
    }

    if (parentAElement == parentBElement) // point 5.e.i
    {
        childElement = parentAElement;
        childSpecies = this->getSpeciesName(); // Ini bisa diganti. Baca point 5.e.1
    }
    else if (elementManager.getMultiplier(parentAElement, parentBElement) == elementManager.getMultiplier(parentBElement, parentAElement)) // point 5.e.3
    {
        // Cari engimon yang memiliki dual element di engidex dan itu jadi spesiesnya.
        // Anaknya memiliki elemen dari parentA dan parentB
    }
    else // point 5.e.2
    {
        if (elementManager.getMultiplier(parentAElement, parentBElement) > elementManager.getMultiplier(parentBElement, parentAElement))
        {
            childElement = parentAElement;
            childSpecies = this->getSpeciesName();
        }
        else
        {
            childElement = parentBElement;
            childSpecies = other.getSpeciesName();
        }
    }
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
        for (int i = 0; i < this->skills.size();i++)
        {
            if (skills[i] == skill)
            {
                return false;
            }
        }
        this->skills.push_back(skill);
        return true;
    }
    else
    {
        return false;
    }
}