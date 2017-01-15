#include <iostream>
#include "Employee.h"													//Defines class Employee
#include "Book.h"
#include "Map.h"														//Defines template Map<Key, Value>

using namespace std;

int main(void) {
    typedef unsigned int ID; 											//Identification number of Employee
    Map<ID, Employee> database;											//Database of employees

    database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
    database.add(510212881, Employee("Adam Nowak", "storekeeper", 54)); //Add second employee: name: Adam Nowak, position: storekeeper, age: 54
    database.add(730505129, Employee("Anna Zaradna", "secretary", 32)); //Add third employee: name: Anna Zaradna, position: secretary, age: 32

    cout << database << endl;											//Print database

    Map<ID, Employee> newDatabase = database;							//Make a copy of database

    Employee* pE;
    pE = newDatabase.find(510212881);									//Find employee using its ID
    pE->position = "salesman";											//Modify the position of employee
    pE = newDatabase.find(761028073);									//Find employee using its ID
    pE->age = 29;														//Modify the age of employee

    database = newDatabase;												//Update original database

    cout << database << endl;											//Print original database

    Map<string, Book> library;
    library.add("Prawo", Book("F. Bastiat", "Nauki spoleczne", 69, false));
    library.add("Interwencjonizm, czyli wladza a rynek", Book("Murray Newton Rothbard", "Anarchokapitalizm, Austriacka Szkola Ekonomii", 364, true));
    library.add("Dziewczyna z pociagu", Book("Paula Hawkins", "Thriller/sensacja/kryminal", 0, false));

    cout << library << endl;

    Map<string, Book> newLibrary = library;
    Book* book;
    book = newLibrary.find("Prawo");
    book->category = "Prawo";
    book = newLibrary.find("Dziewczyna z pociagu");
    book->pages = 328;

    library = newLibrary;
    cout << library << endl;
};
