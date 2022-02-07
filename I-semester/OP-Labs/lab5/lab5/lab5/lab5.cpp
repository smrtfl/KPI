#include <iostream>
using namespace std;

int main()
{
	int n = 1000000, x = 0;

	/*Задаємо інтервал числа х*/
	while (n <= 1000000000)
	{
		int temp = n, rev = 0, num;

		/*"Перегортаємо" числа*/
		while (temp > 0)
		{
			num = temp % 10;
			rev = (rev * 10) + num;
			temp = temp / 10;
		}

		/*Порівнюємо число х з його дзеркальним відображенням*/
		if (rev == n)
		{
			cout << n << " ";
			x++;
		}

		n += 1;
	}

	/*Виводимо число паліндром на інтервалі*/
	cout << "\n" << x << " palindroms";
}

