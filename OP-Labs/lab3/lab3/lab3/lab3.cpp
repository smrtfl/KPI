#include <iostream>
#include <cmath>
#include "windows.h"
using namespace std;

/*Функція розрахування факторіалу від n*/
float fact(int n)
{
    int f = 1, i = 1;

    while (i <= n)
    {
        f = f * i;
        i++;
    }

    return f;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float e = exp(1), x = 1;
    int n = 1, f;

    cout << "Значення e :" << e << "\n\n";

    while (x != e) 
    {
        x += 1 / fact(n);
        n += 1;

        /*Затримка для зручнішого перегляду у консолі*/
        Sleep(1000);

        cout << "Поточне значення х: " << x << endl;
    }

    /*Додаткове повідомлення про успішне завершення програми*/
    if (x == e)
    {
        cout << "\nТепер х = е! Щоб перетворити х на е, знадобилося зробити " << n << " дій!\n";
    }

    return 0;
}

