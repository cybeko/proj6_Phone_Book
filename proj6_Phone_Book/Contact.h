#pragma once
#define _CRT_SECURE_NO_WARNINGS
const char pathData[] = "Data.txt";
const char pathTemp[] = "Temp.txt";

class Contact
{
	char* firstName;
	char* lastName;

	void deleteNullPtr(char*);
public:
	Contact();
	~Contact();
	Contact(const char* userFirstName, const char* userLastName);

	void addContact(const char pathData[]);
	void printInfoStruct(Contact point);
	void printAll(const char pathData[]);

	char* GetFirstName();
	char* GetLastName();
	void setFirstName(const char* userFirstName);
	void setLastName(const char* userFirstName);
};