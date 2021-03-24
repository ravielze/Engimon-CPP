#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include <iostream>
#include <type_traits>
#include <map>
#include "SkillItem.hpp"
#include "Engimon.hpp"
using namespace std;

template <typename T>
class Inventory
{
private:
    map<T, int> storage;
    int maxCapacity;
    static int ITEM_PER_PAGE;

public:
    Inventory()
    {
        this->maxCapacity = 0;
    }

    Inventory(int maxsize)
    {
        this->maxCapacity = maxsize;
    }

    int getCapacity() const
    {
        return this->storage.size();
    }
    int getMaxCapacity() const
    {
        return this->maxCapacity;
    }

    // Add item ke inventoryperator+(const T &);
    bool operator+(const T &i)
    {
        // Apabila storage masih mempunyai stage
        if (this->getCapacity() < this->maxCapacity)
        {
            // Item belum ada di inventory
            if (this->storage.find(i) == this->storage.end())
            {
                this->storage.insert({i, 1});
            }
            // item sudah terdaftar di inventory
            else
            {
                int jml = this->storage[i];
                jml++;
                this->storage[i] = jml;
            }
            return true;
        }
        return false;
    }

    // Remove barang dari inventory
    bool operator-(const T &i)
    {
        // Item belum terdapat di inventory
        if (this->storage.find(i) == this->storage.end())
        {
            return false;
        }
        int jml = this->storage[i];
        jml--;
        this->storage[i] = jml;
        return true;
    }

    // Cek jumlah barang di inventory
    int operator%(const T &i)
    {
        // Item belum terdapat di inventory
        if (this->storage.find(i) == this->storage.end())
        {
            return 0;
        }

        return this->storage[i];
    }

    // Cek apakah ada atau tidak di inventory
    bool operator^(const T &i)
    {
        // Item belum terdapat di inventory
        if (this->storage.find(i) == this->storage.end())
        {
            return false;
        }
        return true;
    }

    // Menunjukkan barang di inventory
    void show(int page) const;
    T getItemOnIndex(int index) const;
};

template <typename T>
int Inventory<T>::ITEM_PER_PAGE = 10;

template <typename T>
void Inventory<T>::show(int page) const
{
}

template <typename T>
T Inventory<T>::getItemOnIndex(int index) const
{
    auto itr = this->storage.begin();
    itr += index;

    return itr->first;
}

template <>
void Inventory<int>::show(int page) const
{
    if (this->storage.size() > 0 && page >= 1)
    {
        int start = (page - 1) * ITEM_PER_PAGE;
        int end = page * ITEM_PER_PAGE;
        int i = 0;
        int size = this->getCapacity();
        for (auto itr = this->storage.begin(); itr != this->storage.end(); itr++)
        {
            if (i < end && i >= start && i < size)
            {
                cout << itr->first << " x" << itr->second;
            }
            else if (i >= end)
            {
                break;
            }
            i++;
            cout << endl;
        }
    }
    cout << endl;
}

template <>
void Inventory<SkillItem>::show(int page) const
{
    if (this->storage.size() > 0 && page >= 1)
    {
        int start = (page - 1) * ITEM_PER_PAGE;
        int end = page * ITEM_PER_PAGE;
        int i = 0;
        int size = this->getCapacity();
        for (auto itr = this->storage.begin(); itr != this->storage.end(); itr++)
        {
            if (i < end && i >= start && i < size)
            {
                itr->first.show();
                cout << " x" << itr->second;
            }
            else if (i >= end)
            {
                break;
            }
            i++;
            cout << endl;
        }
    }
}

template <>
void Inventory<Engimon>::show(int page) const
{
    if (this->storage.size() > 0 && page >= 1)
    {
        int start = (page - 1) * ITEM_PER_PAGE;
        int end = page * ITEM_PER_PAGE;
        int i = 0;
        int size = this->getCapacity();
        for (auto itr = this->storage.begin(); itr != this->storage.end(); itr++)
        {
            if (i < end && i >= start && i < size)
            {
                itr->first.Species::show();
                cout << " x" << itr->second;
            }
            else if (i >= end)
            {
                break;
            }
            i++;
            cout << endl;
        }
    }
}

#endif // __INVENTORY_H__