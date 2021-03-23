#include "lib/Inventory.hpp"

int main()
{

    Species randomPokemon("random", {Element::FIRE, Element::ELECTRIC});
    Species lanturn("Lanturn", {Element::FIRE, Element::ELECTRIC});
    Species pikachu("Pikachu", {Element::ELECTRIC, Element::GROUND});

    Engimon myLanturn(lanturn, EntitySource::WILD, "mylanturn");
    Engimon myPikachu(pikachu, EntitySource::WILD);

    Inventory<Engimon> engimonInventory(10);

    engimonInventory + myLanturn;
    engimonInventory + myPikachu;

    engimonInventory.show(1);
    //     I1 + 5;
    //     I1 + 3;
    //     I1 + 2;
    //     I1 + 3;
    //     I1 + 3;
    //     cout << "Kapasitas sekarang : " << I1.getCapacity() << endl;
    //     I1.show(1);

    //     I1 - 5;
    //     I1 - 3;
    //     cout << "Kapasitas sekarang : " << I1.getCapacity() << endl;
    //     I1.show(1);

    //     I1 % 5;
    //     I1 % 3;

    //     I1 ^ 5;
    //     I1 ^ 3;
    //
}