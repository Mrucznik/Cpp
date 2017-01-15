#include <iostream>
using namespace std;
#include "Map.h"

int main()
{
    Map a1, a2;
    a1["ala"] = 1;
    a1["ola"] = 2;
    cout << a1["ala"] << " " << a1["ola"] << " " << a1["ula"] << endl;
    a2 = a1;
    a2["ula"]+=4;
    cout << a2["ala"] << " " << a2["ola"] << " " << a2["ula"] << endl;

    cout << "Moje testy:" << endl;
    MapCaseInsensitive insensitive;
    MapCaseSensitive sensitive;

    sensitive["ala"] = 5;
    sensitive["Ala"] += 3;

    insensitive["ala"] = 5;
    insensitive["Ala"] += 3;

    cout << "Case sensitive ala and Ala: " << sensitive["ala"] << " and " << sensitive["Ala"] << endl;
    cout << "Case insensitive ala and Ala: " << insensitive["ala"] << " and " << insensitive["Ala"] << endl;
    return 0;
}