#ifndef Camion_H
#define Camion_H

#include "Masini.h"

class Camion: public Masini{
    unsigned tonaj;
    public:
        Camion();
        Camion(const unsigned, const unsigned, const char, const unsigned);
        Camion(const Camion &);
        ~Camion(){}
        Masina & operator=(const Camion &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Camion &);
        friend ostream & operator<<(ostream &, Camion &);
        unsigned getPolita();
};

#endif
