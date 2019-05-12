#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "Event.h"
#include <fstream>
#include "Functions.h"
using namespace std;

//******************Функции МЕНЮ************************************************************
int menu1()
{
	cout << "********************************************************************************" << endl;
	cout << "МЕНЮ 1:";
	cout << "\tЕсли хотите рботать с АДРЕСНОЙ КНИГОЙ - введите 1" << endl;
	cout << "\tЕсли хотите работать с СОБЫТИЯМИ - введите 2" << endl;
	cout << "\tЕсли хотите ЗАВЕРШИТЬ работу с программий - введите 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 2)
			cout << "Режим выбран некорректно! Повторите попытку ввода." << endl;
	} while (i < 0 || i > 2);
	return i;
}


int menu2()
{
	cout << "********************************************************************************" << endl;
	cout << "МЕНЮ 2:";
	cout << "\tЕсли хотите ДОБАВИТЬ КОНТАКТ - введите 1" << endl;
	cout << "\tЕсли хотите СОХРАНИТЬ внесенные изменения - введите 2" << endl;
	cout << "\tЕсли хотите вернуться в МЕНЮ 1 - введите 3" << endl;
	cout << "\tЕсли хотите ЗАВЕРШИТЬ работу с программий - введите 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 3)
			cout << "Режим выбран некорректно! Повторите попытку ввода." << endl;
	} while (i < 0 || i > 3);
	return i;
}


int menu3()
{
	cout << "********************************************************************************" << endl;
	cout << "МЕНЮ 3:";
	cout << "\tЕсли хотите ДОБАВИТЬ КОНТАКТ - введите 1" << endl;
	cout << "\tЕсли хотите УДАЛИТЬ КОНТАКТ - введите 2" << endl;
	cout << "\tЕсли хотите ВЫВЕСТИ ТЕКУЩИЙ СПИСОК - введите 3" << endl;
	cout << "\tЕсли хотите ОТСОРТИРОВАТЬ список по ИМЕНАМ - введите 4" << endl;
	cout << "\tЕсли хотите ОТСОРТИРОВАТЬ список по ФАМИЛИЯМ - введите 5" << endl;
	cout << "\tЕсли хотите РЕДАКТИРОВАТЬ один из контактов - введите 6" << endl;
	cout << "\tЕсли хотите УДАЛИТЬ все записи списка - введите 7" << endl;
	cout << "\tЕсли хотите СОХРАНИТЬ внесенные изменения - введите 8" << endl;
	cout << "\tЕсли хотите вернуться в МЕНЮ 1 - введите 9" << endl;
	cout << "\tЕсли хотите ЗАВЕРШИТЬ работу с программий - введите 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 9)
			cout << "Режим выбран некорректно! Повторите попытку ввода." << endl;
	} while (i < 0 || i > 9);
	return i;
}

int menu4()
{
	cout << "********************************************************************************" << endl;
	cout << "МЕНЮ 4:";
	cout << "\tЕсли хотите ДОБАВИТЬ СОБЫТИЕ - введите 1" << endl;
	cout << "\tЕсли хотите СОХРАНИТЬ внесенные изменения - введите 2" << endl;
	cout << "\tЕсли хотите вернуться в МЕНЮ 1 - введите 3" << endl;
	cout << "\tЕсли хотите ЗАВЕРШИТЬ работу с программий - введите 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 3)
			cout << "Режим выбран некорректно! Повторите попытку ввода." << endl;
	} while (i < 0 || i > 3);
	return i;
}


int menu5()
{
	cout << "********************************************************************************" << endl;
	cout << "МЕНЮ 5:";
	cout << "\tЕсли хотите ДОБАВИТЬ СОБЫТИЕ - введите 1" << endl;
	cout << "\tЕсли хотите УДАЛИТЬ СОБЫТИЕ - введите 2" << endl;
	cout << "\tЕсли хотите ВЫВЕСТИ ТЕКУЩИЙ СПИСОК - введите 3" << endl;
	cout << "\tЕсли хотите ОТСОРТИРОВАТЬ список по НАЗВАНИЯМ - введите 4" << endl;
	cout << "\tЕсли хотите ОТСОРТИРОВАТЬ список по ДАТАМ И ВРЕМЕНИ - введите 5" << endl;
	cout << "\tЕсли хотите РЕДАКТИРОВАТЬ одно из событий - введите 6" << endl;
	cout << "\tЕсли хотите УДАЛИТЬ все записи списка - введите 7" << endl;
	cout << "\tЕсли хотите СОХРАНИТЬ внесенные изменения - введите 8" << endl;
	cout << "\tЕсли хотите вернуться в МЕНЮ 1 - введите 9" << endl;
	cout << "\tЕсли хотите ЗАВЕРШИТЬ работу с программий - введите 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 9)
			cout << "Режим выбран некорректно! Повторите попытку ввода." << endl;
	} while (i < 0 || i > 9);
	return i;
}


