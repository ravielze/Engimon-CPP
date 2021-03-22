#include "lib/Engidex.hpp"

int Engidex::SPECIES_PER_PAGE = 10;

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
    this->storage.push_back(newSpecies);
    newSpecies.setSpeciesNumber(speciesCount);
    speciesCount++;
    return true;
}
