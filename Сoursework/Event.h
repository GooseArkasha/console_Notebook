#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event
{
	string name;
	string tad; //time and date
	string adres;
	string description;
public:
	Event(string n = "��� ����������", string t = "��� ����������",
		string a = "��� ����������", string d = "��� ����������") :
		name(n), tad(t), adres(a), description(d) {};
	string GetName();
	string GetTad();
	string GetAdres();
	string GetDiscription();
	void SetName(string name);
	void SetTad(string surname);
	void SetAdres(string phone);
	void SetDiscription(string email);
	friend ostream& operator>>(ostream& out, const Event &obj);
	friend istream& operator<<(istream& out, Event &obj);
};