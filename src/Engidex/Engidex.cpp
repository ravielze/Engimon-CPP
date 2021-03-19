#include "Engidex.hpp"

int Engidex::SPECIES_PER_PAGE = 10;

Engidex::Engidex()
{
    this->speciesCount = 0;
}

Engidex &Engidex::operator-(const Species &speciesRemoved)
{
}

void Engidex::show(int page) const
{
}

Engidex &Engidex::operator=(const Engidex &)
{
}

bool Engidex::operator%(const Engidex &) const
{
}

Engidex &Engidex::operator+(const Species &newSpecies)
{
    this->storage.push_back(newSpecies);
}
