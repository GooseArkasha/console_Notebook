#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "Event.h"
#include <fstream>
#include "Functions.h"
using namespace std;

//******************������� ����************************************************************
int menu1()
{
	cout << "********************************************************************************" << endl;
	cout << "���� 1:";
	cout << "\t���� ������ ������� � �������� ������ - ������� 1" << endl;
	cout << "\t���� ������ �������� � ��������� - ������� 2" << endl;
	cout << "\t���� ������ ��������� ������ � ���������� - ������� 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 2)
			cout << "����� ������ �����������! ��������� ������� �����." << endl;
	} while (i < 0 || i > 2);
	return i;
}


int menu2()
{
	cout << "********************************************************************************" << endl;
	cout << "���� 2:";
	cout << "\t���� ������ �������� ������� - ������� 1" << endl;
	cout << "\t���� ������ ��������� ��������� ��������� - ������� 2" << endl;
	cout << "\t���� ������ ��������� � ���� 1 - ������� 3" << endl;
	cout << "\t���� ������ ��������� ������ � ���������� - ������� 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 3)
			cout << "����� ������ �����������! ��������� ������� �����." << endl;
	} while (i < 0 || i > 3);
	return i;
}


int menu3()
{
	cout << "********************************************************************************" << endl;
	cout << "���� 3:";
	cout << "\t���� ������ �������� ������� - ������� 1" << endl;
	cout << "\t���� ������ ������� ������� - ������� 2" << endl;
	cout << "\t���� ������ ������� ������� ������ - ������� 3" << endl;
	cout << "\t���� ������ ������������� ������ �� ������ - ������� 4" << endl;
	cout << "\t���� ������ ������������� ������ �� �������� - ������� 5" << endl;
	cout << "\t���� ������ ������������� ���� �� ��������� - ������� 6" << endl;
	cout << "\t���� ������ ������� ��� ������ ������ - ������� 7" << endl;
	cout << "\t���� ������ ��������� ��������� ��������� - ������� 8" << endl;
	cout << "\t���� ������ ��������� � ���� 1 - ������� 9" << endl;
	cout << "\t���� ������ ��������� ������ � ���������� - ������� 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 9)
			cout << "����� ������ �����������! ��������� ������� �����." << endl;
	} while (i < 0 || i > 9);
	return i;
}

int menu4()
{
	cout << "********************************************************************************" << endl;
	cout << "���� 4:";
	cout << "\t���� ������ �������� ������� - ������� 1" << endl;
	cout << "\t���� ������ ��������� ��������� ��������� - ������� 2" << endl;
	cout << "\t���� ������ ��������� � ���� 1 - ������� 3" << endl;
	cout << "\t���� ������ ��������� ������ � ���������� - ������� 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 3)
			cout << "����� ������ �����������! ��������� ������� �����." << endl;
	} while (i < 0 || i > 3);
	return i;
}


int menu5()
{
	cout << "********************************************************************************" << endl;
	cout << "���� 5:";
	cout << "\t���� ������ �������� ������� - ������� 1" << endl;
	cout << "\t���� ������ ������� ������� - ������� 2" << endl;
	cout << "\t���� ������ ������� ������� ������ - ������� 3" << endl;
	cout << "\t���� ������ ������������� ������ �� ��������� - ������� 4" << endl;
	cout << "\t���� ������ ������������� ������ �� ����� � ������� - ������� 5" << endl;
	cout << "\t���� ������ ������������� ���� �� ������� - ������� 6" << endl;
	cout << "\t���� ������ ������� ��� ������ ������ - ������� 7" << endl;
	cout << "\t���� ������ ��������� ��������� ��������� - ������� 8" << endl;
	cout << "\t���� ������ ��������� � ���� 1 - ������� 9" << endl;
	cout << "\t���� ������ ��������� ������ � ���������� - ������� 0" << endl;
	cout << "********************************************************************************" << endl;
	int i;
	do
	{
		i = input_int();
		if (i < 0 || i > 9)
			cout << "����� ������ �����������! ��������� ������� �����." << endl;
	} while (i < 0 || i > 9);
	return i;
}


//******************������� ��� ������ �� ������� ���������*********************************
void AddContact(vector <Contact> &vec)
{
	Contact temp;
	cout << "������� ������ ������, ������� ������ ��������" << endl;
	temp.input();
	vec.push_back(temp);
}

void DeleteContact(vector <Contact> &vec)
{
	cout << "����� �������� ��� ��������";
	int i = SearchContact(vec);
	vector<Contact>::iterator p = vec.begin();
	p += i;
	vec.erase(p);
}

void OutputContacts(vector <Contact> &vec)
{
	cout << "������ �������� �����:" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i + 1 << "�������:" << endl;
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
		cout << "��� ������ �������� �������" << endl;
		cout << "���: ";
		getline(cin, str1);
		cout << "�������: ";
		getline(cin, str2);
		for (int i = 0; i < vec.size(); i++)
		{
			temp1 = vec[i].GetName();
			temp2 = vec[i].GetSurname();
			if (str1 == temp1 && str2 == temp2)
				return i;	//������� �������� ������ ����� ���������� ����������
		}
		cout << "������ ������ �� �������. ��������� ���� ��� ���." << endl;
	} while (true);
}

