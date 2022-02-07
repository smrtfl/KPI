#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

/*Функція обчислення факторіала*/
double fact(int i)
{
	if (i <= 1)
	{
		return 1;
	}
	else
	{
		return i * fact(i - 1);
	}
}

/*Функція обчислення ряду Тейлора*/
double cos(double x1, int n1, double eps1, double sum, double sum0)
{
	double term;

	term = (pow((-1), n1) * pow(x1, 2 * n1)) / fact(2 * n1);

	if (n1 == 0)
	{
		sum = x1;
		cout << "n = " << n1 << "; sum = " << sum << "\n";
		return x1 + cos(x1, n1 + 1, eps1, sum, sum0);
	}
	else if (fabs(sum - sum0) < eps1)
	{
		sum += term;
		cout << "next sum: " << sum << "\n";
		return 0;
	}
	else
	{
		sum0 = sum;
		sum += term;
		cout << "sum - sum0 = " << sum - sum0 << "\n";
		cout << "n = " << n1 << "; sum = " << sum << "\n";
		return term + cos(x1, n1 + 1, eps1, sum, sum0);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double a, b, eps, y;
	double s = 0, s0 = 0;
	double cos_a, cos_b, cos_ab;
	int n = 0;

	cout << "Введіть дійсне a: ";
	cin >> a;
	cout << "Введіть дійсне b: ";
	cin >> b;
	cout << "Введіть точність обчислення: ";
	cin >> eps;

	cout << endl;

	/*Виведення значень ряду cos(a)*/
	cos_a = cos(a, n, eps, s, s0);
	cout << "cos(" << a << ") = " << cos_a << "\n\n";

	/*Виведення значень ряду cos(b)*/
	cos_b = cos(b, n, eps, s, s0);
	cout << "cos(" << b << ") = " << cos_b << "\n\n";

	/*Виведення значень ряду cos(a + b)*/
	cos_ab = cos((a + b), n, eps, s, s0);
	cout << "cos(" << a + b << ") = " << cos_ab << "\n\n";

	/*Кінцевий результат*/
	y = cos_a + pow(cos_b, 2) + cos_ab;

	cout << "y = " << y << endl;
}
