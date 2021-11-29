#include <iostream>
#include <windows.h>
using namespace std;

/*Функція обчислення факторіала*/
int fact(int i)
{
	if (i == 0)
	{
		return 1;
	}
	else
	{
		return i * fact(i - 1);
	}
}

/*Функція обчислення ряду Тейлора*/
float cos(float x1, int n1, float eps1)
{
	float sum;

	sum = (pow((-1), n1) * pow(x1, 2 * n1)) / fact(2 * n1);

	if (fabs(sum) < eps1)
	{
		return 0;
	}
	else
	{
		return sum + cos(x1, n1 + 1, eps1);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float a, b, eps, y;
	int n = 0;

	cout << "Введіть дійсне a: ";
	cin >> a;
	cout << "Введіть дійсне b: ";
	cin >> b;
	cout << "Введіть точність обчислення: ";
	cin >> eps;

	y = cos(a, n, eps) + pow(cos(b, n, eps), 2) + cos(a + b, n, eps);

	cout << "\ny = " << y << endl;