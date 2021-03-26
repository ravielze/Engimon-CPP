#include "lib/Elementum.hpp"
#include "utils.hpp"

Elementum::Elementum()
{
    this->elementAmount = 0;
    this->firstElement = Element::NONE;
    this->secondElement = Element::NONE;
}

Elementum::Elementum(vector<Element> otherElements)
{
    if (otherElements.size() >= 1)
    {
        this->firstElement = otherElements[0];
    }
    if (otherElements.size() >= 2)
    {
        this->secondElement = otherElements[1];
    }
    this->elementAmount = (otherElements.size() >= 2) ? 2 : otherElements.size();
}

Element Elementum::getFirstElement() const
{
    return this->firstElement;
}

Element Elementum::getSecondElement() const
{
    return this->secondElement;
}

Elementum::Elementum(const Elementum &other)
{
    this->elementAmount = other.elementAmount;
    this->firstElement = other.getFirstElement();
    this->secondElement = other.getSecondElement();
}

bool Elementum::operator%(Element el) const
{
    if (getFirstElement() != Element::NONE and el == getFirstElement())
    {
        return true;
    }
    if (getSecondElement() != Element::NONE and el == getSecondElement())
    {
        return true;
    }
    return false;
}

bool Elementum::operator%(const Elementum &el) const
{
    if (this->elementAmount == 2)
    {
        return this->operator%(el.getFirstElement()) || this->operator%(el.getSecondElement());
    }
    else if (this->elementAmount == 1)
    {
        return this->operator%(el.getFirstElement());
    }
    return false;
}

int Elementum::getElementCount() const
{
    return this->elementAmount;
}

double Elementum::getTotalMultiplier(const Elementum &other) const
{

    double firstMultiplier = max(ElementManager::getInstance().getMultiplier(getFirstElement(), other.getFirstElement()), ElementManager::getInstance().getMultiplier(getFirstElement(), other.getSecondElement()));
    double secondMultiplier = max(ElementManager::getInstance().getMultiplier(getSecondElement(), other.getFirstElement()), ElementManager::getInstance().getMultiplier(getSecondElement(), other.getSecondElement()));

    return max(firstMultiplier, secondMultiplier);
}

bool Elementum::operator==(const Elementum &other) const
{
    if (this->elementAmount != other.elementAmount)
    {
        return false;
    }
    return this->operator%(other.getFirstElement()) && this->operator%(other.getSecondElement());
}

Elementum &Elementum::operator=(const Elementum &other)
{
    // this->elements.clear();
    // for (auto el : other.elements)
    // {
    //     this->elements.push_back(el);
    // }
    this->firstElement = other.getFirstElement();
    this->secondElement = other.getSecondElement();
    this->elementAmount = other.getElementCount();
    return *this;
}

void Elementum::show() const
{
    cout << "[";
    if (elementAmount >= 1)
    {
        cout << convertElementToString(this->firstElement);
    }
    if (elementAmount == 2)
    {
        cout << ", " << convertElementToString(this->secondElement);
    }
    cout << "]";
}
