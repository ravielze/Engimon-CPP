#include "lib/Elementum.hpp"
#include "utils.hpp"

int main()
{
    vector<Element> elementVector1;
    //Testing fungsi Elementum (vector<Element> otherElements)
    elementVector1.push_back(Element::FIRE);
    Elementum testElement1(elementVector1);
    testElement1.show();

    //Testing fungsi operator=
    vector<Element> elementVector2;
    elementVector2 = elementVector1;

    //Testing count element
    testElement1.getElementCount();
    elementVector2.push_back(Element::GROUND);

    Elementum testElement2(elementVector2);
    testElement2.getElementCount();
    testElement2.show();
    //Testing total multiplier
    testElement2.getTotalMultiplier(testElement1);

    //Testing fungsi operator ==
    if ((testElement2 == testElement1) == false)
    {
        cout << "Keduanya tidak memiliki jumlah elemen yang sama";
    }
    else
    {
        cout << "Keduanya memiliki jumlah elemen yang sama";
    }

    //Testing operator%(element)
    Element FIRE;
    Elementum testElement3();
    //testElement3 tidak berisi elemen apa-apa
    if (testElement3 % FIRE)
    {
        cout << "operator % salah" << endl;
    }
    else
    {
        cout << "operator % benar" << endl;
    }
    //testElement1 berisi elemen fire
    if (testElement1 % FIRE)
    {
        cout << "operator % benar" << endl;
    }
    else
    {
        cout << "operator % salah" << endl;
    }

    //Testing operator%(const Elementum%)
    Elementum testElement4(elementVector1);
    if (testElement4 % testElement1)
    {
        cout << "operator % benar" << endl;
    }
    else
    {
        cout << "operator % salah" << endl;
    }
}