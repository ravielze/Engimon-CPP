#include "lib/Engidex.hpp"

int Engidex::SPECIES_PER_PAGE = 10;
Engidex Engidex::instance;

Engidex::Engidex()
{
    this->speciesCount = 0;
    // Ice
    this->operator+(Species("Jason <3 <3 <3", {Element::ICE}, {"gatau", "liat nanti"}));
    this->operator+(Species("Cermin realita", {Element::ICE}, {"move on mas", "dia punya yang lain"}));
    this->operator+(Species("Es kental manis", {Element::ICE}, {"ada lima varian rasa", "rasanya selangit"}));

    // Electric
    this->operator+(Species("Tikus Listrik", {Element::ELECTRIC}, {"hachim hachim", "brrrrr"}));
    this->operator+(Species("Antena", {Element::ELECTRIC}, {"Bad connection", "Lost connection"}));
    this->operator+(Species("Lightning McQueen", {Element::ELECTRIC}, {"Kechaw", "Kechaw Kechaw"}));

    // Fire
    this->operator+(Species("Cans lupus familiaris", {Element::FIRE}, {"guk-guk", "aik-aik", "rilis tubes"}));
    this->operator+(Species("Spark Knight", {Element::FIRE}, {"da-da-da", "uuh-aah"}));
    this->operator+(Species("Grenade Laut", {Element::FIRE}, {"BOOM", "DHUAR", "BLARR"}));

    // Ground
    this->operator+(Species("Penghuni Sekre", {Element::GROUND}, {"gabut itu mindset", "ngapain sok sibuk"}));
    this->operator+(Species("Tubes 3 biji dedline sama", {Element::GROUND}, {"Mana Sempat", "Keburu Telat"}));
    this->operator+(Species("Kaum Rebahan", {Element::GROUND}, {"chaos? apa tu", "rebahan dulu gan", "dedline masih lama, chill."}));

    // Water
    this->operator+(Species("Ikan", {Element::WATER}, {"swimming-swimming", "just keep swimming"}));
    this->operator+(Species("Kutu air", {Element::WATER}, {"Jaga kebersihan kaki", "Kaki jangan lembab"}));
    this->operator+(Species("Bintang Laut", {Element::WATER}, {"https://www.youtube.com/watch?v=DtL_giO-EB8"}));

    // Fire x Electric
    this->operator+(Species("Cuma Keong", {Element::FIRE, Element::ELECTRIC}, {"gaskeun", "keos"}));
    this->operator+(Species("Naga api kesetrum", {Element::FIRE, Element::ELECTRIC}, {"oof", "drrrttt"}));
    this->operator+(Species("Laprak", {Element::FIRE, Element::ELECTRIC}, {"pasti mencetarkan", "perih dan membakar hati"}));

    // Water x Ground
    this->operator+(Species("Belut Batu", {Element::WATER, Element::GROUND}, {"gelud sini", "meliat-liat gmn gt"}));
    this->operator+(Species("Kucing ITB", {Element::WATER, Element::GROUND}, {"bukan kucing biasa", "whiskas mana whiskas"}));
    this->operator+(Species("Buaya Darat", {Element::WATER, Element::GROUND}, {"Sini sama abang", "Abang hanya suka kamu kok"}));

    // Water x Ice
    this->operator+(Species("Alarm", {Element::WATER, Element::ICE}, {"absen sudah dibuka di s*x"}));
    this->operator+(Species("Ekhm Ekhm", {Element::WATER, Element::ICE}, {"https://www.youtube.com/watch?v=dQw4w9WgXcQ"}));
    this->operator+(Species("Kelas basd*t", {Element::WATER, Element::ICE}, {"asumsi kalian sudah mempelajari materi terkait", "kerjakan latihan di s*x"}));
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
        if (speciesStorage[i].getElementCount() >= 2 && (speciesStorage[i] % firstElement && speciesStorage[i] % secondElement))
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

Species Engidex::getSpeciesBySpeciesNumber(int number)
{
    return speciesStorage[number];
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

bool Engidex::operator+(Species newSpecies)
{
    newSpecies.setSpeciesNumber(speciesCount);
    this->speciesStorage.push_back(newSpecies);
    speciesCount++;
    return true;
}

bool Engidex::operator+(SkillItem skill)
{
    this->skillStorage.push_back(skill);
    skillCount++;
    return true;
}

Engidex &Engidex::getInstance()
{
    return instance;
}

// Engimon &Engidex::createRandomEngimon() const
// {
//     srand(time(NULL));
//     int generateRandomExp = rand() % 1500;
//     int idxspesies = rand() % this->speciesCount;
//     Species engimonSpecies = this->speciesStorage[idxspesies];
//     Engimon *engi = new Engimon(engimonSpecies, EntitySource::WILD);

//     engi->addExp(generateRandomExp);

//     return *engi;
// }

Species &Engidex::getRandomSpecies(Element element) const
{
    srand(time(NULL));
    int index = randomInt(0, this->speciesStorage.size() - 1);
    Species x = this->speciesStorage[index];
    return x;
}

SkillItem Engidex::createRandomSkillItem(Element element) const
{
    SkillItem tempItem;
    bool first = true;
    srand(time(NULL));
    for (int i = 0; i < skillCount; i++)
    {
        if (skillStorage[i] % element)
        {
            if (first)
            {
                tempItem = skillStorage[i];
            }
            int random = rand() % 2;
            if (random)
            {
                return skillStorage[i];
            }
        }
    }
    return tempItem;
}