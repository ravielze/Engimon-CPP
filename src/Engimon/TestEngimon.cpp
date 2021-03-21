#include "Engimon.hpp"
using namespace std;
int main ()
{
    vector<Element> lanturnElement = {Element::WATER, Element::ELECTRIC};
    Species lanturn ("Lanturn", lanturnElement);
    lanturn.sendMessage();
}