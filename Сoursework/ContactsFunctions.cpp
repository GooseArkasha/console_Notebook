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
int SearchContact(vector <Contact> &vec, int size);	//���������� ������ ��������� ��������
void SaveContacts(vector <Contact> &vec, string FileName, int size);


void OutputContacts(vector <Contact> &vec, int size)
{
	cout << "������ �������� �����:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "�������:" << endl;
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
		cout << "��� ������ �������� �������" << endl;
		cout << "���: ";
		getline(cin, str1);
		cout << "�������: ";
		getline(cin, str2);
		for (int i = 0; i < size; i++)
		{
			temp1 = vec[i].GetName();
			temp2 = vec[i].GetSurname();
			if (str1 == temp1 && str2 == temp2)
				return i;	//������� �������� ������ ����� ���������� ����������
		}
		cout << "������ ������ �� �������. ��������� ���� ��� ���." << endl;
	} while (true);
}

void EditContact(vector <Contact> &vec, int size)
{
	int i = SearchContact(vec, size);
	string temp;
	int k;
	do
	{
		cout << "���� �� ������ ��������" << endl;
		cout << "\t��� - ������� 1" << endl;
		cout << "\t������� - ������� 2" << endl;
		cout << "\t������� - ������� 3" << endl;
		cout << "\tEmail - ������� 4" << endl;
		cout << "\t������� - ������� 5" << endl;
		cout << "������� 0, ���� ������ ��������� ��������������." << endl;
		cin >> k;
		//�������� �������� ���������� ������ ������
		switch (k)
		{
		case 1:
		{
			cout << "������� ����� ���: ";
			getline(cin, temp);
			vec[i].SetName(temp);
			break;
		}
		case 2:
		{
			cout << "������� ����� �������: ";
			getline(cin, temp);
			vec[i].SetSurname(temp);
			break;
		}
		case 3:
		{
			cout << "������� ����� �������: ";
			getline(cin, temp);
			vec[i].SetPhone(temp);
			break;
		}
		case 4:
		{
			cout << "������� ����� email: ";
			getline(cin, temp);
			vec[i].SetEmail(temp);
			break;
		}
		case 5:
		{
			cout << "������� ����� �������: ";
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
		cout << "������ �������� �����! ������ �� ����� ���������." << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
			file << vec[i];
	}
	file.close;
}