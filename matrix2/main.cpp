#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

#define DW(__instruction) cout << #__instruction << "==" << (__instruction) << endl;

Matrix loadMatrixFromFile(const char* filename)
{
    ifstream stream;
    stream.open(filename, ifstream::in);
    if(stream.good())
    {
        Matrix m(stream);
        stream.close();
        return m;
    }
    else
    {
        cout << "Nie udalo sie zaladowac macierzy";
        throw "File Error";
    }
}

int main()
{
    try
    {
        Matrix m1 = loadMatrixFromFile("matrix1.txt");
        Matrix m2 = loadMatrixFromFile("matrix2.txt");
        Matrix m3 = loadMatrixFromFile("matrix3.txt");
        Matrix m4 = loadMatrixFromFile("matrix4.txt");
        cout << "---------------------Wczytano 4 macierze:\n" << m1 << m2 << m3 << m4;

        cout << "\n\n\n---------------------Wykonywanie dodwania macierzy 1 i 2:\n";
        DW(m1+m2);
        DW(m1);
        DW(m2);
        DW(m1+=m2);
        DW(m1);
        DW(m2);

        cout << "\n\n\n---------------------Wykonywanie odejmowania macierzy 1 i 2:\n";
        DW(m1-m2);
        DW(m1);
        DW(m2);
        DW(m1-=m2);
        DW(m1);
        DW(m2);

        cout << "\n\n\n---------------------Wykonywanie mnozenia macierzy 1 i 3:\n";
        DW(m1*m3);
        DW(m1);
        DW(m3);
        DW(m1*=m3);
        DW(m1);
        DW(m3);

        cout << "\n\n\n---------------------Test operatora przypisania i porownania:\n";
        cout << m3 << m4;
        DW(m3=m4);
        cout << m3 << m4;
        DW(m3==m4);
        DW(m3!=m4);
        DW(m1==m4);
        DW(m2==m2);

        cout << "\n\n\n---------------------Dostep do pojedynczego elementu:\n";
        DW(m3(0, 0));
        DW(m3(2, 1));
        DW(m3(1, 2));

        cout << "\n\n\n---------------------Rozroznanie pomiedzy operacja zapisu a odczytu - do sprawdzenia potrzebny debugger:\n";
        m3(0, 0) = 5;
        if(m3(0, 0) == 5)
        {
            m3(1, 1) = m3(0, 0);
        }

        cout << "\n\n\nZle wyrazenia:\n";
        //DW(m3(1, 3)); //out of range
        //DW(m4*m2); //zle wymiary do mnozenia
        //DW(m4*=m2); //zle wymiary do mnozenia
        //DW(m1+m3); //zle wymiary do dodawania
        //DW(m1-m2); //zle wymiary do odejmowania
        //DW(m1*=m2); //zle wymiary do mnozenia
        //DW(m1+=m3); //zle wymiary do dodawania
        //DW(m1-=m2); //zle wymiary do odejmowania
    }
    catch (string exception)
    {
        cout << exception;
    }
    catch (Exception e)
    {
        cout << e.name;
    }

    return 0;
}