#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "pch.h"
#include "Contact.h"
#include <Windows.h>
#include "Functions.h"
using namespace std;

int main()
{
	fstream f1;
	string titel = "Contacts.txt";
	f1.open(titel, fstream::in | fstream::out);
	if (!f1.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл Contacts.txt открыт." << endl;
		vector<Contact> vec;
		Contact temp;

		//Перенесение данных из файла в вектор объектов класса
		while (!f1.eof())
		{
			f1 >> temp;
			vec.push_back(temp);
		}
		f1.close();

		OutputContacts(vec);

		//Первое меню
		int mode = menu1();
		switch (mode)
		{
		case 1: //Работа со списком	КОНТАКТОВ
		{
			break;
		}
		case 2:	//Работа со списком СОБЫТЕЙ
		{
			break;
		}
		case 0: //Завершение работы
		{
			return 0;
			break;
		}
		default:
			break;
		}
		
	}
	return 0;
}