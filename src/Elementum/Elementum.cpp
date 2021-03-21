#include "Elementum.hpp"

Elementum::Elementum()
{
}

Elementum::Elementum(vector<Element> elements)
{
    for (int i = 0; i < elements.size(); i++)
    {
        this->elements.push_back(elements[i]);
    }
}

bool Elementum::operator%(Element el) const
{
    if (this->elements.size() > 0)
    {
        for (int i = 0; i < this->elements.size(); i++)
        {
            if (this->elements[i] == el)
            {
                return true;
            }
        }
    }
    return false;
}

bool Elementum::operator==(const Elementum &other) const
{
    if (other.elements.size() != this->elements.size())
    {
        return false;
    }
    for (int i = 0; i < other.elements.size(); i++)
    {
        if (other.elements[i] != this->elements[i])
        {
            return false;
        }
    }
    return true;
}

Elementum &Elementum::operator=(const Elementum &other)
{
    this->elements.clear();
    for (int i = 0; i < other.elements.size(); i++)
    {
        this->elements.push_back(elements[i]);
    }
    return *this;
}
void Elementum::show() const 
{
    cout << "Elements : ";
}

