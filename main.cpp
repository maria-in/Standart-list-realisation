#include "List_double.h"
#include "Exception.h"
#include <iostream>

int main()
{
	try
	{
		setlocale(LC_ALL, ".1251");
		List_double L;							// создаем пустой список

		/*double x = L.Top();						// посмотрим значение элемента в начале списка
		L.ListPrint();	*/							//печать
		//L.ForEach(Print); //2-ой способ печати
		L.InsertFirst(10.5);						// добавим три элемента в начало списка
		L.InsertFirst(20.6);
		L.InsertFirst(30.7);

		L.ListPrint();

		cout << " онструктор копировани€" << endl;
		List_double M = L; //  онструктор копировани€

		cout << "список M: " << endl;
		M.ListPrint(); //1-ый способ печати
		//M.ForEach(Print); //2-ой способ печати
		cout << endl;
		double a = L.Top();						// посмотрим значение элемента в начале списка

		cout << "Ёлемент в начале списка = ";
		cout << a << endl;
		cout << endl;

		if (L.DeleteFirst())					// удалим элемент из начала
		{
			cout << "после удалени€" << endl;
			L.ListPrint();
		}

		else
			cout << "список пуст" << endl;

		cout << endl;


		L.InsertFirst(40.8);						// добавим элемент в начало списка
		L.ListPrint();

		cout << endl;

		cout << "добавление в конец списка" << endl;
		L.InsertLast(50.9);						//добавим элемент в конец списка
		L.ListPrint();
		cout << endl;

		cout << "добавление в конец списка" << endl;
		L.InsertLast(60.7);						//добавим элемент в конец списка
		L.ListPrint();
		cout << endl;

		if (L.DeleteFirst())					// удалим элемент из начала

		{
			cout << "после удалени€" << endl;
			L.ListPrint();
		}
		else
			cout << "список пуст" << endl;
		cout << endl;

		if (L.DeleteLast())					// удалим элемент из конца

		{
			cout << "после удалени€" << endl;
			L.ListPrint();
		}
		else
			cout << "список пуст" << endl;
		cout << endl;

		cout << "удаление элемента по значению" << endl;
		if (L.DeleteByValue(30.7))					// удалим элемент по значению

		{
			cout << "после удалени€" << endl;
			L.ListPrint();
		}
		else
			cout << "нет такого элемента" << endl;
		cout << endl;

		cout << "поиск места заданного элемента" << endl;
		if (L.Find(20.6) == 0)
			cout << "нет такого элемента" << endl;
		else
		cout << L.Find(20.6) << endl;
		cout << endl;

		cout << "список M: " << endl;
		M.ListPrint();
		M.Erase();								// ќчистим список M
		M.ListPrint();
		cout << endl;

		M.InsertFirst(11.8);						// добавим два элемента в начало списка M
		M.InsertFirst(22.7);
		M.ListPrint();
		cout << endl;

	}
	catch (Exception &ex)
	{
		cout << ex.what() << endl;
	}
	system("pause");
	return 0;
}