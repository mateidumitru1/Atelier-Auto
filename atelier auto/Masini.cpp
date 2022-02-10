#include "Masini.h"

Masini::Masini()
{
    ID = 0;
    km = 0;
    an_fabricatie = 0;
    isDiesel = '\0';
}

Masini::Masini(const unsigned km, const unsigned an_fabricatie, const char isDiesel)
{
    this->km = km;
    this->an_fabricatie = an_fabricatie;
    this->isDiesel = isDiesel;
}

Masini::Masini(const Masini & m)
{
    *this = m;
}

Masini & Masini::operator=(const Masini & m)
{
    ID = m.ID;
    km = m.km;
    an_fabricatie = m.an_fabricatie;
    isDiesel = m.isDiesel;
    return *this;
}

istream & Masini::citire(istream & dev)
{
    cout << "Numar km: "; dev >> km;
    cout << "An fabricatie: "; dev >> an_fabricatie;
    cout << "Are motor diesel?(d/n) "; dev >> isDiesel;
    return dev;
}

istream & operator>>(istream & dev, Masini & m)
{
    return m.citire(dev);
}

ostream & Masini::afisare(ostream & dev)
{
    cout << "\nID: "; dev << ID;
    cout << "\nNumar km: "; dev << km;
    cout << "\nAn fabricatie: "; dev << an_fabricatie;
    cout << "\nDiesel: "; dev << isDiesel;
    return dev;
}

ostream & operator<<(ostream & dev, Masini & m)
{
    return m.afisare(dev);
}
