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

Elementum::Elementum(const Elementum &other)
{
    this->elements.clear();
    for (Element e : other.elements)
    {
        this->elements.push_back(e);
    }
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

bool Elementum::operator%(const Elementum &el) const
{
    for (Element e : this->elements)
    {
        if (el % e)
        {
            return true;
        }
    }
    return false;
}

int Elementum::getElementCount() const
{
    return this->elements.size();
}

double Elementum::getTotalMultiplier(const Elementum &other) const
{

    double totalMultiplier = 0;
    for (auto ourElement : this->elements)
    {
        double maxMultiplier = 0;
        for (auto enemyElement : other.elements)
        {
            double multiplier = ElementManager::getInstance().getMultiplier(ourElement, enemyElement);
            if (multiplier > maxMultiplier)
            {
                maxMultiplier = multiplier;
            }
        }
        totalMultiplier += maxMultiplier;
    }
    return totalMultiplier > 2 ? 2 : totalMultiplier;
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
    cout << "]";
}
