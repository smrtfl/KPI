#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Ініціалізація змінних*/
	float a, b, h, ri;
	int n;

	/*Введення числа n*/
	cout << "Введіть натуральне число n: ";
	cin >> n;

	/*Введення числа a*/
	cout << "Введіть дійсне число a: ";
	cin >> a;

	/*Введення числа b*/
	cout << "Введіть дійсне число b: ";
	cin >> b;

	/*Обчислення числа h*/
	h = (b - a) / n;

	/*Пошук елементів послідовності R*/
	cout << "\n" << "Послідовність чисел r:" << endl;
	for (int i = 1; i <= n; i++)
	{
		ri = a + i * h;
		cout << "r" << i << " = " << ri << endl;
	}

	return 0;
}
