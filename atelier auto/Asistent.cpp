#include "Asistent.h"

Asistent::Asistent(): Angajati()
{
    Coeficient_Salarial = 1;
}

Asistent::Asistent(const char id[], const char data_n[], const char data_a[], const char *nume, const char *prenume): Angajati(id, data_n, data_a, nume, prenume)
{
    Coeficient_Salarial = 1;
}

Asistent::Asistent(const Asistent & a)
{
    *this = a;
}

Asistent::Asistent(const Angajati & a): Angajati(a)
{
    Coeficient_Salarial = 1;
}

Asistent & Asistent::operator=(const Asistent & a)
{
    Angajati::operator=(a);
    return *this;
}

istream & Asistent::citire(istream & dev)
{
    Angajati::citire(dev);
}

istream & operator>>(istream & dev, Asistent & a)
{
    return a.citire(dev);
}

ostream & Asistent::afisare(ostream & dev)
{
    cout << "**** ASISTENT ****\n";
    Angajati::afisare(dev);
    return dev;
}

ostream & operator<<(ostream & dev, Asistent & a)
{
    return a.afisare(dev);
}
