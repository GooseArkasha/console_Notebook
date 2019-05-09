#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include <fstream>
using namespace std;

void OutputContacts(vector <Contact> &vec, int size);
void SortName(vector <Contact> &vec, int size);
void SortSurname(vector <Contact> &vec, int size);
void EditContact(vector <Contact> &vec, int size);
int SearchContact(vector <Contact> &vec, int size);	//Возвращает индекс найденого элемента
void SaveContacts(vector <Contact> &vec, string FileName, int size);


void OutputContacts(vector <Contact> &vec, int size)
{
	cout << "Данные адресной книги:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "контакт:" << endl;
		vec[i].output();
		cout << endl;
	}
}

void SortName(vector <Contact> &vec, int size)
{
	Contact tempCont;
	string temp1, temp2;
	for (int i = 0; i < size - 1; i++)
	{
		temp1 = vec[i].GetName();
		for (int j = i + 1; j < size; j++)
		{
			temp2 = vec[j].GetName();
			if (temp2 < temp1)
			{
				tempCont = vec[i];
				vec[i] = vec[j];
				vec[j] = tempCont;
			}
		}
	}
}

void SortSurname(vector <Contact> &vec, int size)
{
	Contact tempCont;
	string temp1, temp2;
	for (int i = 0; i < size - 1; i++)
	{
		temp1 = vec[i].GetSurname();
		for (int j = i + 1; j < size; j++)
		{
			temp2 = vec[j].GetSurname();
			if (temp2 < temp1)
			{
				tempCont = vec[i];
				vec[i] = vec[j];
				vec[j] = tempCont;
			}
		}
	}
}

int SearchContact(vector <Contact> &vec, int size)
{
	string str1, str2, temp1, temp2;
	do
	{
		cout << "Для поиска контакта введите" << endl;
		cout << "Имя: ";
		getline(cin, str1);
		cout << "Фамилию: ";
		getline(cin, str2);
		for (int i = 0; i < size; i++)
		{
			temp1 = vec[i].GetName();
			temp2 = vec[i].GetSurname();
			if (str1 == temp1 && str2 == temp2)
				return i;	//Функция закончит работу после нахождения совпадения
		}
		cout << "Данная запись не найдена. Повторите воод еще раз." << endl;
	} while (true);
}

void EditContact(vector <Contact> &vec, int size)
{
	int i = SearchContact(vec, size);
	string temp;
	int k;
	do
	{
		cout << "Если вы хотите изменить" << endl;
		cout << "\tИмя - введите 1" << endl;
		cout << "\tФамилию - введите 2" << endl;
		cout << "\tТелефон - введите 3" << endl;
		cout << "\tEmail - введите 4" << endl;
		cout << "\tЗаметки - введите 5" << endl;
		cout << "Введите 0, если хотите закончить редактирование." << endl;
		cin >> k;
		//Добавить проверку переменной выбора режима
		switch (k)
		{
		case 1:
		{
			cout << "Введите новое имя: ";
			getline(cin, temp);
			vec[i].SetName(temp);
			break;
		}
		case 2:
		{
			cout << "Введите новую фамилию: ";
			getline(cin, temp);
			vec[i].SetSurname(temp);
			break;
		}
		case 3:
		{
			cout << "Введите новый телефон: ";
			getline(cin, temp);
			vec[i].SetPhone(temp);
			break;
		}
		case 4:
		{
			cout << "Введите новый email: ";
			getline(cin, temp);
			vec[i].SetEmail(temp);
			break;
		}
		case 5:
		{
			cout << "Введите новые Заметки: ";
			getline(cin, temp);
			vec[i].SetNote(temp);
			break;
		}
		default: break;
		}
	} while (k);
}

void SaveContacts(vector <Contact> &vec, string FileName, int size)
{
	fstream file;
	file.open(FileName, fstream::in);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла! Данные не будут сохранены." << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
			file << vec[i];
	}
	file.close;
}