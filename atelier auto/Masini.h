#ifndef MASINI_H
#define MASINI_H

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class Masini{
    protected:
        unsigned ID, km, an_fabricatie;
        char isDiesel;
    public:
        Masini();
        Masini(const unsigned, const unsigned, const char);
        Masini(const Masini &);
        Masini & operator=(const Masini &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Masini &);
        friend ostream & operator<<(ostream &, Masini &);
        virtual unsigned getPolita() = 0;
};

#endif
