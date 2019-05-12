#include "pch.h"
#include <iostream>
#include <string>
#include "Event.h"
using namespace std;

Event::Event(const Event &obj)
{
	name = obj.name;
	tad = obj.tad;
	address = obj.address;
	description = obj.description;
}

string Event::GetName()
{
	return name;
}

string Event::GetTad()
{
	return tad;
}

string Event::GetAddress()
{
	return address;
}

string Event::GetDescription()
{
	return description;
}

void Event::SetName(string name)
{
	this->name = name;
}

void Event::SetTad(string tad)
{
	this->tad = tad;
}

void Event::SetAddress(string address)
{
	this->address = address;
}

void Event::SetDescription(string email)
{
	this->description = description;
}

void Event::input()
{
	cout << "********************************************************************************" << endl;
	cout << "\tНазвание: ";
	getline(cin, name);
	cout << "\tДата и время: ";
	getline(cin, tad);
	cout << "\tАдрес: ";
	getline(cin, address);
	cout << "\tОписание: ";
	getline(cin, description);
	cout << "********************************************************************************" << endl;
}

void Event::output()
{
	cout << "***************************************" << endl;
	cout << "Вывод контакта:" << endl;
	cout << "\tНазвание: " << name << endl;
	cout << "\tДата и время: " << tad << endl;
	cout << "\tАдрес: " << address << endl;
	cout << "\tОписание: " << description << endl;
	cout << "***************************************" << endl;
}

Event Event::operator=(Event obj2)
{
	name = obj2.name;
	tad = obj2.tad;
	address = obj2.address;
	description = obj2.description;
	return *this;
}

ostream& operator<<(ostream& out, const Event &obj)
{
	out << obj.name << endl;
	out << obj.tad << endl;
	out << obj.address << endl;
	out << obj.description << endl;
	return out;
}

istream& operator>>(istream& in, Event &obj)
{
	getline(in, obj.name);
	getline(in, obj.tad);
	getline(in, obj.address);
	getline(in, obj.description);
	return in;
}