//******************Функции для работы со списком КОНТАКТОВ*********************************
void AddContact(vector <Contact> &vec)
{
	Contact temp;
	cout << "Введите данные записи, которую хотите добавить" << endl;
	temp.input();
	vec.push_back(temp);
}

void DeleteContact(vector <Contact> &vec)
{
	cout << "Поиск контакта для удаления";
	int i = SearchContact(vec);
	vector<Contact>::iterator p = vec.begin();
	p += i;
	vec.erase(p);
}

void OutputContacts(vector <Contact> &vec)
{
	cout << "Данные адресной книги:" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i + 1 << "контакт:" << endl;
		vec[i].output();
		cout << endl;
	}
}

void SortName(vector <Contact> &vec)
{
	Contact tempCont;
	string temp1, temp2;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		temp1 = vec[i].GetName();
		for (int j = i + 1; j < vec.size(); j++)
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

void SortSurname(vector <Contact> &vec)
{
	Contact tempCont;
	string temp1, temp2;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		temp1 = vec[i].GetSurname();
		for (int j = i + 1; j < vec.size(); j++)
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

int SearchContact(vector <Contact> &vec)
{
	string str1, str2, temp1, temp2;
	do
	{
		cout << "Для поиска контакта введите" << endl;
		cout << "Имя: ";
		getline(cin, str1);
		cout << "Фамилию: ";
		getline(cin, str2);
		for (int i = 0; i < vec.size(); i++)
		{
			temp1 = vec[i].GetName();
			temp2 = vec[i].GetSurname();
			if (str1 == temp1 && str2 == temp2)
				return i;	//Функция закончит работу после нахождения совпадения
		}
		cout << "Данная запись не найдена. Повторите воод еще раз." << endl;
	} while (true);
}

void EditContact(vector <Contact> &vec)
{
	cout << "Поиск контакта для изменения" << endl;
	int i = SearchContact(vec);
	cout << "Найденый контакт:" << endl;
	vec[i].output();
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
		do
		{
			k = input_int();
			if (i < 0 || i > 5)
				cout << "Режим выбран некорректно! Повторите попытку ввода." << endl;
		} while (i < 0 || i > 5);
		//Добавить проверку переменной выбора режима
		cin.ignore(32767, '\n');
		switch (k)
		{
		case 1:
		{
			cout << "Текущая запись: " << vec[i].GetName() << endl;
			cout << "Введите новое имя: ";
			getline(cin, temp);
			vec[i].SetName(temp);
			break;
		}
		case 2:
		{
			cout << "Текущая запись: " << vec[i].GetSurname() << endl;
			cout << "Введите новую фамилию: ";
			getline(cin, temp);
			vec[i].SetSurname(temp);
			break;
		}
		case 3:
		{
			cout << "Текущая запись: " << vec[i].GetPhone() << endl;
			cout << "Введите новый телефон: ";
			getline(cin, temp);
			vec[i].SetPhone(temp);
			break;
		}
		case 4:
		{
			cout << "Текущая запись: " << vec[i].GetEmail() << endl;
			cout << "Введите новый email: ";
			getline(cin, temp);
			vec[i].SetEmail(temp);
			break;
		}
		case 5:
		{
			cout << "Текущая запись: " << vec[i].GetNote() << endl;
			cout << "Введите новые Заметки: ";
			getline(cin, temp);
			vec[i].SetNote(temp);
			break;
		}
		default: break;
		}
	} while (k);
}

void SaveContacts(vector <Contact> &vec, string FileName)
{
	ofstream file;
	file.open(FileName);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла! Данные не будут сохранены." << endl;
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
			file << vec[i];
	}
	file.close();
}

void DeleteAllContacts(vector <Contact> &vec)
{
	cout << "Удаление всех записей" << endl;
	vec.clear();
}



//******************Функции для работы со списком СОБЫТЕЙ***********************************
void AddEvent(vector <Event> &vec)
{
	Event temp;
	cout << "Введите данные записи, которую хотите добавить" << endl;
	temp.input();
	vec.push_back(temp);
}

