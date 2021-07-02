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
	void InsertFirst(const double&);	//добавление элемента в начало списка+
	bool DeleteFirst();					// удаление элемента из начала списка+
	const double Top() const;				// посмотреть первый элемент списка+
	void ListPrint() const;				// печать элементов списка+
	void ForEach(void(double))const;		// выполнить действия над всеми элементами списка, не изменяя его+
	void ForEach(void(double&));			// выполнить действия над всеми элементами списка, изменяя его+
	void InsertLast(const double &AInfo);	//+
	bool DeleteLast();						//+
	bool DeleteByValue(double);				//+
	int Find(double AInfo);					//+
	List_double(const List_double&);	// конструктор копирования
	const List_double & operator = (const List_double &); // оператор присваивания
	virtual~List_double();				// деструктор
	void Erase();						// удаление элементов списка списка
protected:
	void Clone(const List_double &);	// клонирование
};
