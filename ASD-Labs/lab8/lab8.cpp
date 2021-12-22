#include <iostream>
#include "windows.h"

using namespace std;

/*Протипи функції*/
void input(float**);
void average_col(float**, float*);
void sort(float**, float*);
void output(float**);

const int n = 5, m = 7;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Ініціалізація матриці*/
	float** matrix = new float* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new float[m];
	}

	float* average = new float[m];

	/*Задаємо матрицю*/
	input(matrix);

	/*Середнє арифметичне додатних елементів стовпця*/
	average_col(matrix, average);

	/*Сортування обміном*/
	sort(matrix, average);

	/*Виведення матриці*/
	output(matrix);
}

void input(float** arr)
{
	cout << "Початкова матриця:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = (float)(rand() % 200 - 100) / 10;
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

void average_col(float** arr, float* ave)
{
	for (int j = 0; j < m; j++)
	{
		int count = 0;
		ave[j] = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] > 0)
			{
				ave[j] += arr[i][j];
				count++;
			}
		}

		ave[j] /= count;
		cout << "\nСереднє арифметичне стовпця №" << j << ": " << ave[j];
	}
}

void sort(float** arr, float* ave)
{
	float temp;

	for (int k = 1; k < m; k++)
	{
		for (int j = 0; j < m - k; j++)
		{
			if (ave[j + 1] > ave[j])
			{
				for (int i = 0; i < n; i++)
				{
					temp = arr[i][j + 1];
					arr[i][j + 1] = arr[i][j];
					arr[i][j] = temp;
				}

				temp = ave[j + 1];
				ave[j + 1] = ave[j];
				ave[j] = temp;
			}
		}
	}
}

void output(float** arr)
{
	cout << "\n\nВідсортована матриця:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

