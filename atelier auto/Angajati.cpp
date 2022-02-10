#include "Angajati.h"

Angajati::Angajati()
{
    ID = 0;
    Data_Nasterii[0] = '\0';
    Data_Angajarii[0] = '\0';
    nume = NULL;
    prenume = NULL;
    Coeficient_Salarial = 0;
}

Angajati::Angajati(const char data_n[], const char data_a[], const char *nume, const char *prenume)
{
    strcpy(Data_Nasterii, data_n);
    strcpy(Data_Angajarii, data_a);
    this->nume = strdup(nume);
    this->prenume = strdup(prenume);
}

Angajati::~Angajati()
{
    delete[] nume;
    delete[] prenume;
}

Angajati::Angajati(const Angajati &a)
{
    *this = a;
}

Angajati &Angajati::operator=(const Angajati &a)
{
    ID = a.ID;
    strcpy(Data_Nasterii, a.Data_Nasterii);
    strcpy(Data_Angajarii, a.Data_Angajarii);
    nume = strdup(a.nume);
    prenume = strdup(a.prenume);
    Coeficient_Salarial = a.Coeficient_Salarial;
    return *this;
}

istream &Angajati::citire(istream &dev)
{
    /********* ID *********/
    if( ListaAngajati.size() == 0 ) ID = 1;
    else 
    {
        for(unsigned i = 1; i <= ListaAngajati.size(); i++)
        {
            unsigned ok = 0;
            for(unsigned j = 0; j < ListaAngajati.size(); j++)
                if( i == ListaAngajati[j]->getID() )
                {
                    ok = 1;
                    break;
                }
            if(ok == 0)
            {
                ID = i;
                break;
            }
        }
        if(ID == 0) ID = ListaAngajati.size() + 1;
    }

    /********* NUME *********/

    cout << "\nNume: ";
    char s[30];
    dev >> s;
    nume = strdup(s);

    /********* PRENUME *********/

    cout << "\nPrenume: ";
    dev >> s;
    prenume = strdup(s);

    /********* DATA NASTERII *********/

    cout << "\nData Nasterii(angajatul trebuie sa aiba varsta mai mare de 18 ani):\n";

    char zi[3], luna[3], an[5];

    int d;

    cout << "\n               Zi(ZZ): ";
    dev >> zi;

    /***********  Daca ziua nu are 2 cifre, daca prima cifra >= 4 sau daca contine alte caractere decat cifre, se repeta citirea zilei.  ***********/


    while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' || zi[0] < '0' ) || ( zi[1] > '9' || zi[1] < '0' ))
    {
        cout << "\nIntroduceti o zi valida!(ZZ)";
        cout << "\n               Zi(ZZ): ";
        dev >> zi;
    }

    cout << "\n               Luna(LL): ";
    dev >> luna;

    /*********** Daca luna nu are 2 cifre, daca are prima cifra >= 2, daca luna e >= 13 sau daca contine alte caractere decat cifre, se repeta citirea lunii. ***********/

    while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
    {
        cout << "\nIntroduceti o luna valida!(LL)";
        cout << "\n               Luna(LL): ";
        dev >> luna;
    }

    /*********** Daca luna 02 (adica februarie) are mai mult de 29 de zile sau daca lunile aprile, iunie, septembrie sau noiembrie au 31 de zile, se repeta citirea zilei si a lunii.  ***********/

    while ( (zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || ( strcmp(zi, "31") == 0 && ( strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0 ) ) )
    {
        cout << "\nIntroduceti o zi si o luna valida!";
        cout << "\n               Zi(ZZ): ";
        dev >> zi;

        while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' && zi[0] < '0' ) || ( zi[1] > '9' && zi[1] < '0' ))
        {
            cout << "\nIntroduceti o zi valida!(ZZ)";
            cout << "\n               Zi(ZZ): ";
            dev >> zi;
        }

        cout << "\n               Luna(LL): ";
        dev >> luna;

        while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
        {
            cout << "\nIntroduceti o luna valida!(LL)";
            cout << "\n               Luna(LL): ";
            dev >> luna;
        }
    }

    cout << "\n               An(AAAA): ";

    dev >> an;
    unsigned AN = atoi(an);
    time_t t = time(NULL);
    tm * timePtr = localtime(&t);
    /*********** Daca anul nu are 4 cifre sau daca contine alte caractere decat cifre, se repeta citirea. ***********/

    while (strlen(an) != 4 || timePtr->tm_year + 1900 - AN < 18 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
    {
        cout << "\nIntroduceti un an valid!(AAAA)";
        cout << "\n               An(AAAA): ";
        dev >> an;
        unsigned AN = atoi(an);
    }

    d = atoi(an); // transform anul in INT ca sa pot verifica daca e an bisect

    /*********** Daca nu e an bisect si februarie are 29 de zile, se repeta intreaga citire. ***********/

    while (d % 4 != 0 && strcmp(luna, "02") == 0 && strcmp(zi, "29") == 0)
    {
        cout << "\nIntroduceti o data valida!(ZZ/LL/AAAA)";
        cout << "\n               Zi(ZZ): ";
        dev >> zi;

        while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' && zi[0] < '0' ) || ( zi[1] > '9' && zi[1] < '0' ))
        {
            cout << "\nIntroduceti o zi valida!(ZZ)";
            cout << "\n               Zi(ZZ): ";
            dev >> zi;
        }

        cout << "\n               Luna(LL): ";
        dev >> luna;

        while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
        {
            cout << "\nIntroduceti o luna valida!(LL)";
            cout << "\n               Luna(LL): ";
            dev >> luna;
        }

        while ( (zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || ( strcmp(zi, "31") == 0 && ( strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0) ) )
        {
            cout << "\nIntroduceti o zi si o luna valida!";
            cout << "\n               Zi(ZZ): ";
            dev >> zi;

        while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' && zi[0] < '0' ) || ( zi[1] > '9' && zi[1] < '0' ))
            {
                cout << "\nIntroduceti o zi valida!(ZZ)";
                cout << "\n               Zi(ZZ): ";
                dev >> zi;
            }

            cout << "\n               Luna(LL): ";
            dev >> luna;

            while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
            {
                cout << "\nIntroduceti o luna valida!(LL)";
                cout << "\n               Luna(LL): ";
                dev >> luna;
            }
        }

        cout << "\n               An(AAAA): ";

        dev >> an;

        unsigned AN = atoi(an);
        time_t t = time(NULL);
        tm *timePtr = localtime(&t);

        while (strlen(an) != 4 || timePtr->tm_year + 1900 - AN < 18 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
        {
            cout << "\nIntroduceti un an valid!(AAAA)";
            cout << "\n               An(AAAA): ";
            dev >> an;
            unsigned AN = atoi(an);
        }
        d = atoi(an);
    }

    strcpy(Data_Nasterii, zi);
    strcat(Data_Nasterii, "/");
    strcat(Data_Nasterii, luna);
    strcat(Data_Nasterii, "/");
    strcat(Data_Nasterii, an);


    /********* DATA ANGAJARII *********/


    cout << "\nData Angajarii(ZZ/LL/AAAA): ";

    cout << "\n               Zi(ZZ): ";
    dev >> zi;

    /***********  Daca ziua nu are 2 cifre, daca prima cifra >= 4 sau daca contine alte caractere decat cifre, se repeta citirea zilei.  ***********/


    while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' || zi[0] < '0' ) || ( zi[1] > '9' || zi[1] < '0' ))
    {
        cout << "\nIntroduceti o zi valida!(ZZ)";
        cout << "\n               Zi(ZZ): ";
        dev >> zi;
    }

    cout << "\n               Luna(LL): ";
    dev >> luna;

    /*********** Daca luna nu are 2 cifre, daca are prima cifra >= 2, daca luna e >= 13 sau daca contine alte caractere decat cifre, se repeta citirea lunii. ***********/

    while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
    {
        cout << "\nIntroduceti o luna valida!(LL)";
        cout << "\n               Luna(LL): ";
        dev >> luna;
    }

    /*********** Daca luna 02 (adica februarie) are mai mult de 29 de zile sau daca lunile aprile, iunie, septembrie sau noiembrie au 31 de zile, se repeta citirea zilei si a lunii.  ***********/

    while ( (zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || ( strcmp(zi, "31") == 0 && ( strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0 ) ) )
    {
        cout << "\nIntroduceti o zi si o luna valida!";
        cout << "\n               Zi(ZZ): ";
        dev >> zi;

        while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' && zi[0] < '0' ) || ( zi[1] > '9' && zi[1] < '0' ))
        {
            cout << "\nIntroduceti o zi valida!(ZZ)";
            cout << "\n               Zi(ZZ): ";
            dev >> zi;
        }

        cout << "\n               Luna(LL): ";
        dev >> luna;

        while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
        {
            cout << "\nIntroduceti o luna valida!(LL)";
            cout << "\n               Luna(LL): ";
            dev >> luna;
        }
    }

    cout << "\n               An(AAAA): ";

    dev >> an;

    /*********** Daca anul nu are 4 cifre sau daca contine alte caractere decat cifre, se repeta citirea. ***********/

    while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
    {
        cout << "\nIntroduceti un an valid!(AA)";
        cout << "\n               An(AAAA): ";
        dev >> an;
    }

    d = atoi(an); // transform anul in INT ca sa pot verifica daca e an bisect

    /*********** Daca nu e an bisect si februarie are 29 de zile, se repeta intreaga citire. ***********/

    while (d % 4 != 0 && strcmp(luna, "02") == 0 && strcmp(zi, "29") == 0)
    {
        cout << "\nIntroduceti o data valida!(ZZ/LL/AAAA)";
        cout << "\n               Zi(ZZ): ";
        dev >> zi;

        while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' && zi[0] < '0' ) || ( zi[1] > '9' && zi[1] < '0' ))
        {
            cout << "\nIntroduceti o zi valida!(ZZ)";
            cout << "\n               Zi(ZZ): ";
            dev >> zi;
        }

        cout << "\n               Luna(LL): ";
        dev >> luna;

        while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
        {
            cout << "\nIntroduceti o luna valida!(LL)";
            cout << "\n               Luna(LL): ";
            dev >> luna;
        }

        while ( (zi[0] == '3' && luna[0] == '0' && luna[1] == '2') || ( strcmp(zi, "31") == 0 && ( strcmp(luna, "04") == 0 || strcmp(luna, "06") == 0 || strcmp(luna, "09") == 0 || strcmp(luna, "11") == 0) ) )
        {
            cout << "\nIntroduceti o zi si o luna valida!";
            cout << "\n               Zi(ZZ): ";
            dev >> zi;

        while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' && zi[0] < '0' ) || ( zi[1] > '9' && zi[1] < '0' ))
            {
                cout << "\nIntroduceti o zi valida!(ZZ)";
                cout << "\n               Zi(ZZ): ";
                dev >> zi;
            }

            cout << "\n               Luna(LL): ";
            dev >> luna;

            while (strlen(luna) != 2 || luna[0] > '1' || (luna[0] == '1' && luna[1] > '2' ) || (luna[0] < '0' && luna[0] > '9') || (luna[1] < '0' && luna[1] > '9') )
            {
                cout << "\nIntroduceti o luna valida!(LL)";
                cout << "\n               Luna(LL): ";
                dev >> luna;
            }
        }

        cout << "\n               An(AAAA): ";

        dev >> an;

        while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
        {
            cout << "\nIntroduceti un an valid!(AA)";
            cout << "\n               An(AAAA): ";
            dev >> an;
        }
        d = atoi(an);
    }

    strcpy(Data_Angajarii, zi);
    strcat(Data_Angajarii, "/");
    strcat(Data_Angajarii, luna);
    strcat(Data_Angajarii, "/");
    strcat(Data_Angajarii, an);
}

istream &operator>>(istream &dev, Angajati &a)
{
    return a.citire(dev);
}

ostream & Angajati::afisare(ostream & dev)
{
    dev << "\nID: " << ID;
    dev << "\nNume: " << nume << "\nPrenume: " << prenume;
    dev << "\nData Nasterii: " << Data_Nasterii;
    dev << "\nData Angajarii: " << Data_Angajarii;
    dev << "\nCoeficient Salarial: " << Coeficient_Salarial;
    return dev;
}

ostream & operator<<(ostream & dev, Angajati & a)
{
    return a.afisare(dev);
}

float Angajati::getSalariu()
{
    int an_angajare = atoi(Data_Angajarii + 6);
    time_t t = time(NULL);
    tm * timePtr = localtime(&t);
    return (timePtr->tm_year + 1900 - an_angajare) * Coeficient_Salarial * 1000;
}

unsigned Angajati::getID()
{
    return ID;
}

void Angajati::setNume(char * nume)
{
    this->nume = strdup(nume);
}

void Angajati::setPrenume(char * prenume)
{
    this->prenume = strdup(prenume);
}

void Angajati::setDataAngajarii(char * DataAngajarii)
{
    strcpy(this->Data_Angajarii, DataAngajarii);
}

void Angajati::setDataNasterii(char * DataNasterii)
{
    strcpy(this->Data_Nasterii, DataNasterii);
}

float Angajati::getCoeficient()
{
    return Coeficient_Salarial;
}
