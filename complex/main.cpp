#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
#include "complex.hpp"


void wait();
void menu(double, double, double, double);

int main()
{


    double AReal = 0, AImag = 0, BReal = 0, BImag = 0;
    cout << "Podaj czesc rzeczywista i urojona Complexa A" << endl;
    cin >> AReal;
    cin >> AImag;
    cout << " Podaj czesc rzeczywista i urojona Complexa B" << endl;
    cin >> BReal;
    cin >> BImag;

    menu(AReal, AImag, BReal, BImag);
    return 0;
}

void wait()
{
    cout << "Nacisnij dowolny klawisz aby worcic" << endl;
    cin.ignore(1024, '\n');
    cin.get();
}

void menu(double AReal, double AImag, double BReal, double BImag)
{
    Complex A(AReal, AImag);
    Complex B(BReal, BImag);
    int warunek = 0;
    do
    {
        system("clear");
        cout << "MENU:" << endl;
        cout << "Complex A = " << A << "  " << "Complex B = " << B << endl;
        cout << "1 - f. Zwracajaca czesc rzeczywista" << endl;
        cout << "2 - f. Zwracajaca czesc urojona" << endl;
        cout << "3 - f. Liczaca Amplitude" << endl;
        cout << "4 - f. Liczaca Faze" << endl;
        cout << "5 - Wykonaj operacje A + B" << endl;
        cout << "6 - Wykonaj operacje A += B" << endl;
        cout << "7 - Wykonaj operacje A - B" << endl;
        cout << "8 - Wykonaj operacje A -= B" << endl;
        cout << "9 - Wykonaj operacje A * B" << endl;
        cout << "10 - Wykonaj operacje A *= B" << endl;
        cout << "11 - Wykonaj operacje A / B" << endl;
        cout << "12 - Wykonaj operacje A /= B" << endl;
        cout << "13 - Wykonaj operacje A == B" << endl;
        cout << "14 - Przypisz wartosc do A z B lub do B z A" << endl;
        cout << "15 - Zakoncz" << endl;

        cin >> warunek;

        switch (warunek)
        {
            case 1:
                int ktory;

                system("clear");
                cout << "Complex A - 1 B - 2" << endl;
                cin >> ktory;

                if (ktory == 1) cout << "Real z A = " << A.getReal() << endl;
                else if (ktory == 2) cout << "Real z B = " << B.getReal() << endl;
                else cout << "Cos poszlo nie tak";

                wait();
                break;
            case 2:

                system("clear");
                cout << "Complex A - 1 B - 2" << endl;
                cin >> ktory;

                if (ktory == 1) cout << "Imag z A = " << A.getImaginary() << endl;
                else if (ktory == 2) cout << "Imag z B = " << B.getImaginary() << endl;
                else cout << "Cos poszlo nie tak";

                wait();
                break;
            case 3:

                system("clear");
                cout << "Complex A - 1 B - 2" << endl;
                cin >> ktory;

                if (ktory == 1) cout << "Amplituda z A = " << A.getAmplitude() << endl;
                else if (ktory == 2) cout << "Amplituda z B = " << B.getAmplitude() << endl;
                else cout << "Cos poszlo nie tak";

                wait();
                break;
            case 4:


                system("clear");
                cout << "Complex A - 1 B - 2" << endl;
                cin >> ktory;

                if (ktory == 1) cout << "Faza z A = " << A.getPhase() << endl;
                else if (ktory == 2) cout << "Imag z B = " << B.getPhase() << endl;
                else cout << "Cos poszlo nie tak";

                wait();
                break;
            case 5:

                system("clear");
                cout << "Complex A + B = " << A + B << endl;

                wait();
                break;

            case 6:

                system("clear");

                A += B;
                cout << "Complex A += B = " << A << endl;

                wait();
                break;
            case 7:

                system("clear");
                cout << "Complex A - B = " << A - B << endl;

                wait();
                break;

            case 8:

                system("clear");

                A -= B;
                cout << "Complex A -= B = " << A << endl;

                wait();
                break;

            case 9:

                system("clear");

                cout << "Complex A * B = " << A*B << endl;

                wait();
                break;

            case 10:

                system("clear");

                if (AReal == 0.0 || AImag == 0.0) cout << "Niestety Real i Imag Complexa musi byæ != 0" << endl;
                else
                {
                    A *= B;
                    cout << "Complex A *= B = " << A << endl;
                }

                wait();
                break;

            case 11:

                system("clear");


                cout << "Complex A / B = " << A / B << endl;

                wait();
                break;

            case 12:

                system("clear");

                if (AReal == 0.0 || AImag == 0.0) cout << "Niestety Real i Imag Complexa A musi byæ != 0" << endl;
                else
                {
                    A /= B;
                    cout << "Complex A - B = " << A << endl;
                }
                wait();
                break;

            case 13:

                system("clear");

                if (A == B)
                    cout << "A == B" << endl;
                else
                    cout << "A != B" << endl;

                wait();
                break;

            case 14:

                system("clear");
                cout << "Complex A - 1 B - 2" << endl;
                cin >> ktory;

                if (ktory == 1)
                {
                    A = B;
                    cout << "Teraz A = B" << endl;
                }
                else if (ktory == 2)
                {
                    B = A;
                    cout << "teraz B = A" << endl;
                }
                else cout << "Cos poszlo nie tak";

                wait();
                break;

            default:

                break;
        };

    } while (warunek != 15);

}