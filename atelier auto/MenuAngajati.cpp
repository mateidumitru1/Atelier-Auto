#include "MenuAngajati.h"

void afisareAngajati()
{
    system("cls");
    if( ListaAngajati.size() == 0 ) 
    {
        cout << "Nu exista niciun angajat!\n";
        cout << "\nApasati ENTER pentru a continua.\n\n";
        return;
    }

    for(int i = 0; i < ListaAngajati.size(); i++)
        cout << *ListaAngajati[i] << "\n";
    cout << "\nApasati ENTER pentru a continua.\n";
}

void adaugareAngajat()
{
    system("cls");
    cout << "Ce pozitie are noul angajat? Director, Mecanic sau Asistent?(d/m/a)\n\n";
    char c;
    cin >> c;
    while ( c != 'd' && c != 'm' && c != 'a' )
    {
        cout << "\nAlegeti un post existent!(d/m/a)\n";
        cin >> c;
    }
    if(c == 'd')
    {
        Director *d = new Director;
        cin >> *d;
        ListaAngajati.push_back(d);
    }
    else if(c == 'm')
    {
        Mecanic *m = new Mecanic;
        cin >> *m;
        ListaAngajati.push_back(m);
    }
    else if(c == 'a')
    {
        Asistent *a = new Asistent;
        cin >> *a;
        ListaAngajati.push_back(a);
    }
    system("cls");
    cout << "\nAngajatul a fost adaugat cu succes!\n\nApasati ENTER pentru a continua.\n\n";
}

void stergereAngajat()
{
    system("cls");
    if( ListaAngajati.size() == 0 )
    {
        cout << "Nu exista niciun angajat!\n\nApasati ENTER pentru a continua.\n\n";
        return;
    }
    cout << "Introduceti ID-ul angajatului pe care doriti sa il stergeti sau tastati \"b\" pentru a va intoarce: ";
    char id[5];
    cin >> id;
    if( strcmp(id, "b") == 0 )
    {
        system("cls");
        cout << "Apasati ENTER pentru a continua.\n\n";
        return;
    }
    unsigned k = -1;
    for(int i = 0; i < ListaAngajati.size(); i++)
        if( strcmp(id, ListaAngajati[i]->getID()) == 0 )
        {
            k = i;
            break;
        }
    system("cls");
    if(k != -1)
    {
        vector<Angajati*>::iterator i = ListaAngajati.begin();
        advance(i, k);
        ListaAngajati.erase(i);
        cout << "Angajatul a fost sters cu succes!\n\nApasati ENTER pentru a continua.\n\n";
    }
    else
    {
        cout << "Angajatul nu a fost gasit.\n\nApasati ENTER pentru a continua.\n\n";
        fflush(stdin);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        stergereAngajat();
    }
}
