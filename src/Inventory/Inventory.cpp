#include "Inventory.hpp"

template <class T>
int Inventory<T>::ITEM_PER_PAGE = 10;

template <class T>
Inventory<T>::Inventory(int maxsize)
{
    this->maxCapacity = maxsize;
}

template <class T>
int Inventory<T>::getCapacity() const
{
    return this->storage.size();
}

template <class T>
int Inventory<T>::getMaxCapacity() const
{
    return this->maxCapacity;
}

template <class T>
bool Inventory<T>::operator+(const T &Item)
{
    // Apabila storage masih mempunyai stage
    if (storage.getCapacity() < this->maxCapacity)
    {
        // Item belum ada di inventory
        if (this->storage.find(Item) == this->storage.end())
        {
            this->storage.insert({Item, 1});
        }
        // Item sudah terdaftar di inventory
        else
        {
            int jml = this->storage[Item];
            jml++;
            this->storage[Item] = jml;
        }
        return true;
    }
    return false;
}

template <class T>
bool Inventory<T>::operator-(const T &Item)
{
    // Item belum terdapat di inventory
    if (this->storage.find(Item) == this->storage.end())
    {
        return false;
    }
    int jml = this->storage[Item];
    jml--;
    this->storage[Item] = jml;
    return true;
}

template <class T>
int Inventory<T>::operator%(const T &Item)
{
    // Item belum terdapat di inventory
    if (this->storage.find(Item) == this->storage.end())
    {
        return 0;
    }

    return this->storage[Item];
}

template <class T>
bool Inventory<T>::operator^(const T &Item)
{
    // Item belum terdapat di inventory
    if (this->storage.find(Item) == this->storage.end())
    {
        return false;
    }
    return true;
}

template <class T>
void Inventory<T>::show(int page) const
{
    // Apabila terdapat item di inventory
    if (this->storage.size() > 0 && page >= 1)
    {
        int start = (page - 1) * ITEM_PER_PAGE;
        int end = page * ITEM_PER_PAGE;
        map<T, int>::iterator itr;
        int i = 0;
        int size = this->getCapacity();
        for (itr = this->storage.begin(); itr != this->storage.end(); itr++)
        {
            if (i < end && i >= start && i < size)
            {
                if (is_same<T, SkillItem>::value || is_same<T, Engimon>::value)
                {
                    cout << itr->first.show() << " x" << itr->second;
                }
                else
                {
                    cout << itr->first << " x" << itr->second;
                }
            }
            else if (i >= end)
            {
                break;
            }
            i++;
        }
    }
}
template <class T>
Inventory<T>::Inventory()
{
    this->maxCapacity = 0;
}
