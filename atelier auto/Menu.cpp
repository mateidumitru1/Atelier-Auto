#include "Menu.h"
#include "MenuAngajati.h"
#include <limits>

void Menu()
{
    system("cls");
    cout << "********************************* MENIU *********************************";
    cout << "\n\n\tOptiuni\n\n";
    cout << "\t1. Angajati\n";
    cout << "\t2. Masini\n\n";
    cout << "\tTastati \"q\" pentru a iesi.\n\n";
    cout << "\tSelectati o optiune: ";
    SelectOptionMenu();
}

void SelectOptionMenu()
{
    char a;
    cin >> a;
    switch(a)
    {
        case '1':
        {
            MenuAngajati();
            break;
        }
        case '2':
        {

        }
        case 'q':
        {
            return;
            break;
        }
    }
}

void MenuAngajati()
{
    system("cls");
    cout << "**************************** MENIU ANGAJATI ****************************";
    cout << "\n\n\tOptiuni\n\n";
    cout << "\t1. Afisare angajati\n";
    cout << "\t2. Adaugare angajat\n";
    cout << "\t3. Stergere angajat\n";
    cout << "\t4. Editare angajat\n";
    cout << "\t5. Calcul salariu angajat\n\n";
    cout << "\tTastati \"b\" pentru a reveni la meniul principal.\n\n";
    cout << "\tTastati \"q\" pentru a iesi.\n\n";
    cout << "\tSelectati o optiune: ";
    SelectOptionMenuAngajati();
}

void SelectOptionMenuAngajati()
{
    char a;
    cin >> a;
    switch(a)
    {
        case '1':
        {
            afisareAngajati();
            break;
        }
        case '2':
        {
            adaugareAngajat();
            break;
        }
        case '3':
        {
            stergereAngajat();
            break;
        }
        case '4':
        {
            editareAngajat();
            break;
        }
        case '5':
        {
            salariuAngajat();
            break;
        }
        case 'b':
        {
            Menu();
        }
        case 'q':
        {
            exit(0);
            break;
        }
    }
    fflush(stdin);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    MenuAngajati();
}
