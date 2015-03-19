#include "Library.h"  //For library header file.
#include "Book.h"  //For Book header file.
#include "Patron.h"  //For Patron header file.
#include <iostream>  //For input/output stream.
#include <vector>  //For vector and functions.

using namespace std;

Library::Library ()
{
    std::vector<Book> holdings;
    std::vector<Patron> members;
    int currentDate = 0;
}

/*********************************************************************
** Function:  addBook
** Description:  A function that adds a Book object to the holdings 
** vector.
** Parameters: Three strings.
** Pre-Conditions: Three strings.
** Post-Conditions:  A Book object is added to the holdings vector.
*********************************************************************/

void Library::addBook ()
{
    string idc, t, a;

    cout << endl << endl << "Enter the book's id code: ";
	cin >> idc;
	
    cout << endl << endl << "Enter the book's title: ";
    cin >> t;
	
    cout << endl << endl << "Enter the book's author: ";
	cin >> a;
	

    Book book = Book (idc, t, a);
	
    book.setLocation(ON_SHELF);
    book.setRequestedBy(NULL);
	
    holdings.push_back (book);

}

/*********************************************************************
** Function:  addMember
** Description:  A function that adds a Patron object to the members 
** vector.
** Parameters: Two strings.
** Pre-Conditions: Two strings.
** Post-Conditions:  A Patron object is added to the members vector.
*********************************************************************/

void Library::addMember ()
{
    string idn, n;
	
    cout << endl << endl << "Enter your id number: ";
	cin >> idn;
	
    cout << endl << endl << "Enter your name: ";
	cin >> n;

    Patron patron = Patron (idn, n);
	
    members.push_back (patron);

}

/*********************************************************************
** Function:  checkOutBook
** Description:  A function that assigns a book object to a patron and
** updates the corresponding information
** Parameters: Two strings.
** Pre-Conditions: Two strings.
** Post-Conditions:  A Book object is assigned to a patron and the
** corresponding info is updated.
*********************************************************************/

void Library::checkOutBook (std::string patronID, std::string bookID)
{
    Patron* p;
    Book* b;
	
    for (int i = 0; i < members.size(); i++)
    {
        if (patronID == members[i].getIdNum())
		{
            p = &members[i];
            break;
		}
    }
    if (p == NULL)
	{
        cout << endl << endl << "That patron is not in the library system.";
        return;
    }

    for (int i = 0; i < holdings.size(); i++)
    {
        if (bookID == holdings[i].getIdCode())
		{
            b = &holdings[i];
            break;
		}
    }
    if (b == NULL)
	{
        cout << endl << endl << "That book is not in the library system.";
        return;
    }

    if (b -> getLocation() == CHECKED_OUT)
    {
        cout << endl << endl << "That book is already checked out.";
        return;
	}
    if (b -> getLocation() == ON_HOLD)
    {
        cout << endl << endl << "This book is on hold by another patron";
		return;
    }
	
    if (b -> getLocation() == ON_HOLD)
        b -> setRequestedBy(NULL);

    b -> setCheckedOutBy(p);
	b -> setDateCheckedOut(currentDate);
    b -> setLocation(CHECKED_OUT);
	
    p -> addBook(b);
	
    cout << endl << endl << b -> getTitle() << " has been checked out to " << p -> getName() << ".";

}

/*********************************************************************
** Function:  returnBook
** Description:  A function that takes in a bookID code and 
** updates the corresponding information in the Book and Patron objects.
** Parameters: A string.
** Pre-Conditions: A string.
** Post-Conditions:  Corresponding book and patron information is 
** updated.
*********************************************************************/

void Library::returnBook (std::string bookID)
{
    Book* b;
    Patron* p;

    for (int i = 0; i < holdings.size(); i++)
    {
        if (bookID == holdings[i].getIdCode())
        {
            b = &holdings[i];
            break;
		}
    }
    if (b == NULL)
    {
        cout << endl << endl << "That book is not in the library system.";
        return;
    }
    
	if (b -> getLocation() != CHECKED_OUT)
    {
        cout << endl << endl << "That book is not checked out.";
		return;    
    }
	
    p = b -> getCheckedOutBy();
    p -> removeBook(b);
	
    cout << endl << endl << b -> getTitle() << " has been returned.";
    
}

/*********************************************************************
** Function:  requestBook
** Description:  A function that takes in a bookID code and patronID
**  and updates the corresponding information to put the book on hold
** for the patron.
** Parameters: Two strings.
** Pre-Conditions: Two strings.
** Post-Conditions:  the corresponding information to put the book on 
** hold for the patron.
*********************************************************************/

