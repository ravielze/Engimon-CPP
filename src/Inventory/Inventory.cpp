#include <Inventory.hpp>
using namespace std;

template <class T>
class Inventory
{
private:
    map<T, int> storage;
    int maxCapacity;

public:
    Inventory();
    ~Inventory();

    int getCapacity() const;
    int getMaxCapacity() const;
    bool operator<<(const T &);
    bool operator>>(const T &);
    int operator%(const T &);
};