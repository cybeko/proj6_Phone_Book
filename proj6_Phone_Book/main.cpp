#include <iostream>
#include "Contact.h"
using namespace std;

int main()
{
    Contact contact;

    int userCh;
    while (true)
    {
        cout << "1. Add Contact" << endl;
        cout << "2. Print All Contacts" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userCh;

        switch (userCh)
        {
        case 1:
            contact.addContact(pathData);
            break;
        case 2:
            contact.printAll(pathData);
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}