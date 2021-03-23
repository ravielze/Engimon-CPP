#include "lib/Elementum.hpp"
#include "utils.hpp"

Elementum::Elementum()
{
}

Elementum::Elementum(vector<Element> otherElements)
{
    for (auto x : otherElements)
    {
        this->elements.push_back(x);
    }
}
vector<Element> Elementum::getElements()
{
    return elements;
}

bool Elementum::operator%(Element el) const
{
    if (this->elements.size() > 0)
    {
        for (auto x : this->elements)
        {
            if (x == el)
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
    for (auto x : other.elements)
    {
        if (!(this->operator%(x)))
        {
            return false;
        }
    }
    return true;
}

Elementum &Elementum::operator=(const Elementum &other)
{
    this->elements.clear();
    for (auto el : other.elements)
    {
        this->elements.push_back(el);
    }
    return *this;
}

void Elementum::show() const
{
    cout << "[";
    bool first = true;
    for (auto el : this->elements)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            cout << ", ";
        }
        cout << convertElementToString(el);
    }
    cout << "]" << endl;
}
