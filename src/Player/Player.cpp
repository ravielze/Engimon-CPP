#include "Player.hpp"

Player::Player()
{
    this->engimonList = Inventory<Engimon>(6);
    this->ItemList = Inventory<SkillItem>(30);
}

void Player::addEngimon(Engimon)
{
}

void Player::removeEngimon(Engimon)
{
}

void move()
{
}

void battle()
{
}

void switchActiveEngimon()
{
}

void interact();
{
}