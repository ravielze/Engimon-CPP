#include "lib/Player.hpp"

Player::Player()
{
    cout << "Hello there! Welcome to the world of engimon! \n";
    cout << "My name is Cemara! People call me the engimon Prof! \n";
    cout << "This world is inhabited by creatures called engimon! For some people, engimon are blessing :). \n";
    cout << "Others use them for fights. Myself...I study engimon just for fun, obviously.\n";
    this->engimonList = Inventory<Engimon>(6);
    this->ItemList = Inventory<SkillItem>(30);
    cout << "There are 3 Engimon here! Haha! They are inside the Engi Balls.\n";
    cout << "When I was young, I was a serious Engimon trainer! In my old age, I only have 3 left, but you can have one! Choose!\n";
    int index = -1;
    while (index < 1 || index > 6)
    {
        cout << "1.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(0).simpleShow();
        cout << endl;
        cout << "2.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(3).simpleShow();
        cout << endl;
        cout << "3.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(6).simpleShow();
        cout << endl;
        cout << "4.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(9).simpleShow();
        cout << endl;
        cout << "5.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(12).simpleShow();
        cout << endl;
        cout << "6.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(15).simpleShow();
        cout << endl
             << "Pick Number: ";
        cin >> index;
    }
    cout << endl;
    Species starterSpecies;
    starterSpecies = Engidex::getInstance().getSpeciesBySpeciesNumber((index - 1) * 3);
    Engimon starter = Engimon(starterSpecies, EntitySource::WILD);
    starter.show();
    cout << endl;
    this->engimonList + starter;
}

Engimon Player::getActiveEngimon()
{
    return this->activeEngimon;
}

void Player::addEngimon(Engimon Engi)
{
    this->engimonList = this->engimonList + Engi;
}

void Player::removeEngimon(Engimon Engi)
{
    this->engimonList = this->engimonList - Engi;
}

bool Player::battle(Engimon wildEngimon)
{
    try
    {
        Engimon engimon = activeEngimon * wildEngimon;
        // Engimon kita menang
        cout << "You have won the battle" << endl;
        cout << "Here is the wild engimon as a reward for you : " << endl;
        engimon.show();
        bool canAdd = engimonList + engimon;

        if (!canAdd)
        {
            cout << "Oops your engimon inventory is full" << endl;
        }
        // TODO : Generate random skill item
        SkillItem item = Engidex::getInstance().createRandomSkillItem(wildEngimon.getFirstElement());
        if (!ItemList.isFull())
        {
            cout << "You got an extra skill item for defeating wild engimon" << endl;
            this->ItemList + item;
        }
        else
        {
            cout << "Inventory udh full hehe" << endl;
        }
        return true;
    }
    catch (Exception e)
    {
        // Engimon kita mati

        cout << "Cacad engimon lu..." << endl;
        bool canRemove = engimonList - activeEngimon;
        switchActiveEngimon();
        return false;
    }
}

void Player::switchActiveEngimon()
{
    showEngimon();
    cout << "Engimon number to switch : " << endl;
    int index;
    cin >> index;

    this->activeEngimon = engimonList.getItemOnIndex(index - 1);
}

void Player::learn()
{
    int engimonIndex;
    showEngimon();
    cout << "Choose Engimon : ";
    cin >> engimonIndex;
    cout << endl;
    int skillIndex;
    showSkillItem();
    cout << "Choose Skill Item: ";
    cin >> skillIndex;
    cout << endl;

    Engimon chosenEngimon = engimonList.getItemOnIndex(engimonIndex);
    SkillItem chosenSkillItem = ItemList.getItemOnIndex(skillIndex);
    this->engimonList - chosenEngimon;
    try
    {
        chosenEngimon.learn(chosenSkillItem);
        // Berhasil learn
        this->ItemList - chosenSkillItem;
    }
    catch (Exception e)
    {
        // Engimon gabisa learn skill
        cout << "Skill item that you chose is not compatible with the engimon" << endl;
    }
    this->engimonList + chosenEngimon;
}

void Player::breed()
{
    if (this->engimonList.isFull())
    {
        cout << "Slot engimon sudah penuh" << endl;
        return;
    }
    int parentAIndex;
    int parentBIndex;
    showEngimon();
    cout << "Parent A Index : ";
    cin >> parentAIndex;
    cout << endl;
    cout << "Parent B Index : ";
    cin >> parentBIndex;
    cout << endl;
    Engimon parentA = this->engimonList.getItemOnIndex(parentAIndex);
    Engimon parentB = this->engimonList.getItemOnIndex(parentBIndex);
    this->engimonList - parentA;
    this->engimonList - parentB;
    try
    {
        Engimon baby = parentA + parentB;
        this->engimonList + baby;
    }
    catch (Exception e)
    {
        cout << "Engimon belum cukup level untuk melakukan breeding" << endl;
    }

    this->engimonList + parentA;
    this->engimonList + parentB;
}

void Player::interact()
{
    this->activeEngimon.sendMessage();
}

void Player::showEngimon()
{
    engimonList.show(1);
}

void Player::showSkillItem()
{
    ItemList.show(1);
    // TODO : Show semua, ini baru sebagian aja
}