void Library::requestBook (std::string patronID, std::string bookID)
{
    Patron* p;
    Book* b;
	
    for (int i = 0; i < members.size(); i++)
    {
        if (patronID == members[i].getIdNum())
		{
            p = &members[i];
            break;
		}
    }
    if (p == NULL)
	{
        cout << endl << endl << "That patron is not in the library system.";
        return;
    }

    for (int i = 0; i < holdings.size(); i++)
    {
        if (bookID == holdings[i].getIdCode())
		{
            b = &holdings[i];
            break;
		}
    }
    if (b == NULL)
	{
        cout << endl << endl << "That book is not in the library system.";
        return;
    }
	
    for (int i = 0; i < holdings.size(); i++)
    {
        if (holdings[i].getRequestedBy() != NULL)
        {
            cout << endl << endl << "This book is already on request by another member.";
            return;
        }
    }
	
    b -> setRequestedBy(p);
	
    if (b -> getLocation() == ON_SHELF)
        b -> setLocation(ON_HOLD);
	
    cout << endl << endl << b -> getTitle() << " is on request for " << p -> getName();
    
}

/*********************************************************************
** Function:  payFine
** Description:  A function that makes a paymet to a patron's fine.
** Parameters: A string and a double.
** Pre-Conditions: A string and a double.
** Post-Conditions:  Amends patronID's fine w/ payment amount.
*********************************************************************/

void Library::payFine (std::string patronID, double payment)
{
    Patron* p;
	
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].getIdNum() == patronID)
        {
            p = &members[i];
            break;
        }
    }

    if (p == NULL)
    {
        cout << endl << endl << "That patron is not in the library system.";
        return;
    }

    p -> amendFine(0 - payment);
   
    cout << endl << endl << p -> getName() << " fines are now " << p -> getFineAmount() << ".";
    
}

/*********************************************************************
** Function:  incrementCurrentDate
** Description:  A function that increments currentDate and increases
** each patron's fines by DAILY_FINE.
** Parameters: None
** Pre-Conditions: currentDate
** Post-Conditions:  Increments currentDate and increases each 
** patron's fines by DAILY_FINE.
*********************************************************************/

void Library::incrementCurrentDate()
{
    currentDate++;
    cout << endl << endl << "Current date is now: " << currentDate << ".";
	
    for (int i = 0; i < members.size(); i++)
    {
        for (int j = 0; j < members[i].getCheckedOutBooks().size(); j++ )
        {
            if (members[i].getCheckedOutBooks()[j] -> getDateCheckedOut() > Book::CHECK_OUT_LENGTH)
            {
                members[i].amendFine(DAILY_FINE);
            }
        }
    } 
}

/*********************************************************************
** Function:  viewPatronInfo
** Description:  A function that takes in a patron'd id, retrieves,
** and outputs relative information.
** Parameters: A string.
** Pre-Conditions: A string.
** Post-Conditions:  Outputs relative information.
*********************************************************************/

void Library::viewPatronInfo (std::string patronID)
{
    Patron* p;
	
    for (int i = 0; i < members.size(); i++)
    {
        if (patronID == members[i].getIdNum())
        {
            p = &members[i];
            break;
        }
    }
	
    if (p == NULL)
    {
        cout << endl << endl << "That patron is not in the library system.";
        return;   
    }
    cout << endl << endl << "Patron's id: " << p -> getIdNum() << ".";
    cout << endl << endl << "Patron's name: " << p -> getName() << ".";
    cout << endl << endl << "Patron's checked out: ";
    for (int i = 0; i < p -> getCheckedOutBooks().size(); i++)
    {
        cout << endl << endl << "  " << p -> getCheckedOutBooks()[i] -> getTitle();
    }
    cout << endl << endl << "Patron's fines: " << p -> getFineAmount() << ".";
	
}

/*********************************************************************
** Function:  viewBookInfo
** Description:  A function that takes in a book id, retrieves,
** and outputs relative information.
** Parameters: A string.
** Pre-Conditions: A string.
** Post-Conditions:  Outputs relative information.
*********************************************************************/

void Library::viewBookInfo (std::string bookID)
{
    Book* b;

    for (int i = 0; i < holdings.size(); i++)
    {
        if (bookID == holdings[i].getIdCode())
        {
            b = &holdings[i];
            break;
        }
    }

    if (b == NULL)
    {
        cout << endl << endl << "That book is not in the library system.";
        return;   
    }
	
    cout << endl << endl << "Book's id: " << b -> getIdCode() << ".";
    cout << endl << endl << "Book's title: " << b -> getTitle() << ".";
    cout << endl << endl << "Book's author: " << b -> getAuthor() << ".";
	
    switch (b -> getLocation())
    {
         case 0:
             cout << endl << endl << "Book's location: ON_SHELF" << endl;
             break;
         case 1:
             cout << endl << endl << "Book's location: ON_HOLD" << endl;
             break;
         case 2:
             cout << endl << endl << "Book's location: CHECKED_OUT"<<endl;
             break;
         default:
             break;
    }
    
    if (b -> getRequestedBy() != NULL)
        cout << endl << endl << "Book's on request by: " << b -> getRequestedBy() -> getName() << ".";
    if (b -> getCheckedOutBy() != NULL)
        cout << endl << endl << "Book's checked out by: " << b -> getCheckedOutBy()-> getName() << ".";
    cout << endl << endl << "Book's due date: " << (b -> getDateCheckedOut() + Book::CHECK_OUT_LENGTH) << ".";     
}
