#ifndef AUTOBUZ_H
#define AUTOBUZ_H

#include "Masini.h"

class Autobuz: public Masini{
    unsigned nr_locuri;
    public:
        Autobuz();
        Autobuz(const unsigned, const unsigned, const char, const unsigned);
        Autobuz(const Autobuz &);
        ~Autobuz(){}
        Masina & operator=(const Autobuz &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Autobuz &);
        friend ostream & operator<<(ostream &, Autobuz &);
        unsigned getPolita();
};

#endif
