#include "Mecanic.h"

Mecanic::Mecanic(): Angajati()
{
    Coeficient_Salarial = 1.5;
}

Mecanic::Mecanic(const char id[], const char data_n[], const char data_a[], const char *nume, const char *prenume): Angajati(id, data_n, data_a, nume, prenume)
{
    Coeficient_Salarial = 1.5;
}

Mecanic::Mecanic(const Mecanic & a)
{
    *this = a;
}

Mecanic::Mecanic(const Angajati & a): Angajati(a)
{
    Coeficient_Salarial = 1.5;
}

Mecanic & Mecanic::operator=(const Mecanic & a)
{
    Angajati::operator=(a);
    return *this;
}

istream & Mecanic::citire(istream & dev)
{
    Angajati::citire(dev);
}

istream & operator>>(istream & dev, Mecanic & a)
{
    return a.citire(dev);
}

ostream & Mecanic::afisare(ostream & dev)
{
    cout << "**** MECANIC ****\n";
    Angajati::afisare(dev);
    return dev;
}

ostream & operator<<(ostream & dev, Mecanic & m)
{
    m.afisare(dev);
}
