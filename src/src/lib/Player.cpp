#include "lib/Player.hpp"

Player::Player()
{
    cout << "Hello there! Welcome to the world of engimon! \n";
    cout << "My name is Cemara! People call me the engimon Prof! \n";
    cout << "This world is inhabited by creatures called engimon! For some people, engimon are blessing :). \n";
    cout << "Others use them for fights. Myself...I study engimon just for fun, obviously.\n";
    this->engimonList = Inventory<Engimon>(6);
    this->ItemList = Inventory<SkillItem>(30);
    this->facing = Direction::NORTH;
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
        cin >> index;
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

void Player::battle(Engimon wildEngimon)
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
    }
    catch (Exception e)
    {
        // Engimon kita mati

        cout << "Cacad engimon lu..." << endl;
        bool canRemove = engimonList - activeEngimon;

        // Show engimon list
        engimonList.show(1);

        // Pilih engimon untuk diganti
        int index;
        cout << "Choose engimon index to replace : ";
        cin >> index;
        // switchActiveEngimon(engimonList.getItemOnIndex(index));
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

void Player::switchActiveEngimon(Engimon engi)
{
    if (this->engimonList ^ engi)
    {
        this->activeEngimon = engi;
    }
    else
    {
        throw Exception::UNKNOWN_ENGIMON;
    }
}

void Player::interact()
{
    this->activeEngimon.sendMessage();
}

void Player::setDirection(Direction direct)
{
    this->facing = direct;
}

Direction Player::getDirection() const
{
    return this->facing;
}