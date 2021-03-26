#include "lib/Species.hpp"
int Species::TAB_COUNT = 1;

Species::Species() : message(vector<string>(0))
{
    this->speciesNumber = -1;
    this->speciesName = "";
}

Species::Species(const Species &aspecies) : Elementum(aspecies)
{
    this->speciesNumber = aspecies.speciesNumber;
    this->speciesName = aspecies.speciesName;
    if (aspecies.message.capacity() > 0)
    {
        this->message = vector<string>(aspecies.message);
    }
}

Species::Species(string name, vector<Element> elem, vector<string> messages) : Elementum(elem)
{
    this->speciesNumber = -1;
    this->speciesName = name;
    if (this->speciesName.size() > TAB_COUNT * 8)
    {
        TAB_COUNT = (this->speciesName.size() + 8) / 8;
    }
    if (messages.capacity() > 0)
    {
        this->message = messages;
    }
}

void Species::sendMessage() const
{
    if (this->message.empty())
    {
        cout << "[" << this->speciesName << "]: hmmm" << endl;
        return;
    }
    int randomIdx;
    randomIdx = rand() % this->message.size();
    cout << "[" << this->speciesName << "]: " << this->message[randomIdx] << endl;
}
string Species::getSpeciesName() const
{
    return this->speciesName;
}

void Species::show() const
{
    cout << this->speciesNumber;
    cout << "\t" << this->speciesName;
    for (int i = 0; i < TAB_COUNT; i++)
    {
        cout << "\t";
    }
    Elementum::show();
}

void Species::simpleShow() const
{
    cout << this->speciesName << "\t";
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
    if (aspecies.message.size() > 0)
    {
        this->message = vector<string>(aspecies.message);
    }
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
