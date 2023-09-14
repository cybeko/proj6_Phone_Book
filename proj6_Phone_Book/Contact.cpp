#include "Contact.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS 
#include <cstring>
using namespace std;

Contact::Contact()
{
	cout << "Constructor def." << endl;
    firstName = nullptr;
    lastName = nullptr;
}
Contact::~Contact()
{
	cout << "Destr." << endl;
	delete[] firstName;
	delete[] lastName;
}
Contact::Contact(const char* userFirstName, const char* userLastName)
{
	cout << "Constructor par." << endl;
	firstName = new char[strlen(userFirstName) + 1];
	strcpy_s(firstName, strlen(userFirstName) + 1, userFirstName);

	lastName = new char[strlen(userLastName) + 1];
	strcpy_s(lastName, strlen(userLastName) + 1, userLastName);
}
void Contact::addContact(const char pathData[])
{
    FILE* file;
    errno_t code = fopen_s(&file, pathData, "ab");
    if (code == 0)
    {
        char buff[30];

		deleteNullPtr(firstName);
		deleteNullPtr(lastName);
		
        cout << "Enter first name: ";
        cin >> buff;
        firstName = new char[strlen(buff) + 1];
        strcpy_s(firstName, strlen(buff) + 1, buff);

        cout << "Enter last name: ";
        cin >> buff;
        lastName = new char[strlen(buff) + 1];
        strcpy_s(lastName, strlen(buff) + 1, buff);

        fwrite(this, sizeof(Contact), 1, file);
        fclose(file);
    }
    else
    {
        cout << "Error. Couldn't open file." << endl;
    }
}
void Contact::printAll(const char pathData[])
{
	FILE* file;
	errno_t code = fopen_s(&file, pathData, "rb");
	if (code == 0)
	{
		Contact point;
		int counter = 1;
		while (!feof(file))
		{
			if (fread(&point, sizeof(Contact), 1, file))
			{
				printf("\tEmployee #%d\n", counter++);
				printInfoStruct(point);
				cout << endl;
			}
		}
		fclose(file);
	}
	else
		cout << "Error. Code: " << code << endl;
}
void Contact::printInfoStruct(Contact point)
{
	printf("Full name: %s %s\n", point.firstName, point.lastName);
}
char* Contact::GetFirstName()
{
	return firstName;
}
char* Contact::GetLastName()
{
	return lastName;
}
void Contact::deleteNullPtr(char* ptr)
{
	if (ptr != nullptr)
	{
		cout << "[Deleting " << ptr << "]" << endl;
		delete[] ptr;
	}
}
void Contact::setFirstName(const char* userFirstName)
{
	deleteNullPtr(firstName);
	firstName = new char[strlen(userFirstName) + 1];
	strcpy_s(firstName, strlen(userFirstName) + 1, userFirstName);
}
void Contact::setLastName(const char* userLastName)
{
	deleteNullPtr(lastName);
	lastName = new char[strlen(userLastName) + 1];
	strcpy_s(lastName, strlen(userLastName) + 1, userLastName);
}