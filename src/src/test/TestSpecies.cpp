#include "lib/Species.hpp"

int main()
{
    vector<Element> lanturnElement;
    lanturnElement.push_back(Element::FIRE);
    Species lanturn("Lanturn", lanturnElement);

    //test fungsi show()
    lanturn.show();

    //test setSpeciesNumber dan operator ==
    vector<Element> minumElement;
    minumElement.push_back(Element::FIRE);
    Species minum("Minum", minumElement);

    lanturn.setSpeciesNumber(201);
    minum.setSpeciesNumber(201);

    if (lanturn == minum)
    {
        cout << "Sama loh" << endl;
    }
    else
    {
        cout << "Tidak sama hiks" << endl;
    }

    //Test copy constructor
    Species plusum(minum);
    plusum.show();
}
