#pragma once
#include <iostream>
using namespace std;

class List_double
{
protected:
	struct ListItem {
		double Info;
		ListItem *Next;
	};
	ListItem *First;
public:
	List_double();
	void InsertFirst(const double&);	//���������� �������� � ������ ������+
	bool DeleteFirst();					// �������� �������� �� ������ ������+
	const double Top() const;				// ���������� ������ ������� ������+
	void ListPrint() const;				// ������ ��������� ������+
	void ForEach(void(double))const;		// ��������� �������� ��� ����� ���������� ������, �� ������� ���+
	void ForEach(void(double&));			// ��������� �������� ��� ����� ���������� ������, ������� ���+
	void InsertLast(const double &AInfo);	//+
	bool DeleteLast();						//+
	bool DeleteByValue(double);				//+
	int Find(double AInfo);					//+
	List_double(const List_double&);	// ����������� �����������
	const List_double & operator = (const List_double &); // �������� ������������
	virtual~List_double();				// ����������
	void Erase();						// �������� ��������� ������ ������
protected:
	void Clone(const List_double &);	// ������������
};
