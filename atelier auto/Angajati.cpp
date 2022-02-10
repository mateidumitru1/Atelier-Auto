#include "Angajati.h"

Angajati::Angajati()
{
    ID[0] = '\0';
    Data_Nasterii[0] = '\0';
    Data_Angajarii[0] = '\0';
    nume = NULL;
    prenume = NULL;
    Coeficient_Salarial = 0;
}

Angajati::Angajati(const char id[], const char data_n[], const char data_a[], const char *nume, const char *prenume)
{
    strcpy(ID, id);
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
    strcpy(ID, a.ID);
    strcpy(Data_Nasterii, a.Data_Nasterii);
    strcpy(Data_Angajarii, a.Data_Angajarii);
    nume = strdup(a.nume);
    prenume = strdup(a.prenume);
    Coeficient_Salarial = a.Coeficient_Salarial;
    return *this;
}

istream &Angajati::citire(istream &dev)
{
    cout << "\nID: ";   /********** ID INCREMENTAT TO DO ***********/
    dev >> ID;

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

    cout << "\nData Nasterii: ";

    char zi[3], luna[3], an[5];

    int d;

    cout << "\n               Zi(ZZ): ";
    dev >> zi;

    while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' || zi[0] < '0' ) || ( zi[1] > '9' || zi[1] < '0' ))
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

    cin >> an;

    while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
    {
        cout << "\nIntroduceti un an valid!(AA)";
        cout << "\n               An(AAAA): ";
        dev >> an;
    }

    d = atoi(an);

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

        cin >> an;

        while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
        {
            cout << "\nIntroduceti un an valid!(AA)";
            cout << "\n               An(AAAA): ";
            dev >> an;
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

    while (strlen(zi) != 2 || zi[0] > '3' || (zi[0] == '3' && zi[1] > '1') || ( zi[0] > '9' || zi[0] < '0' ) || ( zi[1] > '9' || zi[1] < '0' ))
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

    cin >> an;

    while (strlen(an) != 4 || (an[0] < '0' || an[0] > '9' ) || (an[1] < '0' || an[1] > '9' ) || (an[2] < '0' || an[2] > '9' ) || (an[3] < '0' || an[3] > '9' ) )
    {
        cout << "\nIntroduceti un an valid!(AA)";
        cout << "\n               An(AAAA): ";
        dev >> an;
    }

    d = atoi(an);

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

        cin >> an;

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

char * Angajati::getID()
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
