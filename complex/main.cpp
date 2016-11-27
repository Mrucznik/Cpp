#include <iostream>
#include <regex>
#include "complex.hpp"

using namespace std;

class Calculator
{
private:
    static const int range = 'z'-'a'+1;
    Complex zmienna[range];
    bool used[range];

    int GetIndex(char a)
    {
        int idx = a-'a';
        if(idx < 0 || idx > range)
            throw "Out of range exeption";
        return idx;
    }

    char GetName(int a)
    {
        return 'a'+(char)a;
    }

    enum eDzialanie
    {
        NONE,
        PRZYPISZ,
        PRZYPISZ_SUMA,
        PRZYPISZ_ROZNICA,
        PRZYPISZ_ILOCZYN,
        PRZYPISZ_ILORAZ,
        ROWNE,
        NIEROWNE,
        SUMA,
        ROZNICA,
        ILOCZYN,
        ILORAZ,
        RZECZYWISTA,
        UROJONA,
        AMPLITUDA,
        FAZA,
    };

    eDzialanie PobierzDzialanie(string dzialanie)
    {
        if(dzialanie == "=")
            return PRZYPISZ;
        else if (dzialanie == "+=")
            return PRZYPISZ_SUMA;
        else if (dzialanie == "-=")
            return PRZYPISZ_ROZNICA;
        else if (dzialanie == "*=")
            return PRZYPISZ_ILOCZYN;
        else if (dzialanie == "/=")
            return PRZYPISZ_ILORAZ;
        else if (dzialanie == "==")
            return ROWNE;
        else if (dzialanie == "!=")
            return NIEROWNE;
        else if (dzialanie == "+")
            return SUMA;
        else if (dzialanie == "-")
            return ROZNICA;
        else if (dzialanie == "*")
            return ILOCZYN;
        else if (dzialanie == "/")
            return ILORAZ;
        else if (dzialanie == "R")
            return RZECZYWISTA;
        else if (dzialanie == "U" || dzialanie == "I")
            return UROJONA;
        else if (dzialanie == "A")
            return AMPLITUDA;
        else if (dzialanie == "F" || dzialanie == "P")
            return FAZA;
        else
            return NONE;
    }
public:
    //Konstruktor
    Calculator()
    {
        for(int i=0; i<range; i++)
        {
            zmienna[i] = 0;
            used[i] = false;
        }
    }

    void wyswietlZmienne()
    {
        for(int i=0; i<range-3; i++)
        {
            if(used[i])
            {
                cout << "Zmienna: " << GetName(i) << " = " << zmienna[i] << endl;
            }
        }
    }

    //Metody
    void zapiszZmienna(char name, Complex a)
    {
        zmienna[GetIndex(name)] = a;
        used[GetIndex(name)] = true;
    }

    void zapiszZmienna(char name, char zrodlo)
    {
        zmienna[GetIndex(name)] = zmienna[GetIndex(zrodlo)];
        used[GetIndex(name)] = true;
    }

    void usunZmienna(char name)
    {
        used[GetIndex(name)] = false;
    }

    void wykonajDzialanie(eDzialanie dzialanie, char zmienna1, char zmienna2)
    {
        switch(dzialanie)
        {
            case PRZYPISZ:
                zapiszZmienna(zmienna1, zmienna2);
                break;
            case PRZYPISZ_SUMA:
                zmienna[GetIndex(zmienna1)] += zmienna[GetIndex(zmienna2)];
                used[GetIndex(zmienna1)] = true;
                break;
            case PRZYPISZ_ROZNICA:
                zmienna[GetIndex(zmienna1)] -= zmienna[GetIndex(zmienna2)];
                used[GetIndex(zmienna1)] = true;
                break;
            case PRZYPISZ_ILOCZYN:
                zmienna[GetIndex(zmienna1)] *= zmienna[GetIndex(zmienna2)];
                used[GetIndex(zmienna1)] = true;
                break;
            case PRZYPISZ_ILORAZ:
                zmienna[GetIndex(zmienna1)] /= zmienna[GetIndex(zmienna2)];
                used[GetIndex(zmienna1)] = true;
                break;
            case ROWNE:
                zmienna[GetIndex(zmienna1)] = zmienna[GetIndex(zmienna1)] == zmienna[GetIndex(zmienna2)] ? Complex(1) : Complex(0);
                used[GetIndex(zmienna1)] = true;
                break;
            case NIEROWNE:
                zmienna[GetIndex(zmienna1)] = zmienna[GetIndex(zmienna1)] != zmienna[GetIndex(zmienna2)] ? Complex(1) : Complex(0);
                used[GetIndex(zmienna1)] = true;
                break;
            case SUMA:
                zmienna[GetIndex('z')] = zmienna[GetIndex(zmienna1)] + zmienna[GetIndex(zmienna2)];
                break;
            case ROZNICA:
                zmienna[GetIndex('z')] = zmienna[GetIndex(zmienna1)] - zmienna[GetIndex(zmienna2)];
                break;
            case ILOCZYN:
                zmienna[GetIndex('z')] = zmienna[GetIndex(zmienna1)] * zmienna[GetIndex(zmienna2)];
                break;
            case ILORAZ:
                zmienna[GetIndex('z')] = zmienna[GetIndex(zmienna1)] / zmienna[GetIndex(zmienna2)];
                break;
            case RZECZYWISTA:
                zmienna[GetIndex('z')] = zmienna[GetIndex(zmienna1)].getReal();
                break;
            case UROJONA:
                zmienna[GetIndex('z')] = Complex(0, zmienna[GetIndex(zmienna1)].getImaginary());
                break;
            case AMPLITUDA:
                zmienna[GetIndex('z')] = zmienna[GetIndex(zmienna1)].getAmplitude();
                break;
            case FAZA:
                zmienna[GetIndex('z')] = zmienna[GetIndex(zmienna1)].getPhase();
                break;
            default:
                cout << "Brak znaku dzialania" << endl;
                break;
        }
    }

