#include "Menu.h"

void afisareAngajati()
{
    system("cls");
    if( ListaAngajati.size() == 0 ) 
    {
        cout << "Nu exista niciun angajat!\n";
        cout << "\nApasati ENTER pentru a continua.\n\n";
        return;
    }

    for(unsigned i = 0; i < ListaAngajati.size(); i++)
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
    cout << "Introduceti ID-ul angajatului pe care doriti sa il stergeti sau tastati \"b\" pentru a va intoarce la meniu: ";
    char id[5];
    cin >> id;
    if( strcmp(id, "b") == 0 )
    {
        MenuAngajati();
    }
    unsigned i = 0;
    vector<Angajati*>::iterator it = ListaAngajati.begin();
    while ( it != ListaAngajati.end() )
    {
        if( strcmp(id, ListaAngajati[i]->getID() ) == 0 )
        {
            break;
        }
        it++;
        i++;
    }

    system("cls");
    if( it != ListaAngajati.end() )
    {
        ListaAngajati.erase(it);
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

void editareAngajat()
{
    system("cls");

    if( ListaAngajati.size() == 0 )
    {
        cout << "Nu exista niciun angajat!\n\nApasati ENTER pentru a continua.\n\n";
        return;
    }

    cout << "Introduceti ID-ul angajatului pe care doriti sa il modificati sau tastati \"b\" pentru a va intoarce la meniu: ";
    char id[5];
    cin >> id;
    if( strcmp(id, "b") == 0 )
    {
        MenuAngajati();
    }
    unsigned i = 0;
    vector<Angajati*>::iterator it = ListaAngajati.begin();
    while ( it != ListaAngajati.end() )
    {
        if( strcmp(id, ListaAngajati[i]->getID() ) == 0 )
        {
            break;
        }
        it++;
        i++;
    }
    system("cls");
    if( it != ListaAngajati.end() )
    {
        cout << "Alegeti ce modificare doriti sa efectuati: Nume, Data Nasterii, Data Angajarii, Postul(1/2/3/4).\n";
        cout << "Daca doriti sa va intoarceti la meniu tastati \"b\".\n";
        char c;
        cin >> c;
        system("cls");
        switch(c)
        {
            case '1':
            {
                char nume[30], prenume[30];
                cout << "Daca doriti sa pastrati numele sau prenumele tastati \"q\".\n\n";
                fflush(stdin);
                cout << "Noul nume: "; cin >> nume;
                cout << "\nNoul prenume: "; cin >> prenume;
                unsigned ok = 0;
                if( strcmp(nume, "q") )
                {
                    ok = 1;
                    ListaAngajati[i]->setNume(nume);
                }
                if( strcmp(prenume, "q") )
                {
                    ok = 1;
                    ListaAngajati[i]->setPrenume(prenume);
                }
                system("cls");
                if( ok == 1 ) cout << "Numele a fost schimbat cu succes!\n\nApasati ENTER pentru a continua.\n\n";
                else cout << "Numele nu a fost schimbat.\n\nApasati ENTER pentru a continua.\n\n";
                break;
            }
            case '2':
            {
                break;
            }
            case '3':
            {
                break;
            }
            case '4':
            {
                break;
            }
            case 'b':
            {
                MenuAngajati();
                break;
            }
        }
    }
    else
    {
        cout << "Angajatul nu a fost gasit.\n\nApasati ENTER pentru a continua.\n\n";
        fflush(stdin);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        editareAngajat();
    }
}
