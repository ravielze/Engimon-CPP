#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include <iostream>
#include <map>
using namespace std;

template <class T>
class Inventory
{
private:
    map<T, int> storage;
    int maxCapacity;
    static int ITEM_PER_PAGE;

public:
    Inventory();
    Inventory(int maxsize);

    int getCapacity() const;
    int getMaxCapacity() const;

    // Add item ke inventoryperator+(const T &);
    bool operator+(const T &);

    // Remove barang dari inventory
    bool operator-(const T &);

    // Cek jumlah barang di inventory
    int operator%(const T &);

    // Cek apakah ada atau tidak di inventory
    bool operator^(const T &);

    // Menunjukkan barang di inventory
    void show(int page) const;
};
#endif // __INVENTORY_H__