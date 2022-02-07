#include <iostream>
#include <cmath>
#include "windows.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x1, y1, x2, y2, x3, y3;
	float AB, BC, AC;
	float P, HP, S;

	/*Точка А*/
	cout << "Введіть значення x1: ";
	cin >> x1;
	cout << "Введіть значення y1: ";
	cin >> y1;

	/*Точка B*/
	cout << "Введіть значення x2: ";
	cin >> x2;
	cout << "Введіть значення y2: ";
	cin >> y2;

	/*Точка C*/
	cout << "Введіть значення x3: ";
	cin >> x3;
	cout << "Введіть значення y3: ";
	cin >> y3;

	/*Сторони трикутника*/
	AB = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	BC = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	AC = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));

	/*Периметр трикутника*/
	P = AB + BC + AC;

	/*Півпериметр трикутник*/
	HP = P / 2;

	/*Площа трикутника*/
	S = sqrt(HP * (HP - AB) * (HP - BC) * (HP - AC));

	/*Вивід результату*/
	cout << "Периметр трикутника ABC: " << P << endl;
	cout << "Площа трикутника ABC: " << S << endl;

	return 0;
}