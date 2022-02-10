#include "MasinaStandard.h"

MasinaStandard::MasinaStandard()
{
    transmisie = '\0';
}

MasinaStandard::MasinaStandard(const unsigned km, const unsigned an_fabricatie, const char isDiesel, const char transmisie): Masini(km, an_fabricatie, isDiesel)
{
    this->transmisie = transmisie;
}

MasinaStandard::MasinaStandard(const MasinaStandard & ms)
{
    *this = ms;
}

MasinaStandard & MasinaStandard::operator=(const MasinaStandard & ms)
{
    Masini::operator=(ms);
    transmisie = ms.transmisie;
    return *this;
}

istream & MasinaStandard::citire(istream & dev)
{
    Masini::citire(dev);
    cout << "\nTransmisie manuala sau automata(m/a): "; dev >> transmisie;
    return dev;
}

istream & operator>>(istream & dev, MasinaStandard & ms)
{
    return ms.citire(dev);
}

ostream & MasinaStandard::afisare(ostream & dev)
{
    cout << "**** MASINA STANDARD ****\n"
    Masini::afisare();
    cout << "Transmisie: ";
    if(transmisie == 'm') dev << "manuala\n";
    else if(transmisie == 'a') dev << "automata\n";
    return dev;
}

ostream & operator<<(ostream & dev, MasinaStandard & ms)
{
    return ms.afisare(dev);
}

unsigned MasinaStandard::getPolita()
{
    time_t t = time(NULL);
    tm * timePtr = localtime(&t);
    unsigned polita = 0;
    polita = (timePtr->tm_year + 1900 - an_fabricatie) * 100;
    if(isDiesel == 'd') polita = polita + 500;
    if(km > 200000) polita = polita + 500;
    return polita;
}