    void zapiszStala(char name, string matching)
    {
        regex zmienna("^([a-z])$");
        regex rzeczywista("^(\\-?(?:\\d*\\.)?\\d+)$");
        regex complex("^\\((\\-?(?:\\d*\\.)?\\d+)\\s*\\,\\s*(\\-?(?:\\d*\\.)?\\d+)\\)$");
        smatch stala;
        if(regex_search(matching, stala, zmienna))
        {
            zapiszZmienna(name, stala.str(1)[0]);
        }
        else if(regex_search(matching, stala, complex))
        {
            zapiszZmienna(name, Complex(stod(stala.str(1)), stod(stala.str(2))));
        }
        else if(regex_search(matching, stala, rzeczywista))
        {
            zapiszZmienna(name, Complex(stod(stala.str(1)), 0));
        }
        else
        {
            throw "Cos poszlo nie tak z wykrywaniem stalej: " + matching;
        }
    }

    void oblicz(string wyrazenie)
    {
        try
        {
            char wynik;
            regex headRegex("^([a-z])\\s*(=|\\+=|-=|\\*=|\\/=|==|!=)\\s*([a-z]|(?:\\-?(?:\\d*\\.)?\\d+)|\\((?:\\-?(?:\\d*\\.)?\\d+)\\s*\\,\\s*(?:\\-?(?:\\d*\\.)?\\d+)\\))(?:(?:\\s*(\\+|\\-|\\*|\\/)\\s*([a-z]|(?:\\-?(?:\\d*\\.)?\\d+)|\\((?:\\-(?:\\d*\\.)?\\d+)\\s*\\,\\s*(?:\\-?(?:\\d*\\.)?\\d+)\\)))|(R|I|U|A|F|P|D))?$");
            smatch match;

            if(regex_search(wyrazenie, match, headRegex))
            {
                if(match.str(4).length() < 1 && match.str(6).length() < 1)
                {
                    wynik = match.str(1)[0];
                    eDzialanie dzialanie = PobierzDzialanie(match.str(2));
                    zapiszStala('x', match.str(3));
                    wykonajDzialanie(dzialanie, wynik, 'x');
                }
                else if(match.str(5).length() >= 1)
                {
                    wynik = match.str(1)[0];
                    eDzialanie dzialanie1 = PobierzDzialanie(match.str(2));
                    zapiszStala('x', match.str(3));
                    eDzialanie dzialanie2 = PobierzDzialanie(match.str(4));
                    zapiszStala('y', match.str(5));

                    wykonajDzialanie(dzialanie2, 'x', 'y');
                    wykonajDzialanie(dzialanie1, wynik, 'z');
                }
                else if(match.str(6).length() >= 1)
                {
                    wynik = match.str(1)[0];
                    eDzialanie dzialanie1 = PobierzDzialanie(match.str(2));
                    zapiszStala('x', match.str(3));
                    eDzialanie dzialanie2 = PobierzDzialanie(match.str(6));

                    wykonajDzialanie(dzialanie2, 'x', 'x');
                    wykonajDzialanie(dzialanie1, wynik, 'z');
                    cout << "ZASKOCZYLO";
                }
                else
                {
                    cout << "Cos poszlo nie tak! Sprawdz czy masz odpowiednia ilosc skladnikow! wykryto:" << match.size() << endl;
                    return;
                }

                cout << "Wynik operacji: " << zmienna[GetIndex(wynik)] << endl;
            }
            else
            {
                cout << "Cos poszlo nie tak! Sprawdz czy poprawnie wpisales wyrazenie." << endl;
            }
        }
        catch (std::regex_error& e)
        {
            cout << "Regex syntax error!";
        }catch (std::string e)
        {
            cout << "Exeption: " << e;
        }
    }
};

int main()
{
    Calculator calc;
    cout << "Instrukcja obslugi:" << endl;
    cout << "W wyrazeniach mozna uzywac zmiennych. Nazwa zmiennej musi byc pojedyncza litera z zakresu [a-u]" << endl;
    cout << "Aby wykonac dzialanie nalezy uzyc ktoregos z operatorw przypisania a nastepnie wpisac dzialanie." << endl;
    cout << "Dostepne operatory:" << endl;
    cout << "=, +=, -=, *=, /=, ==, !=, +, -, *, /\noraz: R - czesc rzeczywista, I - czesc urojona, A - amplituda, P - faza, D - usuwa zmienna\n(operatory literalowe sa operatorami przyrostkowymi)" << endl;
    cout << "Aby wyswietlic wszystkie zmienne wpisz W. Aby zakonczyc dzialanie programu nalezy wpisac X." << endl;
    cout << "Przykladowa operacja: a = 5 + (10, 5)" << endl << endl;

    string wyrazenie;
    while(true)
    {
        cout << endl << "--- Kalkulator liczb zespolonych ---" << endl;
        cout << "Wpisz wyrazenie" << endl;
        getline(cin, wyrazenie);
        if(wyrazenie[0] == 'X')
        {
            cout << "Zakonczono dzialanie kalkulatora" << endl;
            break;
        }
        else if(wyrazenie[0] == 'W')
        {
            system("cls");
            calc.wyswietlZmienne();
            continue;
        }
        else if(wyrazenie[0] >= 'a' && wyrazenie[0] <= 'z' && wyrazenie[1] == 'D')
        {
            calc.usunZmienna(wyrazenie[0]);
        }

        calc.oblicz(wyrazenie);
    }
    getchar();
    return 0;
}
