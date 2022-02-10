#ifndef ANGAJATI_H
#define ANGAJATI_H

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <vector>



using namespace std;

class Angajati{
    protected:
        unsigned ID;
        char Data_Nasterii[11], Data_Angajarii[11];
        char *nume, *prenume;
        float Coeficient_Salarial;
    public:
        Angajati();
        Angajati(const char[], const char[], const char*, const char*);
        Angajati(const Angajati &);
        ~Angajati();
        Angajati & operator=(const Angajati &);
        friend istream & operator>>(istream &, Angajati &);
        friend ostream & operator<<(ostream &, Angajati &);
        istream & citire(istream & dev);
        virtual ostream & afisare(ostream & dev);
        float getSalariu();
        unsigned getID();
        void setNume(char*);
        void setPrenume(char*);
        void setDataNasterii(char*);
        void setDataAngajarii(char*);
        float getCoeficient();
};

extern vector<Angajati*> ListaAngajati;

#endif
