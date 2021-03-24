#include <iostream>
using namespace std;
class Point
{
public:
    int x, y;
    void show()
    {
        cout << "(" << x << "," << y << ")";
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    ~Point()
    {
        cout << "destructor called "
             << "(" << x << "," << y << ")" << endl;
    }
};

Point &createPoint(int x, int y)
{
    Point *created = new Point(x, y);
    cout << "HEHEHE" << endl;
    return *created;
}

int main()
{
    Point test = createPoint(1, 1);
    Point test2 = createPoint(5, 1);
    Point test3 = createPoint(1, 2);
    cout << "TRALALA TRILILI" << endl;
    string a;
    while (1)
    {
        cin >> a;
        if (a == "exit")
        {
            break;
        }
    }
    return 0;
}