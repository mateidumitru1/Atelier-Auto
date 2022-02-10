#include "Menu.h"

void afisareAngajati()
{
    system("cls");
    if (ListaAngajati.size() == 0)
    {
        cout << "Nu exista niciun angajat!\n";
        cout << "\nApasati ENTER pentru a continua.\n\n";
        return;
    }

    for (unsigned i = 0; i < ListaAngajati.size(); i++)
        cout << *ListaAngajati[i] << "\n";
    cout << "\nApasati ENTER pentru a continua.\n";
}

void adaugareAngajat()
{
    system("cls");
    cout << "Ce pozitie are noul angajat? Director, Mecanic sau Asistent?(d/m/a)\n\n";
    char c;
    cin >> c;
    while (c != 'd' && c != 'm' && c != 'a')
    {
        cout << "\nAlegeti un post existent!(d/m/a)\n";
        cin >> c;
    }
    if (c == 'd')
    {
        Director *d = new Director;
        cin >> *d;
        ListaAngajati.push_back(d);
    }
    else if (c == 'm')
    {
        Mecanic *m = new Mecanic;
        cin >> *m;
        ListaAngajati.push_back(m);
    }
    else if (c == 'a')
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
    if (ListaAngajati.size() == 0)
    {
        cout << "Nu exista niciun angajat!\n\nApasati ENTER pentru a continua.\n\n";
        return;
    }
    cout << "Introduceti ID-ul angajatului pe care doriti sa il stergeti sau tastati \"b\" pentru a va intoarce la meniu: ";
    char id[5];
    cin >> id;
    int ID = atoi(id);
    if (strcmp(id, "b") == 0)
    {
        MenuAngajati();
    }
    unsigned i = 0;
    vector<Angajati *>::iterator it = ListaAngajati.begin();
    while (it != ListaAngajati.end())
    {
        if (ID == ListaAngajati[i]->getID())
        {
            break;
        }
        it++;
        i++;
    }

    system("cls");
    if (it != ListaAngajati.end())
    {
        ListaAngajati.erase(it);
        cout << "Angajatul a fost sters cu succes!\n\nApasati ENTER pentru a continua.\n\n";
    }
    else
    {
        cout << "Angajatul nu a fost gasit.\n\nApasati ENTER pentru a continua.\n\n";
        fflush(stdin);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        stergereAngajat();
    }
}

