#include "lib/Player.hpp"

Player::Player()
{
    this->engimonList = Inventory<Engimon>(6);
    this->ItemList = Inventory<SkillItem>(30);
    this->facing = Direction::NORTH;
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
        switchActiveEngimon(engimonList.getItemOnIndex(index));
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