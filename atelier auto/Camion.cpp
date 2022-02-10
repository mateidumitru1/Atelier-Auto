#include "Camion.h"

Camion::Camion()
{
    tonaj = 0;
}

Camion::Camion(const unsigned km, const unsigned an_fabricatie, const char isDiesel, const unsigned tonaj): Masini(km, an_fabricatie, isDiesel)
{
    this->tonaj = tonaj;
}

Camion::Camion(const Camion & ms)
{
    *this = ms;
}

Camion & Camion::operator=(const Camion & ms)
{
    Masini::operator=(ms);
    tonaj = ms.tonaj;
    return *this;
}

istream & Camion::citire(istream & dev)
{
    Masini::citire(dev);
    cout << "\nTonaj: "; dev >> tonaj;
    return dev;
}

istream & operator>>(istream & dev, Camion & ms)
{
    return ms.citire(dev);
}

ostream & Camion::afisare(ostream & dev)
{
    cout << "**** CAMION ****\n"
    Masini::afisare();
    cout << "Tonaj: "; dev << tonaj;
    return dev;
}

ostream & operator<<(ostream & dev, Camion & ms)
{
    return ms.afisare(dev);
}

unsigned Camion::getPolita()
{
    time_t t = time(NULL);
    tm * timePtr = localtime(&t);
    unsigned polita = 0;
    polita = (timePtr->tm_year + 1900 - an_fabricatie) * 300;
    if(km > 800000) polita = polita + 700;
    return polita;
}
