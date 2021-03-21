#include "Player.hpp"

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

void Player::battle(Engimon myEngimon, Engimon wildEngimon)
{
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