void DeleteEvent(vector <Event> &vec)
{
	cout << "Поиск события для удаления";
	int i = SearchEvent(vec);
	vector<Event>::iterator p = vec.begin();
	p += i;
	vec.erase(p);
}

void OutputEvents(vector <Event> &vec)
{
	cout << "Данные списка событий:" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i + 1 << "событие:" << endl;
		vec[i].output();
		cout << endl;
	}
}

void SortName(vector <Event> &vec)
{
	Event tempEv;
	string temp1, temp2;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		temp1 = vec[i].GetName();
		for (int j = i + 1; j < vec.size(); j++)
		{
			temp2 = vec[j].GetName();
			if (temp2 < temp1)
			{
				tempEv = vec[i];
				vec[i] = vec[j];
				vec[j] = tempEv;
			}
		}
	}
}

void SortTad(vector <Event> &vec)
{
	Event tempEv;
	string temp1, temp2;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		temp1 = vec[i].GetTad();
		for (int j = i + 1; j < vec.size(); j++)
		{
			temp2 = vec[j].GetTad();
			if (temp2 < temp1)
			{
				tempEv = vec[i];
				vec[i] = vec[j];
				vec[j] = tempEv;
			}
		}
	}
}

void EditEvent(vector <Event> &vec)
{
	cout << "Поиск события для изменения" << endl;
	int i = SearchEvent(vec);
	cout << "Найденый контакт:" << endl;
	vec[i].output();
	string temp;
	int k;
	do
	{
		cout << "Если вы хотите изменить" << endl;
		cout << "\tНазвание - введите 1" << endl;
		cout << "\tДату и время - введите 2" << endl;
		cout << "\tАдрес - введите 3" << endl;
		cout << "\tОписание - введите 4" << endl;
		cout << "Введите 0, если хотите закончить редактирование." << endl;
		do
		{
			k = input_int();
			if (i < 0 || i > 4)
				cout << "Режим выбран некорректно! Повторите попытку ввода." << endl;
		} while (i < 0 || i > 4);
		//Добавить проверку переменной выбора режима
		cin.ignore(32767, '\n');
		switch (k)
		{
		case 1:
		{
			cout << "Текущая запись:" << vec[i].GetName() << endl;
			cout << "Введите новое название: ";
			getline(cin, temp);
			vec[i].SetName(temp);
			break;
		}
		case 2:
		{
			cout << "Текущая запись:" << vec[i].GetTad() << endl;
			cout << "Введите новую дату и время: ";
			getline(cin, temp);
			vec[i].SetTad(temp);
			break;
		}
		case 3:
		{
			cout << "Текущая запись:" << vec[i].GetAddress() << endl;
			cout << "Введите новый адрес: ";
			getline(cin, temp);
			vec[i].SetAddress(temp);
			break;
		}
		case 4:
		{
			cout << "Текущая запись:" << vec[i].GetDescription() << endl;
			cout << "Введите новый описание: ";
			getline(cin, temp);
			vec[i].SetDescription(temp);
			break;
		}
		default: break;
		}
	} while (k);
}

int SearchEvent(vector <Event> &vec)
{
	string str1, str2, temp1, temp2;
	do
	{
		cout << "Для поиска события введите" << endl;
		cout << "Название: ";
		getline(cin, str1);
		cout << "Дата и время: ";
		getline(cin, str2);
		for (int i = 0; i < vec.size(); i++)
		{
			temp1 = vec[i].GetName();
			temp2 = vec[i].GetTad();
			if (str1 == temp1 && str2 == temp2)
				return i;	//Функция закончит работу после нахождения совпадения
		}
		cout << "Данная запись не найдена. Повторите воод еще раз." << endl;
	} while (true);
}

void SaveEvents(vector <Event> &vec, string FileName)
{
	ofstream file;
	file.open(FileName);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла! Данные не будут сохранены." << endl;
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
			file << vec[i];
	}
	file.close();
}

void DeleteAllEvents(vector <Event> &vec)
{
	cout << "Удаление всех записей" << endl;
	vec.clear();
}


//******************Остальные функции*******************************************************
int input_int()
{
	string temp;
	getline(cin, temp);
	if (temp.size() > 2)
		return -1;
	int i = 0, k = 0;
	while (temp[k] != '\0')
	{
		if (temp[k] < '0' || temp[k] > '9')
			return -1;
		i = (i + temp[k] - 48) * 10;
		k++;
	}
	i /= 10;
	return i;
}