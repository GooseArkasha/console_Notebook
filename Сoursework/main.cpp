#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Contact.h"
#include <Windows.h>
#include "Functions.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Первое меню
	int mode = menu1();
	
	if(mode == 1)//Работа со списком	КОНТАКТОВ
	{
		fstream f1;
		string titel = "contacts.txt";
		f1.open(titel, fstream::in | fstream::out || fstream::app);
		if (!f1.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			system("pause");
			return 1;
		}
		else
		{
			cout << "Файл Contacts.txt открыт." << endl;
			vector<Contact> vec;
			Contact temp;

			//Копирование данных из файла в вектор объектов класса
			while (!f1.eof())
			{
				f1 >> temp;
				vec.push_back(temp);
			}
			f1.close();
			OutputContacts(vec);
		}
	}


	if (mode == 2)	//Работа со списком СОБЫТЕЙ
	{
		cout << "Работа со списком СОБЫТИЙ" << endl;
	}


	if (mode == 0) //Завершение работы
	{
		cout << "Звершение работы" << endl;
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}