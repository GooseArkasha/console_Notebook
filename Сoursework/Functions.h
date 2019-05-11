#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
using namespace std;

//******************Прототипы функций МЕНЮ**************************************************
int menu1();
int menu2();
int menu3();

//******************Прототипы функций для работы со списком КОНТАКТОВ***********************
void AddContact(vector <Contact> &vec);	//Функция добавляет в конец вектора новую запись
void DeleteContact(vector <Contact> &vec);	//Функция удаляет заданную пользователем запись
void OutputContacts(vector <Contact> &vec);	//Функция выводит текущий список записей
void SortName(vector <Contact> &vec);	//Функция сортирует список по именам в алфавитном порядке
void SortSurname(vector <Contact> &vec);	//Функция сортирует список по фамилиям в алфавитном порядке
void EditContact(vector <Contact> &vec);	//Функция редактирует заданный пользователем контакт
int SearchContact(vector <Contact> &vec);	//Функция производит поиск контакта, возвращает индекс найденого элемента
void SaveContacts(vector <Contact> &vec, string FileName);	//Функция сохраняет текущий список в файл
void DeleteAllContacts(vector <Contact> &vec);	//Функция удаляет все записи, хранящиесе я списке



//******************Прототипы функций для работы со списком СОБЫТИЙ*************************




//******************Прототипы остальных функций*********************************************
int input_int();