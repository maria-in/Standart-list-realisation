#include "List_double.h"
#include "Exception.h"
#include <iostream>

int main()
{
	try
	{
		setlocale(LC_ALL, ".1251");
		List_double L;							// ������� ������ ������

		/*double x = L.Top();						// ��������� �������� �������� � ������ ������
		L.ListPrint();	*/							//������
		//L.ForEach(Print); //2-�� ������ ������
		L.InsertFirst(10.5);						// ������� ��� �������� � ������ ������
		L.InsertFirst(20.6);
		L.InsertFirst(30.7);

		L.ListPrint();

		cout << "����������� �����������" << endl;
		List_double M = L; // ����������� �����������

		cout << "������ M: " << endl;
		M.ListPrint(); //1-�� ������ ������
		//M.ForEach(Print); //2-�� ������ ������
		cout << endl;
		double a = L.Top();						// ��������� �������� �������� � ������ ������

		cout << "������� � ������ ������ = ";
		cout << a << endl;
		cout << endl;

		if (L.DeleteFirst())					// ������ ������� �� ������
		{
			cout << "����� ��������" << endl;
			L.ListPrint();
		}

		else
			cout << "������ ����" << endl;

		cout << endl;


		L.InsertFirst(40.8);						// ������� ������� � ������ ������
		L.ListPrint();

		cout << endl;

		cout << "���������� � ����� ������" << endl;
		L.InsertLast(50.9);						//������� ������� � ����� ������
		L.ListPrint();
		cout << endl;

		cout << "���������� � ����� ������" << endl;
		L.InsertLast(60.7);						//������� ������� � ����� ������
		L.ListPrint();
		cout << endl;

		if (L.DeleteFirst())					// ������ ������� �� ������

		{
			cout << "����� ��������" << endl;
			L.ListPrint();
		}
		else
			cout << "������ ����" << endl;
		cout << endl;

		if (L.DeleteLast())					// ������ ������� �� �����

		{
			cout << "����� ��������" << endl;
			L.ListPrint();
		}
		else
			cout << "������ ����" << endl;
		cout << endl;

		cout << "�������� �������� �� ��������" << endl;
		if (L.DeleteByValue(30.7))					// ������ ������� �� ��������

		{
			cout << "����� ��������" << endl;
			L.ListPrint();
		}
		else
			cout << "��� ������ ��������" << endl;
		cout << endl;

		cout << "����� ����� ��������� ��������" << endl;
		if (L.Find(20.6) == 0)
			cout << "��� ������ ��������" << endl;
		else
		cout << L.Find(20.6) << endl;
		cout << endl;

		cout << "������ M: " << endl;
		M.ListPrint();
		M.Erase();								// ������� ������ M
		M.ListPrint();
		cout << endl;

		M.InsertFirst(11.8);						// ������� ��� �������� � ������ ������ M
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