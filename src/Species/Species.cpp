#include "Species.hpp"

Species::Species()
{
    this->speciesNumber = -1;
    this->speciesName = "";
}

Species::Species(const Species &aspecies)
{
    this->speciesNumber = aspecies.speciesNumber;
    this->speciesName = aspecies.speciesName;
    for (int i = 0; i < aspecies.message.size(); i++)
    {
        this->message[i] = aspecies.message[i];
    }
}

Species::Species(string name, vector<Element> elements) : Elementum(elements)
{
    this->speciesNumber = -1;
    this->speciesName = name;
}

void Species::sendMessage() const
{
    int randomIdx;
    randomIdx = rand() % this->message.size();
    cout << this->speciesName << " says :" << this->message[randomIdx] << endl;
}

void Species::show() const
{
    cout << "Number : " << this->speciesNumber << endl;
    cout << "Name : " << this->speciesName << endl;
    Elementum::show();
}

bool Species::operator==(const Species &aspecies) const
{
    return (this->speciesNumber == aspecies.speciesNumber && Elementum::operator==(aspecies.elements));
}

Species &Species::operator=(const Species &aspecies)
{
    Elementum::operator=(aspecies);
    this->speciesNumber = aspecies.speciesNumber;
    this->speciesName = aspecies.speciesNumber;
    this->message.clear();
    for (int i = 0; i < aspecies.message.size(); i++)
    {
        this->message[i] = aspecies.message[i];
    }
    return *this;
}

void Species::setSpeciesNumber(int num)
{
    this->speciesNumber = num;
}