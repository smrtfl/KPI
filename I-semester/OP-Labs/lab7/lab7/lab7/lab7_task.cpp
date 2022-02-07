#include <iostream>
#include "windows.h"
using namespace std;

float arr_b(float*, float*, int);
float maximum(float*, int, int, float);
int maximumi(float*, int, int, int, float);
int counting(float*, int, int, int, float);
void replace(float*, int, float, float, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, z, counter = 0, index = 0;
	float maxb = 0, first = 0;

	cout << "Введіть довжину масиву: ";
	cin >> n;

	float* b = new float[n];
	float x[5];

	cout << "Масив b[]: ";
	arr_b(b, x, n);

	for (int i = 0; i < 5; i++)
	{
		cout << x[i] << " ";
	}

	cout << "\n\nВведіть натуралне z: ";
	cin >> z;

	cout << "\nКількість елементів менших за z: " << counting(b, n, z, counter, maxb);;
	cout << "\nМаксимальне значенння серед цих елементів: b[" << maximumi(b, n, z, index, maxb) << "] = " << maximum(b, n, z, maxb);;

	cout << "\n\nНовий масив b[]: ";
	replace(b, n, first, maximum(b, n, z, maxb), maximumi(b, n, z, index, maxb));
	cout << endl;
}

/*Знаходимо масив B*/
float arr_b(float* arr, float* x1, int n1)
{
	for (int i = 0; i < n1; i++)
	{
		*arr = (float)(rand() % 200 - 100) / 10;
		/*cout << "b[" << i << "] = " << *arr << "\t";*/
		arr++;
	}

	for (int i = 0; i < 5; i++)
	{
		x1[i] = 2,5 * i;
		return x1[i];
	}

	
}

/*Знайходимо кількість елементів менших за z*/
int counting(float* arr, int n1, int z1, int counter1, float maxb1)
{
	maxb1 = *arr;

	for (int i = 0; i < n1; i++)
	{
		if (*arr < z1)
		{
			counter1++;
		}
		arr++;
	}

	return counter1;
}

/*Знайходимо максимум серед елементів менших за z*/
float maximum(float* arr, int n1, int z1, float maxb1)
{
	maxb1 = *arr;

	for (int i = 0; i < n1; i++)
	{
		if (*arr < z1)
		{
			if (*arr > maxb1)
			{
				maxb1 = *arr;
			}
		}
		arr++;
	}

	return maxb1;
}

/*Знайходимо індекс максимуму*/
int maximumi(float* arr, int n1, int z1, int index1, float maxb1)
{
	maxb1 = *arr;

	for (int i = 0; i < n1; i++)
	{
		if (*arr < z1)
		{
			if (*arr > maxb1)
			{
				maxb1 = *arr;
				index1 = i;
			}
		}
		arr++;
	}

	return index1;
}

/*Міняємо перший елемент з максимумом*/
void replace(float* arr, int n1, float first1, float max, int maxi)
{
	for (int i = 0; i < n1; i++)
	{
		if (i == 0)
		{
			first1 = *arr;
			*arr = max;
		}
		else if (i == maxi)
		{
			*arr = first1;
		}
		else
		{
			*arr = *arr;
		}
		cout << "b[" << i << "] = " << *arr << "\t";
		arr++;
	}
}