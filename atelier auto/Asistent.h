#ifndef ASISTENT_H
#define ASISTENT_H

#include "Angajati.h"

class Asistent: public Angajati{
    public:
        Asistent();
        Asistent(const char[], const char[], const char[], const char*, const char*);
        Asistent(const Asistent &);
        Asistent & operator=(const Asistent &);
        istream & citire(istream &);
        friend istream & operator>>(istream & dev, Asistent &);
        friend ostream & operator<<(ostream & dev, Asistent &);
        ostream & afisare(ostream &);
};

#endif
