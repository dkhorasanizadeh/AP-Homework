#include "adress.hpp"

const QString &Adress::getName() const
{
    return Name;
}

void Adress::setName(const QString &newName)
{
    Name = newName;
}

const QString &Adress::getAdressText() const
{
    return AdressText;
}

void Adress::setAdressText(const QString &newAdressText)
{
    AdressText = newAdressText;
}

Adress::Adress(QObject *parent) : QObject(parent)
{

}
