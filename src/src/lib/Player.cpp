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
    while (index < 1 || index > 3)
    {
        cout << "1.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(0).simpleShow();
        cout << endl;
        cout << "2.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(3).simpleShow();
        cout << endl;
        cout << "3.\t";
        Engidex::getInstance().getSpeciesBySpeciesNumber(6).simpleShow();
        cout << endl
             << "Pick Number: ";
        //cin >> index;
        index = 3;
    }
    cout << endl;
    Species starterSpecies;
    if (index == 1)
    {
        starterSpecies = Engidex::getInstance().getSpeciesBySpeciesNumber(0);
    }
    else if (index == 2)
    {
        starterSpecies = Engidex::getInstance().getSpeciesBySpeciesNumber(3);
    }
    else if (index == 3)
    {
        starterSpecies = Engidex::getInstance().getSpeciesBySpeciesNumber(6);
    }
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
    // pake method battle dari engimon jgn lupa try catch dri battle

    // if (myEngimon.getPower(myEngimon.getElements()) > wildEngimon.getPower(wildEngimon.getElements()))
    // {
    //     addEngimon(wildEngimon);
    //     myEngimon.addExp(100);
    //     // dapat random skill item yang kompatibel dengan elemen wildEngimon
    // }
    // else
    // {
    //     // engimon kita mati
    //     // dapat memilih engimon active baru
    // }
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
