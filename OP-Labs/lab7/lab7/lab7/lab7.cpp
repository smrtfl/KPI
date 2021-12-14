#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, z, count = 0, index = 0;
	
	cout << "Введіть довжину масиву: ";
	cin >> n;

	float *b = new float[n];

	cout << "Масив b[]: ";

	for (int i = 0; i < n; i++)
	{
		b[i] = (float)(rand() % 2000 - 1000) / 100;
		cout << "b[" << i << "] = " << b[i] << "\t";
	}

	cout << "\n\nВведіть натуралне z: ";
	cin >> z;

	float max = b[0], temp;

	for (int i = 0; i < n; i++)
	{
		if (b[i] < z)
		{
			
			if (b[i] > max)
			{
				max = b[i];
				index = i;
			}
			count++;
		}
	}

	cout << "Кількість елементів менших за z: " << count;
	cout << "\nМаксимальне значенння серед цих елементів: b[" << index << "] = " << max;

	for (int i = 0; i < n; i++)
	{
		if (b[i] == max)
		{
			temp = b[0];
			b[0] = b[i];
			b[i] = temp;
		}
	}

	cout << "\n\nНовий масив b[]: ";

	for (int i = 0; i < n; i++)
	{
		cout << "b[" << i << "] = " << b[i] << "\t";
	}

	cout << endl;
}

