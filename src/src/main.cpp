#include <iostream>
#include <vector>
using namespace std;

// int main()
// {
//     srand(time(NULL));
//     string s;
//     while (true)
//     {
//         int a = rand();
//         int b = rand();
//         int c = (a ^ b) % 101;
//         cout << c << endl;
//     }
// }
// using namespace std;
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
        this->x = other.x;
        this->y = other.y;
        cout << "cctor called" << endl;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        cout << "uctor called" << endl;
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

Point &getItemOnIndex(vector<Point> array, int index)
{
    return array[index];
}

void showArray(vector<Point> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        array[i].show();
        cout << endl;
    }
}

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
    // cout << "TRALALA TRILILI" << endl;
    // vector<Point> v;
    // Point x = createPoint(3, 3);
    // v.push_back(x);
    // x.x = 5;
    // x.show();
    // v[0].show();
    // //something();
    // //something();
    // cout << "TRALALA TRILILI" << endl;
    // string a;
    // while (1)
    // {
    //     cin >> a;
    //     if (a == "exit")
    //     {
    //         break;
    //     }
    // }
    // return 0;
    vector<Point> arrayPoint = {Point(1, 2),
                                Point(2, 3),
                                Point(4, 5)};
    showArray(arrayPoint);
}