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

    Point()
    {
        this->x = 5;
        this->y = 20;
        cout << "ctor called" << endl;
    }

    Point(const Point &other)
    {
        cout << "cctor called" << endl;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point &operator=(const Point &other)
    {
        cout << "op= called" << endl;
        this->x = other.x;
        this->y = other.y;
        return *this;
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

Point &something()
{
    cout << "HAA" << endl;
    Point *array = new Point[5];
    return *array;
}

int main()
{
    cout << "TRALALA TRILILI" << endl;
    string a;
    Point x = createPoint(1, 1);
    Point y = x;
    //something();
    //something();
    cout << "TRALALA TRILILI" << endl;
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