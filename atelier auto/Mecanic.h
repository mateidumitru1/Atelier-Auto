#ifndef MECANIC_H
#define MECANIC_H

#include "Angajati.h"

class Mecanic: public Angajati{
    public:
        Mecanic();
        Mecanic(const char[], const char[], const char[], const char*, const char*);
        Mecanic(const Mecanic &);
        Mecanic & operator=(const Mecanic &);
        istream & citire(istream & dev);
        friend istream & operator>>(istream & dev, Mecanic &);
        friend ostream & operator<<(ostream & dev, Mecanic &);
        ostream & afisare(ostream &);
};

#endif
