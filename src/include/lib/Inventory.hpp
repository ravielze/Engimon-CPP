#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include <iostream>
#include <type_traits>
#include <map>
#include "lib/SkillItem.hpp"
#include "lib/Engimon.hpp"
using namespace std;

template <typename T>
class Inventory
{
private:
    map<T, int> storage;
    int maxCapacity;
    int size;
    static int ITEM_PER_PAGE;

public:
    Inventory()
    {
        this->maxCapacity = 0;
        this->size = 0;
    }

    Inventory(int maxsize)
    {
        this->maxCapacity = maxsize;
        this->size = 0;
    }

    int getCapacity() const
    {
        return this->size;
    }
    int getMaxCapacity() const
    {
        return this->maxCapacity;
    }

    // Add item ke inventoryperator+(const T &);
    bool operator+(const T &i)
    {
        // Apabila storage masih mempunyai space
        if (this->getCapacity() < this->maxCapacity)
        {
            this->size++;
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
        if (jml > 0)
        {
            this->storage[i] = jml;
        }
        else
        {
            this->storage.erase(i);
        }
        this->size--;
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
    T getItemOnIndex(int index)
    {
        auto itr = storage.begin();
        advance(itr, index);
        return itr->first;
    }
};

#endif // __INVENTORY_H__