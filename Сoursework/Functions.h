#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
using namespace std;

//******************��������� ������� ����**************************************************
int menu1();



//******************��������� ������� ��� ������ �� ������� ���������***********************
void AddContact(vector <Contact> &vec);	//������� ��������� � ����� ������� ����� ������
void DeliteContact(vector <Contact> &vec);	//������� ������� �������� ������������� ������
void OutputContacts(vector <Contact> &vec);	//������� ������� ������� ������ �������
void SortName(vector <Contact> &vec);	//������� ��������� ������ �� ������ � ���������� �������
void SortSurname(vector <Contact> &vec);	//������� ��������� ������ �� �������� � ���������� �������
void EditContact(vector <Contact> &vec);	//������� ����������� �������� ������������� �������
int SearchContact(vector <Contact> &vec);	//������� ���������� ����� ��������, ���������� ������ ��������� ��������
void SaveContacts(vector <Contact> &vec, string FileName);	//������� ��������� ������� ������ � ����
void DeliteAllContacts(vector <Contact> &vec);	//������� ������� ��� ������, ���������� � ������



//******************��������� ������� ��� ������ �� ������� �������*************************




//******************��������� ��������� �������*********************************************
int input_int();