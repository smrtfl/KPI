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
//	cout << "������ ������� ������: ";
//	cin >> n;
//
//	float* b = new float[n];
//
//	cout << "����� b[]: ";
//	arr_b(b);
//
//	cout << "\n\n������ ��������� z: ";
//	cin >> z;
//	maximum(b);
//
//	cout << "\n\n����� ����� b[]: ";
//	replace(b);
//
//	cout << endl;
//}
//
///*��������� ����� B*/
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
///*���������� ������� �������� ������ �� z �� �� ��������*/
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
//	cout << "\nʳ������ �������� ������ �� z: " << counter;
//	cout << "\n����������� ��������� ����� ��� ��������: b[" << index << "] = " << maxb;
//}
//
///*̳����� ������ ������� � ����������*/
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