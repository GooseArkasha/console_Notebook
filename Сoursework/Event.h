#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event
{
	string name;
	string tad; //time and date
	string address;
	string description;
public:
	Event(string n = "Нет информации", string t = "Нет информации",
		string a = "Нет информации", string d = "Нет информации") :
		name(n), tad(t), address(a), description(d) {};
	Event(const Event &obj);
	string GetName();
	string GetTad();
	string GetAddress();
	string GetDescription();
	void SetName(string name);
	void SetTad(string tad);
	void SetAddress(string address);
	void SetDescription(string description);
	void input();	//Функция ввода пользователем
	void output();	//Функция вывода в консоль
	Event operator=(Event obj2);
	friend ostream& operator<<(ostream& out, const Event &obj);
	friend istream& operator>>(istream& out, Event &obj);
};