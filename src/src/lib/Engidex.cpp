#include "lib/Engidex.hpp"

int Engidex::SPECIES_PER_PAGE = 10;
Engidex Engidex::instance;

Engidex::Engidex()
{
    this->speciesCount = 0;
}

void Engidex::show(int page) const
{
    if (this->storage.size() > 0 && page >= 1)
    {
        int start = (page - 1) * SPECIES_PER_PAGE;
        int end = page * SPECIES_PER_PAGE;
        for (int i = start; i < end; i++)
        {
            this->storage[i].show();
            if (i + 1 >= this->speciesCount)
            {
                break;
            }
        }
    }
}

Species Engidex::getDualElementEngimon(Element firstElement, Element secondElement)
{
    for (int i = 0; i < storage.size(); i++)
    {
        if (storage[i].getElementCount() == 2 && (storage[i] % firstElement && storage[i] % secondElement))
        {
            return storage[i];
        }
    }
    return Species();
}

Species Engidex::getSpeciesByString(string speciesName)
{
    for (int i = 0; i < storage.size(); i++)
    {
        if (speciesName == storage[i].getSpeciesName())
        {
            return storage[i];
        }
    }
    return Species();
}

Engidex &Engidex::operator=(const Engidex &other)
{
    this->storage.clear();
    for (int i = 0; i < other.speciesCount; i++)
    {
        this->storage.push_back(other.storage[i]);
    }
    this->speciesCount = other.speciesCount;
    return *this;
}

bool Engidex::operator%(const Species &x) const
{
    for (int i = 0; i < this->speciesCount; i++)
    {
        if (this->storage[i] == x)
        {
            return true;
        }
    }
    return false;
}

bool Engidex::operator+(Species &newSpecies)
{
    newSpecies.setSpeciesNumber(speciesCount);
    this->storage.push_back(newSpecies);
    speciesCount++;
    return true;
}

Engidex &Engidex::getInstance()
{
    return instance;
}
