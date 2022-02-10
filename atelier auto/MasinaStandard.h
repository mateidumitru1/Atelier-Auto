#ifndef MASINA_STANDARD_H
#define MASINA_STANDARD_H

#include "Masini.h"

class MasinaStandard: public Masini{
    char transmisie;
    public:
        MasinaStandard();
        MasinaStandard(const unsigned, const unsigned, const char, const char);
        MasinaStandard(const MasinaStandard &);
        ~MasinaStandard(){}
        Masina & operator=(const MasinaStandard &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, MasinaStandard &);
        friend ostream & operator<<(ostream &, MasinaStandard &);
        unsigned getPolita();
};

#endif
