#include "lib/Skill.hpp"

int main()
{
    Skill s1;
    vector<Element> elements;
    Skill s2("nama_skill", 100, 50, elements);
    Skill s3(s2);
    cout << "S1 nama : " << s1.getName() << endl;
    s1 = s2;
    cout << "S1(updated) nama : " << s1.getName() << endl;
    cout << "S2 nama : " << s2.getName() << endl;
    cout << "S3 nama : " << s3.getName() << endl;
    cout << "S2 power : " << s2.getPower();
    s2.setPower(25);
    cout << "S2(updated) power = " << s2.getPower();
    s2 = s3;
    cout << "S2(updated2) power = " << s2.getPower();
    bool temp = (s2 == s3);
    cout << temp << endl;
}