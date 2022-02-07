//#include <iostream>
//#include "windows.h"
//
//using namespace std;
//
//void input(float**);
//void average_col(float**, float*);
//void sort(float**, float*);
//void output(float**);
//
//void input_a(int**);
//void sort_a(int**, float*);
//void output_a(int**);
//
//
//const int n = 5, m = 7;
//float average;
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float** matrix = new float* [n];
//	for (int i = 0; i < n; i++)
//	{
//		matrix[i] = new float[m];
//	}
//
//	input(matrix);
//
//	average_col(matrix);
//
//	sort(matrix);
//
//	output(matrix)
//}
//
//void input(float** arr)
//{
//	cout << "Початкова матриця:\n";
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = (float)(rand() % 200 - 100) / 10;
//			cout << arr[i][j] << "\t";
//		}
//		cout << "\n";
//	}
//}
//
//void sort(float** arr)
//{
//	float temp;
//
//	for (int k = 0; k < n; k++)
//	{
//		for (int i = 0; i < n - 1; i++)
//		{
//			for (int s = 0; s < m; s++)
//			{
//				for (int j = 0; j < m - 1; j++)
//				{
//					if (average_plus > average)
//					{
//						for (int w = 0; w < 1; w++)
//						{
//							temp = arr[i + w][j + 1];
//							arr[i + w][j + 1] = arr[i + w][j];
//							arr[i + w][j] = temp;
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void output(float** arr)
//{
//	cout << "\n\nВідсортована матриця:\n";
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << arr[i][j] << "\t";
//		}
//		cout << "\n";
//	}
//}