//#include <iostream>
//#include "windows.h"
//using namespace std;
//
//void arr_b(float*);
//void maximum(float*);
//void replace(float*);
//
//int n, z, counter = 0, index = 0;
//float maxb, first;
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	cout << "Введіть довжину масиву: ";
//	cin >> n;
//
//	float* b = new float[n];
//
//	cout << "Масив b[]: ";
//	arr_b(b);
//
//	cout << "\n\nВведіть натуралне z: ";
//	cin >> z;
//	maximum(b);
//
//	cout << "\n\nНовий масив b[]: ";
//	replace(b);
//
//	cout << endl;
//}
//
///*Знаходимо масив B*/
//void arr_b(float* arr)
//{
//	for (int i = 0; i < n; i++)
//	{
//		*arr = (float)(rand() % 200 - 100) / 10;
//		if (i == 0)
//		{
//			first = *arr;
//		}
//		cout << "b[" << i << "] = " << *arr << "\t";
//		arr++;
//	}
//}
//
///*Знайходимо кількість елементів менших за z та їх максимум*/
//void maximum(float* arr)
//{
//	maxb = *arr;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (*arr < z)
//		{
//
//			if (*arr > maxb)
//			{
//				maxb = *arr;
//				index = i;
//			}
//			counter++;
//		}
//		arr++;
//	}
//	cout << "\nКількість елементів менших за z: " << counter;
//	cout << "\nМаксимальне значенння серед цих елементів: b[" << index << "] = " << maxb;
//}
//
///*Міняємо перший елемент з максимумом*/
//void replace(float* arr)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (i == 0)
//		{
//			*arr = maxb;
//		}
//		else if (i == index)
//		{
//			*arr = first;
//		}
//		else
//		{
//			*arr = *arr;
//		}
//		cout << "b[" << i << "] = " << *arr << "\t";
//		arr++;
//	}
//}