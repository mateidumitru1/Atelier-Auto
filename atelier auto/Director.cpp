#include "Director.h"

Director::Director(): Angajati()
{
    Coeficient_Salarial = 2;
}

Director::Director(const char id[], const char data_n[], const char data_a[], const char *nume, const char *prenume): Angajati(id, data_n, data_a, nume, prenume)
{
    Coeficient_Salarial = 2;
}

Director::Director(const Director & a)
{
    *this = a;
}

Director::Director(const Angajati & a): Angajati(a)
{
    Coeficient_Salarial = 2;
}

Director & Director::operator=(const Director & a)
{
    Angajati::operator=(a);
    return *this;
}

istream & Director::citire(istream & dev)
{
    Angajati::citire(dev);
}

istream & operator>>(istream & dev, Director & a)
{
    return a.citire(dev);
}

ostream & Director::afisare(ostream & dev)
{
    cout << "**** DIRECTOR ****\n";
    Angajati::afisare(dev);
    return dev;
}

ostream & operator<<(ostream & dev, Director & d)
{
    d.afisare(dev);
}
