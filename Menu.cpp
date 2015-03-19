#include "Library.h"
#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <cstdlib>  //Includes cstdlib for exit function.

using namespace std;

int main ()
{
    Library library;
    
    char again;
    int choice;
    do 
    {
        cout << endl << endl << "Choose one of the following options: ";
        cout << endl << endl << "1 Add Book";
        cout << endl << endl << "2 Add Member";
        cout << endl << endl << "3 Check Out Book";
        cout << endl << endl << "4 Return Book";
        cout << endl << endl << "5 Request Book";
        cout << endl << endl << "6 Pay Fine";
        cout << endl << endl << "7 Increment Current Date";
        cout << endl << endl << "8 View Patron Info";
        cout << endl << endl << "9 View Book Info";
        cout << endl << endl << "10 Quit" << endl << endl;
        cin >> choice;
	
	    if (choice == 1)
        {
            library.addBook();   
        }
        else if (choice == 2)
        {
            library.addMember();
        }
        else if (choice == 3)
        {
            string patronID;
            string bookID;
        
            cout << endl << endl << "Enter a member ID: ";
            cin >> patronID;
            cout << endl << endl << "Enter a book ID: ";
            cin >> bookID;
		
            library.checkOutBook (patronID, bookID);
		   
        }
        else if (choice == 4)
        {
            string bookID;
		
            cout << endl << endl << "Enter a book ID: ";
            cin >> bookID;
		
            library.returnBook (bookID);
        }
        else if (choice == 5)
        {
            string patronID;
            string bookID;
        
            cout << endl << endl << "Enter a member ID: ";
            cin >> patronID;
            cout << endl << endl << "Enter a book ID: ";
            cin >> bookID;
		
            library.requestBook (patronID, bookID);       
        }
        else if (choice == 6)
        {
            string patronID;
            double payment;

            cout << endl << endl << "Enter a member ID: ";
            cin >> patronID;
            cout << endl << endl << "Enter a payment amount: ";
            cin >> payment;
			
            library.payFine(patronID, payment);     
        }
        else if (choice == 7)
        {
            library.incrementCurrentDate();   
        }
        else if (choice == 8)
        {
            string patronID;

            cout << endl << endl << "Enter a member ID: ";
            cin >> patronID;
		
            library.viewPatronInfo(patronID);
        }
	    
        else if (choice == 9)
        {
            string bookID;		
		
            cout << endl << endl << "Enter a book ID: ";
            cin >> bookID;
        
            library.viewBookInfo(bookID);   
        }
        
        else if (choice == 10)
        {
            exit(0);   
        }
			
		
        cout << endl << endl << "Would you like to make another selection?";
        cin >> again;
		
    } while (again == 'y' || again == 'Y');
		
    return 0;
}
