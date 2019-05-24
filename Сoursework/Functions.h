#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "Event.h"
using namespace std;

//******************Прототипы функций МЕНЮ**************************************************
int menu1();
int menu2();
int menu3();
int menu4();
int menu5();

//******************Прототипы функций для работы со списком КОНТАКТОВ***********************
void AddContact(vector <Contact> &vec);	//Функция добавляет в конец вектора новую запись
void DeleteContact(vector <Contact> &vec);	//Функция удаляет заданную пользователем запись
void OutputContacts(vector <Contact> &vec);	//Функция выводит текущий список записей
void SortName(vector <Contact> &vec);	//Функция сортирует список по именам в алфавитном порядке
void SortSurname(vector <Contact> &vec);	//Функция сортирует список по фамилиям в алфавитном порядке
void EditContact(vector <Contact> &vec);	//Функция редактирует заданный пользователем контакт
void SaveContacts(vector <Contact> &vec, string FileName);	//Функция сохраняет текущий список в файл
void DeleteAllContacts(vector <Contact> &vec);	//Функция удаляет все записи, хранящиесе я списке



//******************Прототипы функций для работы со списком СОБЫТИЙ*************************
void AddEvent(vector <Event> &vec);	//Функция добавляет в конец вектора новую запись
void DeleteEvent(vector <Event> &vec);	//Функция удаляет заданную пользователем запись
void OutputEvents(vector <Event> &vec);	//Функция выводит текущий список записей
void SortName(vector <Event> &vec);	//Функция сортирует список по названиям в алфавитном порядке
void SortTad(vector <Event> &vec);	//Функция сортирует список по датам
void EditEvent(vector <Event> &vec);	//Функция редактирует заданную пользователем запись
int SearchEvent(vector <Event> &vec);	//Функция производит поиск сибытия, возвращает индекс найденого элемента
void SaveEvents(vector <Event> &vec, string FileName);	//Функция сохраняет текущий список в файл
void DeleteAllEvents(vector <Event> &vec);	//Функция удаляет все записи, хранящиесе я списке



//******************Прототипы остальных функций*********************************************
int input_int();