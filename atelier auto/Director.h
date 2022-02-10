#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Angajati.h"

class Director: public Angajati{
    public:
        Director();
        Director(const char[], const char[], const char*, const char*);
        Director(const Director &);
        Director(const Angajati &);
        ~Director(){}
        Director & operator=(const Director &);
        istream & citire(istream & dev);
        friend istream & operator>>(istream & dev, Director &);
        friend ostream & operator<<(ostream & dev, Director &);
        ostream & afisare(ostream &);
};

#endif
