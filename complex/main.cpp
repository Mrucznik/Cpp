#include <iostream>
#include <regex>
#include "complex.hpp"

using namespace std;

class Calculator
{
private:
    const int range = 'z'-'a'+1;
    int zmiennaInt[range];
    double zmiennaDouble[range];
    Complex zmiennaComplex[range];
    enum eTypZmiennej
    {
        EMPTY,
        INT,
        DOUBLE,
        COMPLEX
    } typZmiennej[range];

    int GetIndex(char a)
    {
        int idx = 'z'-a;
        if(idx < 0 || idx > range)
            throw "Out of range exeption";
        return idx;
    }

    char GetName(int a)
    {
        return 'z'+a;
    }

    eTypZmiennej GetType(char name)
    {
        return typZmiennej[GetIndex(name)];
    }

    void wyswietlZmienne()
    {
        for(int i=0; i<range; i++)
        {
            switch(typZmiennej[i])
            {
                case INT:
                    cout << "Zmienna: int " << GetName(i) << " = " << cout << zmiennaInt[i] << endl;
                    break;
                case DOUBLE:
                    cout << "Zmienna: double " << GetName(i) << " = " << cout << zmiennaInt[i] << endl;
                    break;
                case COMPLEX:
                    cout << "Zmienna: Complex " << GetName(i) << " = " << cout << zmiennaInt[i] << endl;
                    break;
            }
        }
    }
public:
    //=, +=, -=, *=, /-, ==, !=, +, -, *, /, R - czesc rzeczywista, I - czesc urojona, A - amplituda, P - faza
    enum eDzialanie
    {
        NONE,
        PRZYPISZ,
        PRZYPISZ_PLUS,
        PRZYPISZ_MINUS,
        PRZYPISZ_RAZY,
        PRZYPISZ_DZIEL,
        CZYROWNE,
        NIEROWNE,
        PLUS,
        MINUS,
        RAZY,
        DZIEL,
        RZECZYWISTA,
        UROJONA,
        AMPLITUDA,
        FAZA
    };

    Calculator()
    {
        for(int i=0; i<range; i++)
        {
            typZmiennej[i] = EMPTY;
        }
    }

    void zapiszZmienna(char name, int a)
    {
        int idx = GetIndex(name);
        zmiennaInt[idx] = a;
        typZmiennej[idx] = INT;
    }

    void zapiszZmienna(char name, double a)
    {
        int idx = GetIndex(name);
        zmiennaDouble[idx] = a;
        typZmiennej[idx] = DOUBLE;
    }

    void zapiszZmienna(char name, Complex a)
    {
        int idx = GetIndex(name);
        zmiennaComplex[idx] = a;
        typZmiennej[idx] = COMPLEX;
    }

    void zapiszZmienna(char name, char zmienna)
    {
        switch(GetType(zmienna))
        {
            case INT:

                break;
            case DOUBLE:
                break;
            case COMPLEX:
                break;
        }
    }

    void getZmienna(char name, double& a)
    {

    }

    void getZmienna(char name, int& a)
    {

    }

    void getZmienna(char name, Complex& a)
    {

    }

    eTypZmiennej wybierzTypZapisu(char zmienna1, char zmienna2, char zmienna3)
    {
        if(GetType(zmienna1) == GetType(zmienna2) == GetType(zmienna3))
            return GetType(zmienna1);

        if(GetType(zmienna1) == COMPLEX || GetType(zmienna2) == COMPLEX || GetType(zmienna3) == COMPLEX)
            return COMPLEX;

        if(GetType(zmienna1) == DOUBLE || GetType(zmienna2) == DOUBLE || GetType(zmienna3) == DOUBLE)
            return DOUBLE;

        return INT;
    }

    void wykonajDzialanie(eDzialanie dzialanie, char wynik, char zmienna1, char zmienna2)
    {
        switch(dzialanie)
        {
            case PRZYPISZ:
                eTypZmiennej zapis = wybierzTypZapisu(wynik, zmienna1, zmienna2);
                if(zapis == INT)
                {

                }
                else if(zapis == DOUBLE)
                {

                }
                else if(zapis == COMPLEX)
                {

                }
                break;
        }
    }

    void oblicz(string wyrazenie)
    {

    }
};

int main()
{
    Calculator calc;
    cout << "--- Kalkulator liczb zespolonych ---" << endl;
    cout << "Instrukcja obslugi:" << endl;
    cout << "W wyrazeniach mozna uzywac zmiennych. Nazwa zmiennej musi byc pojedyncza litera z zakresu [a-u]" << endl;
    cout << "Aby stworzyc zmienna nalezy wpisac jej nazwe a potem w nawiasach podac jej wartosc. Dla zespolonych oddzielic wartosc rzeczywista i urojona przecinkiem." << endl;
    cout << "Aby wykonac dzialanie nalezy uzyc ktoregos z operatorw przypisania a nastepnie wpisac dzialanie. Jezeli brak operatora przypisania dzialanie zostanie przypisane do zmiennej z. Stale sa przypisywane do zmiennych x i y. Dostepne operatory:" << endl;
    cout << "=, +=, -=, *=, /-, ==, !=, +, -, *, /\noraz: R - czesc rzeczywista, I - czesc urojona, A - amplituda, P - faza" << endl;
    cout << "Mozna wykonywac tylko pojedyncze operacje na jedno wyrazenie. Aby zakonczyc dzialanie programu nalezy wpisac X" << endl;

    string wyrazenie;
    while(true)
    {
        cout << "Wpisz wyrazenie" << endl;
        cin >> wyrazenie;
        if(wyrazenie[0] == 'X')
        {
            cout << "Zakonczono dzialanie kalkulatora" << endl;
            break;
        }

        calc.oblicz(wyrazenie);
    }
}
