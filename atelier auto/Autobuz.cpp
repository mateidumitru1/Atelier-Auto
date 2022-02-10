#include "Autobuz.h"

Autobuz::Autobuz()
{
    nr_locuri = 0;
}

Autobuz::Autobuz(const unsigned km, const unsigned an_fabricatie, const char isDiesel, const unsigned nr_locuri): Masini(km, an_fabricatie, isDiesel)
{
    this->nr_locuri = nr_locuri;
}

Autobuz::Autobuz(const Autobuz & ms)
{
    *this = ms;
}

Autobuz & Autobuz::operator=(const Autobuz & ms)
{
    Masini::operator=(ms);
    nr_locuri = ms.nr_locuri;
    return *this;
}

istream & Autobuz::citire(istream & dev)
{
    Masini::citire(dev);
    cout << "\nNumar locuri: "; dev >> nr_locuri;
    return dev;
}

istream & operator>>(istream & dev, Autobuz & ms)
{
    return ms.citire(dev);
}

ostream & Autobuz::afisare(ostream & dev)
{
    cout << "**** AUTOBUZ ****\n"
    Masini::afisare();
    cout << "Numar locuri: "; dev << nr_locuri;
    return dev;
}

ostream & operator<<(ostream & dev, Autobuz & ms)
{
    return ms.afisare(dev);
}

unsigned Autobuz::getPolita()
{
    time_t t = time(NULL);
    tm * timePtr = localtime(&t);
    unsigned polita = 0;
    polita = (timePtr->tm_year + 1900 - an_fabricatie) * 200;
    if(isDiesel == 'd') polita = polita + 1000;
    if(km > 200000) polita = polita + 1000;
    else if(km > 100000) polita = polita + 500;
    return polita;
}
