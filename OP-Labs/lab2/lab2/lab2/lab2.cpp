﻿#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float x, ota, y;

    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть ординату точки A: ";
    cin >> ota;

    if (x >= 0)
        y = ota;
    else
        y = x;

    cout << "\nЗначення функції f(x) =" << y << "\n";

    return 0;
}