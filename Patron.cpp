#include "Library.h"
#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Patron::Patron (std::string idn, std::string n)
{
    idNum = idn;
    name = n;
    double fineAmount = 0; 
}

string Patron::getIdNum ()
{
    return idNum;
}

string Patron::getName ()
{
    return name;
}

vector <Book*> Patron::getCheckedOutBooks ()
{
    return checkedOutBooks;	
}

void Patron::addBook (Book* b)
{
    checkedOutBooks.push_back(b);        
}

void Patron::removeBook (Book* b)
{
    for (int i = 0; i < checkedOutBooks.size(); i++)
    {
        if (checkedOutBooks[i] -> getIdCode() ==  b -> getIdCode())
        {
            checkedOutBooks.erase(checkedOutBooks.begin() + i);
        }
    }
}

double Patron::getFineAmount ()
{
    return fineAmount;    
}

void Patron::amendFine (double amount)
{
    fineAmount += amount;
}
