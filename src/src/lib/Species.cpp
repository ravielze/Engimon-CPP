#include "lib/Species.hpp"
int Species::TAB_COUNT = 1;

Species::Species()
{
    this->speciesNumber = -1;
    this->speciesName = "Unspecified";
    this->message = "";
}

Species::Species(const Species &aspecies) : Elementum(aspecies)
{
    if (aspecies.speciesName.size() != 0)
    {
        this->speciesName = aspecies.speciesName;
    }
    this->speciesNumber = aspecies.speciesNumber;
    this->message = aspecies.message;
}

Species::Species(string name, vector<Element> elem, string message) : Elementum(elem)
{
    this->speciesNumber = -1;
    this->speciesName = name;
    if (this->speciesName.size() / 8 >= TAB_COUNT)
    {
        TAB_COUNT = (this->speciesName.size() + 8) / 8;
    }
    this->message.clear();
    this->message = message;
}

void Species::sendMessage() const
{
    cout << "[" << this->speciesName << "]: " << this->message << endl;
}
string Species::getSpeciesName() const
{
    return this->speciesName;
}

void Species::show() const
{
    cout << this->speciesNumber;
    cout << "\t" << this->speciesName;
    for (int i = 0; i < TAB_COUNT - (this->speciesName.size() / 8); i++)
    {
        cout << "\t";
    }
    Elementum::show();
}

void Species::simpleShow() const
{
    cout << this->speciesName;
    for (int i = 0; i < TAB_COUNT - (this->speciesName.size() / 8); i++)
    {
        cout << "\t";
    }
    Elementum::show();
}

bool Species::operator==(const Species &aspecies) const
{
    return (this->speciesNumber == aspecies.speciesNumber && Elementum::operator==(aspecies));
}

Species &Species::operator=(const Species &aspecies)
{
    Elementum::operator=(aspecies);
    this->speciesNumber = aspecies.speciesNumber;
    this->speciesName = aspecies.speciesName;
    this->message = aspecies.message;
    // this->message.clear();
    // for (int i = 0; i < aspecies.message.size(); i++)
    // {
    //     this->message[i] = aspecies.message[i];
    // }
    return *this;
}

void Species::setSpeciesNumber(int num)
{
    this->speciesNumber = num;
}
