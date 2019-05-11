#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
using namespace std;

Contact::Contact(const Contact &obj)
{
	name = obj.name;
	surname = obj.surname;
	phone = obj.phone;
	email = obj.email;
	note = obj.note;
}

string Contact::GetName()
{
	return name;
}

string Contact::GetSurname()
{
	return surname;
}

string Contact::GetPhone()
{
	return phone;
}

string Contact::GetEmail()
{
	return email;
}

string Contact::GetNote()
{
	return note;
}

void Contact::SetName(string name)
{
	this->name = name;
}

void Contact::SetSurname(string surname)
{
	this->surname = surname;
}

void Contact::SetPhone(string phone)
{
	this->phone = phone;
}

void Contact::SetEmail(string email)
{
	this->email = email;
}

void Contact::SetNote(string note)
{
	this->note = note;
}

void Contact::input()
{
	cout << "***************************************" << endl;
	cout << "\tИмя: ";
	getline(cin, name);
	cout << "\tФамилия: ";
	getline(cin, surname);
	cout << "\tТелефон: ";
	getline(cin, phone);
	cout << "\tEmail: ";
	getline(cin, email);
	cout << "\tЗаметки: ";
	getline(cin, note);
	cout << "***************************************" << endl;
}

void Contact::output()
{
	cout << "***************************************" << endl;
	cout << "Вывод контакта:" << endl;
	cout << "\tИмя: " << name << endl;
	cout << "\tФамилия: " << surname << endl;
	cout << "\tТелефон: " << phone << endl;
	cout << "\tEmail: " << email << endl;
	cout << "\tЗаметки: " << note << endl;
	cout << "***************************************" << endl;
}

Contact Contact::operator=(Contact obj2)
{
	name = obj2.name;
	surname = obj2.surname;
	phone = obj2.phone;
	email = obj2.email;
	note = obj2.note;
	return *this;
}

ostream& operator<<(ostream& out, const Contact& obj)
{
	out << obj.name << endl;
	out << obj.surname << endl;
	out << obj.phone << endl;
	out << obj.email << endl;
	out << obj.note << endl;
	return out;
}

istream& operator>>(istream& in, Contact &obj)
{
	getline(in, obj.name);
	getline(in, obj.surname);
	getline(in, obj.phone);
	getline(in, obj.email);
	getline(in, obj.note);
	return in;
}