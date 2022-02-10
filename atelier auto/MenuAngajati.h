#ifndef MENU_ANGAJATI_H
#define MENU_ANGAJATI_H

#include <vector>
#include "Angajati.h"
#include "Director.h"
#include "Mecanic.h"
#include "Asistent.h"
#include <limits>

using namespace std;

extern vector<Angajati*> ListaAngajati;

void afisareAngajati();
void adaugareAngajat();
void stergereAngajat();
void editareAngajat();
void salariuAngajat();

#endif
