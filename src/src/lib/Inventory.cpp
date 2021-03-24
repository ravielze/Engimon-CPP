#include "lib/Inventory.hpp"

template <typename T>
int Inventory<T>::ITEM_PER_PAGE = 10;

template <typename T>
void Inventory<T>::show(int page) const
{
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