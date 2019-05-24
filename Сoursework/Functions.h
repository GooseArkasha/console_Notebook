#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "Event.h"
using namespace std;

//******************��������� ������� ����**************************************************
int menu1();
int menu2();
int menu3();
int menu4();
int menu5();

//******************��������� ������� ��� ������ �� ������� ���������***********************
void AddContact(vector <Contact> &vec);	//������� ��������� � ����� ������� ����� ������
void DeleteContact(vector <Contact> &vec);	//������� ������� �������� ������������� ������
void OutputContacts(vector <Contact> &vec);	//������� ������� ������� ������ �������
void SortName(vector <Contact> &vec);	//������� ��������� ������ �� ������ � ���������� �������
void SortSurname(vector <Contact> &vec);	//������� ��������� ������ �� �������� � ���������� �������
void EditContact(vector <Contact> &vec);	//������� ����������� �������� ������������� �������
void SaveContacts(vector <Contact> &vec, string FileName);	//������� ��������� ������� ������ � ����
void DeleteAllContacts(vector <Contact> &vec);	//������� ������� ��� ������, ���������� � ������



//******************��������� ������� ��� ������ �� ������� �������*************************
void AddEvent(vector <Event> &vec);	//������� ��������� � ����� ������� ����� ������
void DeleteEvent(vector <Event> &vec);	//������� ������� �������� ������������� ������
void OutputEvents(vector <Event> &vec);	//������� ������� ������� ������ �������
void SortName(vector <Event> &vec);	//������� ��������� ������ �� ��������� � ���������� �������
void SortTad(vector <Event> &vec);	//������� ��������� ������ �� �����
void EditEvent(vector <Event> &vec);	//������� ����������� �������� ������������� ������
int SearchEvent(vector <Event> &vec);	//������� ���������� ����� �������, ���������� ������ ��������� ��������
void SaveEvents(vector <Event> &vec, string FileName);	//������� ��������� ������� ������ � ����
void DeleteAllEvents(vector <Event> &vec);	//������� ������� ��� ������, ���������� � ������



//******************��������� ��������� �������*********************************************
int input_int();