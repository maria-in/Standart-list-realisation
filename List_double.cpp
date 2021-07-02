#include "List_double.h"
#include "Exception.h"
#include <iostream>

//����������� ��� ����������, �������� ������� �������
List_double::List_double() : First(NULL) {}

// ������������
void List_double::Clone(const List_double &L)
{
	ListItem *p, *q, *r;
	r = NULL;
	p = L.First;
	while (p != NULL)
	{
		q = new ListItem;
		q->Info = p->Info;
		q->Next = NULL;
		if (r == NULL)
			First = q;
		else
			r->Next = q;
		r = q;
		p = p->Next;
	}
}

// ����������� �����������
List_double::List_double(const List_double& L)
{
	Clone(L);
}

// �������� ������������
const List_double & List_double::operator = (const List_double &L)
{
	if (&L == this)
		return *this; // �������� �� ����������������
	Erase();
	Clone(L);
	return *this;
}


// ����������
List_double::~List_double()
{
	Erase();
}

// ���������� ������ �������� � ������ ������
void List_double::InsertFirst(const double &AInfo)
{
	ListItem *P = new ListItem;
	P->Info = AInfo;
	P->Next = First;
	First = P;
}

//���������� � �����
void List_double::InsertLast(const double &AInfo)
{
	if (First == NULL)
	{
		InsertFirst(AInfo);
		return;
	}
	ListItem *p = First;
	while (p->Next != NULL)
	{
		p = p->Next;
	}
	p->Next = new ListItem{ AInfo, NULL };
}

// �������� �������� �� ������ ������
bool List_double::DeleteFirst()
{
	if (First == NULL)
		throw Exception("Your list is empty");
		//return false; // ������ ������
	ListItem *P = First;
	First = First->Next;
	delete P;
	return true;
}

//�������� �������� �� ����� ������
bool List_double::DeleteLast()
{
	if (First == NULL)
		throw Exception("Your list is empty");
	//	return false; // ������ ������
	ListItem *P = First;
	if (P->Next == NULL)
	{
		delete P;
		First = NULL;
		return true;
	}
	ListItem *L = P->Next;
	while (L->Next != NULL)
	{
		L = L->Next;
		P = P->Next;
	}
	delete L;
	P->Next = NULL;
	return true;
}

bool List_double::DeleteByValue(double AInfo)
{
	if (First == NULL)
		return false; // ������ ������
	ListItem *P = First;
	if (P->Next == NULL)
	{
		if (P->Info == AInfo) {
			delete P;
			First = NULL;
			return true;
		}
		return false;
	}
	ListItem *L = P->Next;
	while (L->Next != NULL)
	{
		if (L->Info == AInfo)
			break;
		L = L->Next;
		P = P->Next;
	}
	if (L->Info == AInfo)
	{
		P->Next = L->Next;
		delete L;
		return true;
	}
	return false;
}

int List_double::Find(double AInfo)
{
	int counter = 0;
	int ccounter = 0;
	ListItem *P = First;
	while (P != NULL)
	{
		counter++;
		if (P->Info != AInfo)
			ccounter++;
		if (P->Info == AInfo)
			break;
		P = P->Next;
	}
	if (counter == ccounter)	return 0;
	return counter;
}


// ���������� ������ ������� ������
const double List_double::Top() const
{
	if (First == NULL)
		throw Exception("Your list is empty");
	double x = First->Info;
	return x;
}

// �������� ������
void List_double::Erase()
{
	ListItem *p, *q;
	p = First;
	while (p != NULL)
	{
		q = p->Next;
		delete p;
		p = q;
	}
	First = NULL;
}


// ������ ��������� ������ 1-�� ������
void List_double::ListPrint()const
{
	ListItem *P = First;
	if (P == NULL)
		cout << "������ ����" << endl;
	if (P != NULL)
	{
		cout << "���������� ������" << endl;
		while (P != NULL)
		{
			cout << P->Info << endl;
			P = P->Next;
		}
	};
}// ������ ��������� ������ 2-�� ������
void Print(double x)
{
	cout << x << endl;
}

void List_double::ForEach(void Fun(double))const
{
	ListItem *P = First;
	if (P == NULL)
		cout << "������ ����" << endl;
	if (P != NULL)
	{
		cout << "���������� ������" << endl;
		while (P != NULL)
		{
			Fun(P->Info);
			P = P->Next;
		}
	};
}void List_double::ForEach(void Fun(double&))
{
	ListItem *P = First;
	if (P == NULL)
		cout << "������ ����" << endl;
	if (P != NULL)
	{
		cout << "���������� ������" << endl;
		while (P != NULL)
		{
			Fun(P->Info);
			P = P->Next;
		}
	};
}