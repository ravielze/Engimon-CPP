#include "lib/Engidex.hpp"

int Engidex::SPECIES_PER_PAGE = 10;
Engidex Engidex::instance;

Engidex::Engidex()
{
    this->speciesCount = 0;
    this->operator+(Species("Jason <3 <3 <3", {Element::ICE}, {"gatau", "liat nanti"}));
    (*this) + Species("Tikus Listrik", {Element::ELECTRIC}, {});
    this->operator+(Species("Keong", {Element::ICE}, {"gatau", "liat nanti"}));
}

void Engidex::show(int page) const
{
    if (this->speciesStorage.size() > 0 && page >= 1)
    {
        int start = (page - 1) * SPECIES_PER_PAGE;
        int end = page * SPECIES_PER_PAGE;
        for (int i = start; i < end; i++)
        {
            this->speciesStorage[i].show();
            if (i + 1 >= this->speciesCount)
            {
                break;
            }
        }
    }
}

Species Engidex::getDualElementEngimon(Element firstElement, Element secondElement)
{
    for (int i = 0; i < speciesStorage.size(); i++)
    {
        if (speciesStorage[i].getElementCount() == 2 && (speciesStorage[i] % firstElement && speciesStorage[i] % secondElement))
        {
            return speciesStorage[i];
        }
    }
    return Species();
}

Species Engidex::getSpeciesByString(string speciesName)
{
    for (int i = 0; i < speciesStorage.size(); i++)
    {
        if (speciesName == speciesStorage[i].getSpeciesName())
        {
            return speciesStorage[i];
        }
    }
    return Species();
}

Engidex &Engidex::operator=(const Engidex &other)
{
    this->speciesStorage.clear();
    for (int i = 0; i < other.speciesCount; i++)
    {
        this->speciesStorage.push_back(other.speciesStorage[i]);
    }
    this->speciesCount = other.speciesCount;

    this->skillStorage.clear();
    for (int i = 0; i < other.skillCount; i++)
    {
        this->skillStorage.push_back(other.skillStorage[i]);
    }

    return *this;
}

bool Engidex::operator%(const Species &x) const
{
    for (int i = 0; i < this->speciesCount; i++)
    {
        if (this->speciesStorage[i] == x)
        {
            return true;
        }
    }
    return false;
}

bool Engidex::operator%(const Skill &) const
{
    for (int i = 0; i < this->skillCount; i++)
    {
        if (this->skillStorage[i] == x)
        {
            return true;
        }
    }
    return false;
}

bool Engidex::operator+(Species newSpecies)
{
    newSpecies.setSpeciesNumber(speciesCount);
    this->speciesStorage.push_back(newSpecies);
    speciesCount++;
    return true;
}

bool Engidex::operator+(Skill skill)
{
    this->skillStorage.push_back(skill);
    skillCount++;
    return true;
}

Engidex &Engidex::getInstance()
{
    return instance;
}

Engimon &Engidex::createRandomEngimon() const
{
    //TODO
}

SkillItem &Engidex::createRandomSkillItem(Element) const
{
    //TODO
}

bool Engidex::operator+(Skill)
{
    //TODO
}
