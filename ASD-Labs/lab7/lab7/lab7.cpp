#include <iostream>
#include <iomanip>
#include "windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char a[10], b[10], c[10];
	int average = 0;

	/*Елементи массивів а та b*/
	for (int i = 0; i < 10; i++)
	{
		a[i] = 92 - 3 * i;
		cout << "a[" << i << "] = " << a[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		b[i] = 71 + 3 * i;
		cout << "b[" << i << "] = " << b[i] << " ";
	}

	cout << endl;

	/*Елементи массиву c*/
	for (int i = 0; i < 10; i++)
	{
		if (a[i] == b[i])
		{
			c[i] = a[i];
		}
		else
		{
			c[i] = 0;
		}

		cout << "c[" << i << "] = " << c[i] << "  ";

		/*Середнє арифметичне елементів, коди яких менше 82*/
		if (c[i] < 82)
		{
			average += c[i] / 10;
		}
	}

	cout << "\n\nСереднє арифметичне масиву с[]: " << (char)average << endl;
	cout << "Код середнього арифметичного масиву с[]: " << average << endl;
}

