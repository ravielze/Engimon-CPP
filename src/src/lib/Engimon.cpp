#include "lib/Engimon.hpp"

int Engimon::MAX_SKILL = 4;
int Engimon::MAX_CUM_EXP = 10000;

Engimon::Engimon() : livingSource(EntitySource::UNKNOWN), parent(pair<string, string>("", ""))
{
    this->level = 1;
    this->exp = 0;
    this->cum_exp = 0;
}

Engimon::Engimon(const Engimon &engimon) : Species(engimon), livingSource(engimon.livingSource), parent(pair<string, string>("", ""))
{
    Species::operator=(engimon);
    this->name = engimon.name;
    this->parent.first = engimon.parent.first;
    this->parent.second = engimon.parent.second;
    this->level = engimon.level;
    this->exp = engimon.exp;
    this->cum_exp = engimon.cum_exp;
    this->skills = vector<Skill>(engimon.skills);
}

Engimon::Engimon(Species &s, EntitySource es) : Species(s), livingSource(es), parent(pair<string, string>("", ""))
{
    this->level = 1;
    this->exp = 0;
    this->cum_exp = 0;
    this->name = s.getSpeciesName();
}

Engimon::Engimon(Species &s, EntitySource es, string name) : Species(s), livingSource(es), parent(pair<string, string>("", ""))
{
    this->level = 1;
    this->exp = 0;
    this->cum_exp = 0;
    this->name = name;
}

//Operator Assignment
Engimon &Engimon::operator=(const Engimon &engimon)
{
    Species::operator=(engimon);
    this->name = engimon.name;
    this->parent.first = engimon.parent.first;
    this->parent.second = engimon.parent.second;
    this->level = engimon.level;
    this->exp = engimon.exp;
    this->cum_exp = engimon.cum_exp;
    this->skills = vector<Skill>(engimon.skills);

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

    while (exp >= level)
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
    cout << endl;
    if (this->name != this->speciesName)
    {
        cout << "Name \t: " << name << endl;
    }
    cout << "Engimon Source : " << convertEntitySourceToString(this->getEntitySource()) << endl;
    if (this->getEntitySource() == EntitySource::BREEDING)
    {
        cout << "First parent : " << this->parent.first << endl;
        cout << "Second parent : " << this->parent.second << endl;
    }
    cout << "Skills : " << endl;
    for (int i = 0; i < skills.size(); i++)
    {
        cout << skills[i].getName() << "\t" << skills[i].getPower() << endl;
    }
}

double Engimon::getPower(const Elementum &other)
{
    double totalSkillPower = 0;
    for (int i = 0; i < skills.size(); i++)
    {
        totalSkillPower += skills[i].getPower() * skills[i].getMasteryLevel();
    }

    return totalSkillPower + level * this->getTotalMultiplier(other);
}

int Engimon::getLevel() const
{
    return this->level;
}

void Engimon::setFirstParent(string name)
{
    this->parent.first = name;
}

void Engimon::setSecondParent(string name)
{
    this->parent.second = name;
}

vector<Skill> Engimon::getSkills() const
{
    return this->skills;
}

// Untuk breeding, this dengan engimon lain, result = anak
Engimon Engimon::operator+(const Engimon &other) const
{
    if (this->getLevel() < 30 || other.getLevel() < 30)
    {
        throw Exception::ENGIMON_CANT_BREED;
    }

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
        for (int j = parentASkills.size() - 1; j >= 0; j--)
        {
            if (parentASkills[j].getMasteryLevel() >= parentAMaxMastery)
            {
                parentAMaxMastery = parentASkills[j].getMasteryLevel();
                parentASlot = j;
            }
        }
        for (int j = parentBSkills.size() - 1; j >= 0; j--)
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
            for (int j = 0; j < toCheck.size(); j++)
            {
                if (toCheck[j] == choosen)
                {
                    if (toCheck[j].getMasteryLevel() == choosen.getMasteryLevel()) // poin 5.d.ii.2
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
    Species childSpecies;
    if (this->getElementCount() > 1)
    {
        if (elementManager.getMultiplier(this->getFirstElement(), this->getSecondElement()) > elementManager.getMultiplier(this->getSecondElement(), this->getFirstElement()))
        {
            parentAElement = this->getFirstElement();
        }
        else
        {
            parentAElement = this->getSecondElement();
        }
    }
    else
    {
        parentAElement = this->getFirstElement();
    }

    if (other.getElementCount() > 1)
    {
        if (elementManager.getMultiplier(other.getFirstElement(), other.getSecondElement()) > elementManager.getMultiplier(other.getSecondElement(), other.getFirstElement()))
        {
            parentAElement = other.getFirstElement();
        }
        else
        {
            parentAElement = other.getSecondElement();
        }
    }
    else
    {
        parentAElement = other.getFirstElement();
    }

    if (parentAElement == parentBElement)
    {
        childSpecies = Engidex::getInstance().getSpeciesByString(this->getSpeciesName()); // Ini bisa diganti. Baca point 5.e.1
    }
    else if (elementManager.getMultiplier(parentAElement, parentBElement) == elementManager.getMultiplier(parentBElement, parentAElement)) // point 5.e.3
    {
        childSpecies = Engidex::getInstance().getDualElementEngimon(parentAElement, parentBElement);
    }
    else // point 5.e.2
    {
        if (elementManager.getMultiplier(parentAElement, parentBElement) > elementManager.getMultiplier(parentBElement, parentAElement))
        {
            childSpecies = Engidex::getInstance().getSpeciesByString(this->getSpeciesName());
        }
        else
        {
            childSpecies = Engidex::getInstance().getSpeciesByString(other.getSpeciesName());
        }
    }
    cout << childSpecies.getSpeciesName() << endl;
    string name;
    cout << "Masukkan nama untuk anak : ";
    cin >> name;
    Engimon child(childSpecies, EntitySource::BREEDING, name);
    for (int i = 0; i < choosenSkills.size(); i++)
    {
        child << choosenSkills[i];
    }
    child.setFirstParent(this->getName());
    child.setSecondParent(other.getName());
    // TODO : Kurangi level engimon sebesar 30

    // Set level engimon

    return child;
}

// Untuk battle;
Engimon &Engimon::operator*(Engimon &other)
{
    double ourPower = this->getPower(other);
    double otherPower = other.getPower(*this);
    if (ourPower >= otherPower) // Kita menang
    {
        this->addExp(other.cum_exp * 0.3); // Masih statik exp yang didapatkan
        return other;
    }
    else // Musuh menang
    {
        throw Exception::ENGIMON_LOST_BATTLE;
    }
}

void Engimon::learn(const SkillItem &skill)
{
    SkillItem si = skill;
    bool canLearn = Elementum::operator%(si);
    if (!canLearn)
    {
        throw Exception::CANNOT_LEARN_SKILL;
    }
    canLearn = Engimon::operator<<(si);
    if (!canLearn)
    {
        throw Exception::CANNOT_LEARN_SKILL;
    }
}

//Untuk buang skill pada slot ...;

//Untuk nambah skill;
bool Engimon::operator<<(Skill &skill)
{
    if (this->skills.size() < Engimon::MAX_SKILL)
    {
        for (int i = 0; i < this->skills.size(); i++)
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
        int slot;
        cout << "Mengganti skill di slot : ";
        cin >> slot;
        this->skills[slot] = skill;
        return true;
    }
}

bool Engimon::operator>(const Engimon &other) const
{
    return false; //|| this->speciesName > other.speciesName;
}

bool Engimon::operator<(const Engimon &other) const
{
    return false; //|| this->speciesName < other.speciesName;
}