void EditContact(vector <Contact> &vec)
{
	cout << "����� �������� ��� ���������" << endl;
	int i = SearchContact(vec);
	cout << "�������� �������:" << endl;
	vec[i].output();
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
		do
		{
			k = input_int();
			if (i < 0 || i > 5)
				cout << "����� ������ �����������! ��������� ������� �����." << endl;
		} while (i < 0 || i > 5);
		//�������� �������� ���������� ������ ������
		cin.ignore(32767, '\n');
		switch (k)
		{
		case 1:
		{
			cout << "������� ������: " << vec[i].GetName() << endl;
			cout << "������� ����� ���: ";
			getline(cin, temp);
			vec[i].SetName(temp);
			break;
		}
		case 2:
		{
			cout << "������� ������: " << vec[i].GetSurname() << endl;
			cout << "������� ����� �������: ";
			getline(cin, temp);
			vec[i].SetSurname(temp);
			break;
		}
		case 3:
		{
			cout << "������� ������: " << vec[i].GetPhone() << endl;
			cout << "������� ����� �������: ";
			getline(cin, temp);
			vec[i].SetPhone(temp);
			break;
		}
		case 4:
		{
			cout << "������� ������: " << vec[i].GetEmail() << endl;
			cout << "������� ����� email: ";
			getline(cin, temp);
			vec[i].SetEmail(temp);
			break;
		}
		case 5:
		{
			cout << "������� ������: " << vec[i].GetNote() << endl;
			cout << "������� ����� �������: ";
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
		cout << "������ �������� �����! ������ �� ����� ���������." << endl;
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
	cout << "�������� ���� �������" << endl;
	vec.clear();
}



//******************������� ��� ������ �� ������� �������***********************************
void AddEvent(vector <Event> &vec)
{
	Event temp;
	cout << "������� ������ ������, ������� ������ ��������" << endl;
	temp.input();
	vec.push_back(temp);
}

void DeleteEvent(vector <Event> &vec)
{
	cout << "����� ������� ��� ��������";
	int i = SearchEvent(vec);
	vector<Event>::iterator p = vec.begin();
	p += i;
	vec.erase(p);
}

void OutputEvents(vector <Event> &vec)
{
	cout << "������ ������ �������:" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << i + 1 << "�������:" << endl;
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
	cout << "����� ������� ��� ���������" << endl;
	int i = SearchEvent(vec);
	cout << "�������� �������:" << endl;
	vec[i].output();
	string temp;
	int k;
	do
	{
		cout << "���� �� ������ ��������" << endl;
		cout << "\t�������� - ������� 1" << endl;
		cout << "\t���� � ����� - ������� 2" << endl;
		cout << "\t����� - ������� 3" << endl;
		cout << "\t�������� - ������� 4" << endl;
		cout << "������� 0, ���� ������ ��������� ��������������." << endl;
		do
		{
			k = input_int();
			if (i < 0 || i > 4)
				cout << "����� ������ �����������! ��������� ������� �����." << endl;
		} while (i < 0 || i > 4);
		//�������� �������� ���������� ������ ������
		cin.ignore(32767, '\n');
		switch (k)
		{
		case 1:
		{
			cout << "������� ������:" << vec[i].GetName() << endl;
			cout << "������� ����� ��������: ";
			getline(cin, temp);
			vec[i].SetName(temp);
			break;
		}
		case 2:
		{
			cout << "������� ������:" << vec[i].GetTad() << endl;
			cout << "������� ����� ���� � �����: ";
			getline(cin, temp);
			vec[i].SetTad(temp);
			break;
		}
		case 3:
		{
			cout << "������� ������:" << vec[i].GetAddress() << endl;
			cout << "������� ����� �����: ";
			getline(cin, temp);
			vec[i].SetAddress(temp);
			break;
		}
		case 4:
		{
			cout << "������� ������:" << vec[i].GetDescription() << endl;
			cout << "������� ����� ��������: ";
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
		cout << "��� ������ ������� �������" << endl;
		cout << "��������: ";
		getline(cin, str1);
		cout << "���� � �����: ";
		getline(cin, str2);
		for (int i = 0; i < vec.size(); i++)
		{
			temp1 = vec[i].GetName();
			temp2 = vec[i].GetTad();
			if (str1 == temp1 && str2 == temp2)
				return i;	//������� �������� ������ ����� ���������� ����������
		}
		cout << "������ ������ �� �������. ��������� ���� ��� ���." << endl;
	} while (true);
}

void SaveEvents(vector <Event> &vec, string FileName)
{
	ofstream file;
	file.open(FileName);
	if (!file.is_open())
	{
		cout << "������ �������� �����! ������ �� ����� ���������." << endl;
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
	cout << "�������� ���� �������" << endl;
	vec.clear();
}


//******************��������� �������*******************************************************
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