#include "Library.h"
#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <string>

using namespace std;

Book::Book (std::string idc, std::string t, std::string a)
{
    idCode = idc;
    title = t;
    author = a;
    int dateCheckedOut = 0;   
}

string Book::getIdCode ()
{
    return idCode;
}

string Book::getTitle ()
{
    return title;
}

string Book::getAuthor ()
{
    return author;
}

Locale Book::getLocation ()
{
    return location;
}

void Book::setLocation (Locale Lo)
{
    location = Lo;
}

Patron* Book::getCheckedOutBy ()
{
    return checkedOutBy;
}

void Book::setCheckedOutBy (Patron* p)
{
    checkedOutBy = p;
}

Patron* Book::getRequestedBy ()
{
    return requestedBy;
}

void Book::setRequestedBy (Patron* p)
{
    requestedBy = p;
}

int Book::getDateCheckedOut ()
{
    return dateCheckedOut;
}

void Book::setDateCheckedOut (int d)
{
    dateCheckedOut = d;
}
