#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact
{
	string name;
	string surname;
	string phone;
	string email;
	string note;
public:
	Contact(string n = "Нет информации", string s = "Нет информации",
		string p = "Нет информации", string e = "Нет информации", string note = "Нет информации") :
		name(n), surname(s), phone(p), email(e), note(n) {};
	Contact(const Contact &obj);
	string GetName();
	string GetSurname();
	string GetPhone();
	string GetEmail();
	string GetNote();
	void SetName(string name);
	void SetSurname(string surname);
	void SetPhone(string phone);
	void SetEmail(string email);
	void SetNote(string note);
	void input();	//Функция ввода пользователем
	void output();	//Функция вывода в консоль
	Contact operator=(Contact obj2);
	friend ostream& operator<<(ostream& out, const Contact &obj);	//Функции для записи в файл
	friend istream& operator>>(istream& out, Contact &obj);	//Функции для извлечения из файла
};