void editareAngajat()
{
    system("cls");

    if (ListaAngajati.size() == 0)
    {
        cout << "Nu exista niciun angajat!\n\nApasati ENTER pentru a continua.\n\n";
        return;
    }

    cout << "Introduceti ID-ul angajatului pe care doriti sa il modificati sau tastati \"b\" pentru a va intoarce la meniu: ";
    char id[5];
    cin >> id;
    int ID = atoi(id);
    if (strcmp(id, "b") == 0)
    {
        MenuAngajati();
    }
    unsigned i = 0;
    while (i < ListaAngajati.size())
    {
        if (ID == ListaAngajati[i]->getID())
        {
            break;
        }
        i++;
    }
    system("cls");
    if (i < ListaAngajati.size())
    {
        cout << "Alegeti ce modificare doriti sa efectuati\n";
        cout << "Daca doriti sa va intoarceti la meniu tastati \"b\".\n";
        cout << "\n1. Nume\n";
        cout << "2. Data Nasterii\n";
        cout << "3. Data Angajarii\n";
        cout << "4. Postul\n\nOptiune: ";
        char c;
        cin >> c;
        system("cls");
        switch (c)
        {
        case '1':
        {
            char nume[30], prenume[30];
            cout << "Daca doriti sa pastrati numele sau prenumele tastati \"q\".\n\n";
            fflush(stdin);
            cout << "Noul nume: ";
            cin >> nume;
            cout << "\nNoul prenume: ";
            cin >> prenume;
            unsigned ok = 0;
            if (strcmp(nume, "q"))
            {
                ok = 1;
                ListaAngajati[i]->setNume(nume);
            }
            if (strcmp(prenume, "q"))
            {
                ok = 1;
                ListaAngajati[i]->setPrenume(prenume);
            }
            system("cls");
            if (ok == 1)
                cout << "Numele a fost schimbat cu succes!\n\nApasati ENTER pentru a continua.\n\n";
            else
                cout << "Numele nu a fost schimbat.\n\nApasati ENTER pentru a continua.\n\n";
            break;
        }
        case '2':
        {
            cout << "Daca v-ati razgandit tastati acum \"q\".\n\n";
            cout << "Noua zi de nastere\n";
            char zi[3], luna[3], an[5];

            int d;

            cout << "\n               Zi(ZZ): ";
            cin >> zi;

            /***********  Daca ziua nu are 2 cifre, daca prima cifra >= 4 sau daca contine alte caractere decat cifre, se repeta citirea zilei.  ***********/

            while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' || zi[0] < '0') || (zi[1] > '9' || zi[1] < '0'))
            {
                cout << "\nIntroduceti o zi valida!(ZZ)";
                cout << "\n               Zi(ZZ): ";
                cin >> zi;
            }

            cout << "\n               Luna(LL): ";
            cin >> luna;

            /*********** Daca luna nu are 2 cifre, daca are prima cifra >= 2, daca luna e >= 13 sau daca contine alte caractere decat cifre, se repeta citirea lunii. ***********/

            while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
            {
                cout << "\nIntroduceti o luna valida!(LL)";
                cout << "\n               Luna(LL): ";
                cin >> luna;
            }

            /*********** Daca luna 02 (adica februarie) are mai mult de 29 de zile sau daca lunile aprile, iunie, septembrie sau noiembrie au 31 de zile, se repeta citirea zilei si a lunii.  ***********/

            while ((zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || (strcmp(zi, "31") == 0 && (strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0)))
            {
                cout << "\nIntroduceti o zi si o luna valida!";
                cout << "\n               Zi(ZZ): ";
                cin >> zi;

                while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' && zi[0] < '0') || (zi[1] > '9' && zi[1] < '0'))
                {
                    cout << "\nIntroduceti o zi valida!(ZZ)";
                    cout << "\n               Zi(ZZ): ";
                    cin >> zi;
                }

                cout << "\n               Luna(LL): ";
                cin >> luna;

                while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
                {
                    cout << "\nIntroduceti o luna valida!(LL)";
                    cout << "\n               Luna(LL): ";
                    cin >> luna;
                }
            }

            cout << "\n               An(AAAA): ";

            cin >> an;
            time_t t = time(NULL);
            tm *timePtr = localtime(&t);
            /*********** Daca anul nu are 4 cifre sau daca contine alte caractere decat cifre, se repeta citirea. ***********/

            while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9') || (an[1] < '0' || an[1] > '9') || (an[2] < '0' || an[2] > '9') || (an[3] < '0' || an[3] > '9'))
            {
                cout << "\nIntroduceti un an valid!(AAAA)";
                cout << "\n               An(AAAA): ";
                cin >> an;
                unsigned AN = atoi(an);

            }

            d = atoi(an); // transform anul in INT ca sa pot verifica daca e an bisect

            /*********** Daca nu e an bisect si februarie are 29 de zile, se repeta intreaga citire. ***********/

            unsigned anv, lv, ziv;
            anv = atoi(an);

            if(luna[0] == '0')  lv = atoi(luna + 1);
            else lv = atoi(luna);

            if(zi[0] == '0') ziv = atoi(zi + 1);
            else ziv = atoi(zi);

            while ((d % 4 != 0 && strcmp(luna, "02") == 0 && strcmp(zi, "29") == 0) || (timePtr->tm_year + 1900 - anv < 18) || (timePtr->tm_year - anv + 1900 == 18 && timePtr->tm_mon + 1 < lv) || (timePtr->tm_year + 1900 - anv == 18 && timePtr->tm_mon + 1 == lv && ziv > timePtr->tm_mday) )
            {
                cout << "\nIntroduceti o data valida!(ZZ/LL/AAAA)";
                cout << "\n               Zi(ZZ): ";
                cin >> zi;

                while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' && zi[0] < '0') || (zi[1] > '9' && zi[1] < '0'))
                {
                    cout << "\nIntroduceti o zi valida!(ZZ)";
                    cout << "\n               Zi(ZZ): ";
                    cin >> zi;
                }

                cout << "\n               Luna(LL): ";
                cin >> luna;

                while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
                {
                    cout << "\nIntroduceti o luna valida!(LL)";
                    cout << "\n               Luna(LL): ";
                    cin >> luna;
                }

                while ((zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || (strcmp(zi, "31") == 0 && (strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0)))
                {
                    cout << "\nIntroduceti o zi si o luna valida!";
                    cout << "\n               Zi(ZZ): ";
                    cin >> zi;

                    while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' && zi[0] < '0') || (zi[1] > '9' && zi[1] < '0'))
                    {
                        cout << "\nIntroduceti o zi valida!(ZZ)";
                        cout << "\n               Zi(ZZ): ";
                        cin >> zi;
                    }

                    cout << "\n               Luna(LL): ";
                    cin >> luna;

                    while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
                    {
                        cout << "\nIntroduceti o luna valida!(LL)";
                        cout << "\n               Luna(LL): ";
                        cin >> luna;
                    }
                }

                cout << "\n               An(AAAA): ";

                cin >> an;

                unsigned AN = atoi(an);
                time_t t = time(NULL);
                tm *timePtr = localtime(&t);

                while (strlen(an) != 4 || timePtr->tm_year + 1900 - AN < 18 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
                {
                    cout << "\nIntroduceti un an valid!(AAAA)";
                    cout << "\n               An(AAAA): ";
                    cin >> an;
                    unsigned AN = atoi(an);

                }
                d = atoi(an);
                anv = atoi(an);

                if(luna[0] == '0')  lv = atoi(luna + 1);
                else lv = atoi(luna);

                if(zi[0] == '0') ziv = atoi(zi + 1);
                else ziv = atoi(zi);

            }

            char Data_Nasterii[11];

            strcpy(Data_Nasterii, zi);
            strcat(Data_Nasterii, "/");
            strcat(Data_Nasterii, luna);
            strcat(Data_Nasterii, "/");
            strcat(Data_Nasterii, an);

            ListaAngajati[i]->setDataNasterii(Data_Nasterii);

            system("cls");
            cout << "Data nasterii a fost modificata cu succes!\n\nApasati ENTER pentru a continua.\n\n";

            break;
        }

        case '3':
        {
            cout << "Daca v-ati razgandit tastati acum \"q\".\n\n";
            cout << "Noua zi de angajare\n";
            char zi[3], luna[3], an[5];

            int d;

            cout << "\n               Zi(ZZ): ";
            cin >> zi;

            /***********  Daca ziua nu are 2 cifre, daca prima cifra >= 4 sau daca contine alte caractere decat cifre, se repeta citirea zilei.  ***********/

            while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' || zi[0] < '0') || (zi[1] > '9' || zi[1] < '0'))
            {
                cout << "\nIntroduceti o zi valida!(ZZ)";
                cout << "\n               Zi(ZZ): ";
                cin >> zi;
            }

            cout << "\n               Luna(LL): ";
            cin >> luna;

            /*********** Daca luna nu are 2 cifre, daca are prima cifra >= 2, daca luna e >= 13 sau daca contine alte caractere decat cifre, se repeta citirea lunii. ***********/

            while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
            {
                cout << "\nIntroduceti o luna valida!(LL)";
                cout << "\n               Luna(LL): ";
                cin >> luna;
            }

            /*********** Daca luna 02 (adica februarie) are mai mult de 29 de zile sau daca lunile aprile, iunie, septembrie sau noiembrie au 31 de zile, se repeta citirea zilei si a lunii.  ***********/

            while ((zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || (strcmp(zi, "31") == 0 && (strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0)))
            {
                cout << "\nIntroduceti o zi si o luna valida!";
                cout << "\n               Zi(ZZ): ";
                cin >> zi;

                while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' && zi[0] < '0') || (zi[1] > '9' && zi[1] < '0'))
                {
                    cout << "\nIntroduceti o zi valida!(ZZ)";
                    cout << "\n               Zi(ZZ): ";
                    cin >> zi;
                }

                cout << "\n               Luna(LL): ";
                cin >> luna;

                while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
                {
                    cout << "\nIntroduceti o luna valida!(LL)";
                    cout << "\n               Luna(LL): ";
                    cin >> luna;
                }
            }

            cout << "\n               An(AAAA): ";

            cin >> an;

            /*********** Daca anul nu are 4 cifre sau daca contine alte caractere decat cifre, se repeta citirea. ***********/

            while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9') || (an[1] < '0' || an[1] > '9') || (an[2] < '0' || an[2] > '9') || (an[3] < '0' || an[3] > '9'))
            {
                cout << "\nIntroduceti un an valid!(AA)";
                cout << "\n               An(AAAA): ";
                cin >> an;
            }

            d = atoi(an); // transform anul in INT ca sa pot verifica daca e an bisect

            /*********** Daca nu e an bisect si februarie are 29 de zile, se repeta intreaga citire. ***********/

            
            time_t t = time(NULL);
            tm * timePtr = localtime(&t);

            unsigned anv, lv, ziv;
            anv = atoi(an);
            if(luna[0] == '0')  lv = atoi(luna + 1);
            else lv = atoi(luna);

            if(zi[0] == '0') ziv = atoi(zi + 1);
            else ziv = atoi(zi);

            while ((d % 4 != 0 && strcmp(luna, "02") == 0 && strcmp(zi, "29") == 0) || (anv > timePtr->tm_year + 1900) || (anv == timePtr->tm_year + 1900 && lv > timePtr->tm_mon +1 ) || (anv == timePtr->tm_year + 1900 && lv == timePtr->tm_mon + 1 && ziv > timePtr->tm_mday) )
            {
                cout << "\nIntroduceti o data valida!(ZZ/LL/AAAA)";
                cout << "\n               Zi(ZZ): ";
                cin >> zi;

                while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' && zi[0] < '0') || (zi[1] > '9' && zi[1] < '0'))
                {
                    cout << "\nIntroduceti o zi valida!(ZZ)";
                    cout << "\n               Zi(ZZ): ";
                    cin >> zi;
                }

                cout << "\n               Luna(LL): ";
                cin >> luna;

                while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
                {
                    cout << "\nIntroduceti o luna valida!(LL)";
                    cout << "\n               Luna(LL): ";
                    cin >> luna;
                }

                while ((zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || (strcmp(zi, "31") == 0 && (strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0)))
                {
                    cout << "\nIntroduceti o zi si o luna valida!";
                    cout << "\n               Zi(ZZ): ";
                    cin >> zi;

                    while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || (zi[0] > '9' && zi[0] < '0') || (zi[1] > '9' && zi[1] < '0'))
                    {
                        cout << "\nIntroduceti o zi valida!(ZZ)";
                        cout << "\n               Zi(ZZ): ";
                        cin >> zi;
                    }

                    cout << "\n               Luna(LL): ";
                    cin >> luna;

                    while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2') || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9'))
                    {
                        cout << "\nIntroduceti o luna valida!(LL)";
                        cout << "\n               Luna(LL): ";
                        cin >> luna;
                    }
                }

                cout << "\n               An(AAAA): ";

                cin >> an;

                anv = atoi(an);
                if(luna[0] == '0')  lv = atoi(luna + 1);
                else lv = atoi(luna);

                if(zi[0] == '0') ziv = atoi(zi + 1);
                else ziv = atoi(zi);

                while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9') || (an[1] < '0' || an[1] > '9') || (an[2] < '0' || an[2] > '9') || (an[3] < '0' || an[3] > '9'))
                {
                    cout << "\nIntroduceti un an valid!(AA)";
                    cout << "\n               An(AAAA): ";
                    cin >> an;
                }
                d = atoi(an);
            }

            char Data_Angajarii[11];

            strcpy(Data_Angajarii, zi);
            strcat(Data_Angajarii, "/");
            strcat(Data_Angajarii, luna);
            strcat(Data_Angajarii, "/");
            strcat(Data_Angajarii, an);

            ListaAngajati[i]->setDataAngajarii(Data_Angajarii);

            system("cls");
            cout << "Data angajarii a fost modificata cu succes!\n\nApasati ENTER pentru a continua.\n\n";

            break;
        }
        case '4':
        {
            cout << "Daca v-ati razgandit tastati acum \"q\".\n\n";
            cout << "Angajatul selectat este ";
            char c;
            if (ListaAngajati[i]->getCoeficient() == 1)
            {
                cout << "asistent.\n\n";
                c = 'a';
            }
            else if (ListaAngajati[i]->getCoeficient() == 1.5)
            {
                cout << "mecanic.\n\n";
                c = 'm';
            }
            else if (ListaAngajati[i]->getCoeficient() == 2)
            {
                cout << "director.\n\n";
                c = 'd';
            }
            cout << "Noul post ";
            if (c == 'a')
                cout << "(m/d): ";
            else if (c == 'm')
                cout << "(a/d): ";
            else if (c == 'd')
                cout << "(a/m): ";
            cin >> c;
            switch (c)
            {
            case 'a':
            {
                Asistent *a = new Asistent(*ListaAngajati[i]);
                ListaAngajati[i] = a;
                break;
            }
            case 'm':
            {
                Mecanic *m = new Mecanic(*ListaAngajati[i]);
                ListaAngajati[i] = m;
                break;
            }
            case 'd':
            {
                Director *d = new Director(*ListaAngajati[i]);
                ListaAngajati[i] = d;
                break;
            }
            case 'q':
            {
                MenuAngajati();
                break;
            }
            }
            system("cls");
            cout << "Postul a fost modificat cu succes.\n\nApasati ENTER pentru a continua.\n\n";
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        editareAngajat();
    }
}

void salariuAngajat()
{
    system("cls");
    if (ListaAngajati.size() == 0)
    {
        cout << "Nu exista niciun angajat!\n\nApasati ENTER pentru a continua.\n\n";
        return;
    }
    cout << "Introduceti ID-ul angajatului caruia doriti sa ii calculati salariul sau tastati \"b\" pentru a reveni la meniu: ";
    char id[5];
    cin >> id;
    if (strcmp(id, "b") == 0)
    {
        MenuAngajati();
    }
    int ID = atoi(id);
    unsigned i = 0;
    while (i < ListaAngajati.size())
    {
        if (ID == ListaAngajati[i]->getID())
        {
            break;
        }
        i++;
    }
    system("cls");
    if (i < ListaAngajati.size())
    {
        cout << "Salariul angajatului este de " << ListaAngajati[i]->getSalariu() << " lei.";
        cout << "\n\nApasati ENTER pentru a continua.\n\n";
    }
    else
    {
        cout << "Angajatul nu a fost gasit.\n\nApasati ENTER pentru a continua.\n\n";
        fflush(stdin);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        stergereAngajat();
    }
}
