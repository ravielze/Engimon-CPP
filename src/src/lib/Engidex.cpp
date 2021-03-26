#include "lib/Engidex.hpp"

int Engidex::SPECIES_PER_PAGE = 10;
Engidex Engidex::instance;

Engidex::Engidex()
{
    this->speciesCount = 0;
    // Ice
    this->operator+(Species("Jason <3 <3 <3", {Element::ICE}, "gatau"));
    this->operator+(Species("Cermin realita", {Element::ICE}, "move on mas"));
    this->operator+(Species("Es kental manis", {Element::ICE}, "ada lima varian rasa"));

    // Electric
    this->operator+(Species("Tikus Listrik", {Element::ELECTRIC}, "hachim hachim"));
    this->operator+(Species("Antena", {Element::ELECTRIC}, "Bad connection"));
    this->operator+(Species("Lightning McQueen", {Element::ELECTRIC}, "Kechaw Kechaw"));

    // Fire
    this->operator+(Species("Cans lupus familiaris", {Element::FIRE}, "guk guk"));
    this->operator+(Species("Spark Knight", {Element::FIRE}, "da da da"));
    this->operator+(Species("Grenade Laut", {Element::FIRE}, "DHUAR"));

    // Ground
    this->operator+(Species("Penghuni Sekre", {Element::GROUND}, "ngapain sok sibuk"));
    this->operator+(Species("Tubes 3 biji dedline sama", {Element::GROUND}, "Mana Sempat Keburu Telat"));
    this->operator+(Species("Kaum Rebahan", {Element::GROUND}, "chill"));

    // Water
    this->operator+(Species("Ikan", {Element::WATER}, "swimming swimming"));
    this->operator+(Species("Kutu air", {Element::WATER}, "Oink"));
    this->operator+(Species("Bintang Laut", {Element::WATER}, "Patrick"));

    // Fire x Electric
    this->operator+(Species("Cuma Keong", {Element::FIRE, Element::ELECTRIC}, "gaskeun"));
    this->operator+(Species("Naga api kesetrum", {Element::FIRE, Element::ELECTRIC}, "oof"));
    this->operator+(Species("Laprak", {Element::FIRE, Element::ELECTRIC}, "tpb"));

    // Water x Ground
    this->operator+(Species("Belut Batu", {Element::WATER, Element::GROUND}, "gelud sini"));
    this->operator+(Species("Kucing ITB", {Element::WATER, Element::GROUND}, "whiskas mana"));
    this->operator+(Species("Buaya Darat", {Element::WATER, Element::GROUND}, "Abangg"));

    // Water x Ice
    this->operator+(Species("Alarm", {Element::WATER, Element::ICE}, "absen sudah dibuka"));
    this->operator+(Species("Ekhm Ekhm", {Element::WATER, Element::ICE}, "https://www.youtube.com/watch?v=dQw4w9WgXcQ"));
    this->operator+(Species("Kelas basd*t", {Element::WATER, Element::ICE}, "asumsi kalian sudah mempelajari materi terkait"));

    // Add skill SkillItem(string itemName, Skill skill, ItemType it);
    // Ice
    this->operator+(SkillItem("Tergelincir es", Skill("Tergelincir Es", 1, {Element::ICE}), ItemType::HM));
    this->operator+(SkillItem("Email asisten st*ma", Skill("Email asisten st*ma", 1, {Element::ICE}), ItemType::HM));
    this->operator+(SkillItem("Terserah kamu aja", Skill("Terserah kamu aja", 2, {Element::ICE}), ItemType::HM));
    this->operator+(SkillItem("Tatapan dingin", Skill("Tatapan dingin", 2, {Element::ICE}), ItemType::HM));
    this->operator+(SkillItem("Penenggelam Titanic", Skill("Penenggelam Titanic", 3, {Element::ICE}), ItemType::HM));
    this->operator+(SkillItem("Molding type: Ice Bridge", Skill("Molding type: Ice Bridge", 3, {Element::ICE}), ItemType::HM));

    // Electric
    this->operator+(SkillItem("Rolling Thunder", Skill("Rolling Thunder", 1, {Element::ELECTRIC}), ItemType::HM));
    this->operator+(SkillItem("Aliran singkat", Skill("Aliran singkat", 1, {Element::ELECTRIC}), ItemType::HM));
    this->operator+(SkillItem("Driving Thunder", Skill("Driving Thunder", 2, {Element::ELECTRIC}), ItemType::HM));
    this->operator+(SkillItem("Colokan listrik", Skill("Colokan listrik", 2, {Element::ELECTRIC}), ItemType::HM));
    this->operator+(SkillItem("Thunder Apocalypse", Skill("Thunder Apocalypse", 3, {Element::ELECTRIC}), ItemType::HM));
    this->operator+(SkillItem("Ara ara shock", Skill("Ara ara shock", 3, {Element::ELECTRIC}), ItemType::HM));

    // Fire
    this->operator+(SkillItem("Semprotan Api", Skill("Semprotan Api", 1, {Element::FIRE}), ItemType::HM));
    this->operator+(SkillItem("Mata Api", Skill("Mata Api", 1, {Element::FIRE}), ItemType::HM));
    this->operator+(SkillItem("Hell Fire", Skill("Hell Fire", 2, {Element::FIRE}), ItemType::HM));
    this->operator+(SkillItem("Fluter By", Skill("Fluter By", 2, {Element::FIRE}), ItemType::HM));
    this->operator+(SkillItem("Baron Bunny", Skill("Baron Bunny", 3, {Element::FIRE}), ItemType::HM));
    this->operator+(SkillItem("Jumpty Dumpty", Skill("Jumpty Dumpty", 3, {Element::FIRE}), ItemType::HM));

    // Ground
    this->operator+(SkillItem("Goyangan Albedo", Skill("Goyangan Albedo", 1, {Element::GROUND}), ItemType::HM));
    this->operator+(SkillItem("Batu jatoh", Skill("Batu jatoh", 1, {Element::GROUND}), ItemType::HM));
    this->operator+(SkillItem("Tiang Batu", Skill("Tiang Batu", 2, {Element::GROUND}), ItemType::HM));
    this->operator+(SkillItem("Rock Throw", Skill("Rock Throw", 2, {Element::GROUND}), ItemType::HM));
    this->operator+(SkillItem("Bumi bergetar", Skill("Bumi bergetar", 3, {Element::GROUND}), ItemType::HM));
    this->operator+(SkillItem("Tendou Banshou", Skill("Tendou Banshou", 3, {Element::GROUND}), ItemType::HM));

    // Water
    this->operator+(SkillItem("Splash splash", Skill("Splash splash", 1, {Element::WATER}), ItemType::HM));
    this->operator+(SkillItem("Swimming swimming", Skill("Swimming swimming", 1, {Element::WATER}), ItemType::HM));
    this->operator+(SkillItem("Siraman rohani", Skill("Siraman rohani", 2, {Element::WATER}), ItemType::HM));
    this->operator+(SkillItem("Gelembung air", Skill("Gelembung air", 2, {Element::WATER}), ItemType::HM));
    this->operator+(SkillItem("Siraman Oceanid", Skill("Siraman Oceanid", 3, {Element::WATER}), ItemType::HM));
    this->operator+(SkillItem("Barbara Beam", Skill("Barbara Beam", 3, {Element::WATER}), ItemType::HM));
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
    vector<Species> sameElement;
    for (Species t : this->speciesStorage)
    {
        if (t % element)
        {
            sameElement.push_back(t);
        }
    }
    int index = randomInt(0, sameElement.size() - 1);
    return sameElement[index];
}

Species &Engidex::getRandomSpecies(Element element, Element element2) const
{
    vector<Species> sameElement;
    for (Species t : this->speciesStorage)
    {
        if (t % element && t % element2)
        {
            sameElement.push_back(t);
        }
    }
    int index = randomInt(0, sameElement.size() - 1);
    return sameElement[index];
}

SkillItem Engidex::createRandomSkillItem(Element element) const
{
    SkillItem tempItem;
    bool first = true;
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