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

public:
    Inventory();

    int getCapacity() const;
    int getMaxCapacity() const;

    // Add item ke inventoryperator+(const T &);
    int operator%(const T &);

    // Remove barang ke inventory
    bool operator-(const T &);

    // Cek jumlah barang di inventory
    bool operator%(const T &);

    // Cek apakah ada atau tidak di inventory
    bool operator/(const T &);
