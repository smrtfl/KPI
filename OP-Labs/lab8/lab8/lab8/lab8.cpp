#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m;
    int row_maxc = 0, row_minc = 0, column_maxc = 0, column_minc = 0;
    int row_maxb = 0, row_minb = 0, column_maxb = 0, column_minb = 0;

    cout << "n рядків: ";
    cin >> n;
    cout << "m стовпців: ";
    cin >> m;

    /*Матриця C*/
    float** c = new float* [n];
    for (int i = 0; i < n; i++)
    {
        c[i] = new float[m];
    }

    /*Матриця B*/
    float** b = new float* [n];
    for (int i = 0; i < n; i++)
    {
        b[i] = new float[m];
    }

    /*Матриця Y*/
    float** y = new float* [n];
    for (int i = 0; i < n; i++)
    {
        y[i] = new float[m];
    }

    /*Матриця Z*/
    float** z = new float* [n];
    for (int i = 0; i < n; i++)
    {
        z[i] = new float[m];
    }

    cout << "\nМатриця C: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i][j] = (float)(rand() % 2000 - 1000) / 100;
            cout << c[i][j] << "\t";
        }
        cout << "\n";
    }

    float maxc = c[0][0], minc = c[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] > maxc)
            {
                maxc = c[i][j];
                row_maxc = i;
                column_maxc = j;
            }
            else if (c[i][j] < minc)
            {
                minc = c[i][j];
                row_minc = i;
                column_minc = j;
            }
        }
    }

    cout << "\nМаксимальне значення матриці C: c[" << row_maxc << "][" << column_maxc << "] = " << maxc;
    cout << "\nМінімальне значення матриці C: c[" << row_minc << "][" << column_minc << "] = " << minc;

    cout << "\n\nМатриця Y (модифікована C): \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == row_maxc)
            {
                y[i][j] = c[row_minc][j];
            }
            else if (i == row_minc)
            {
                y[i][j] = c[row_maxc][j];
            }
            else
            {
                y[i][j] = c[i][j];
            }
            cout << y[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n--------------------------------------------------";

    cout << "\n\nМатриця B: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i][j] = (float)(rand() % 2000 - 1000) / 100;
            cout << b[i][j] << "\t";
        }
        cout << "\n";
    }

    float maxb = b[0][0], minb = b[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] > maxb)
            {
                maxb = b[i][j];
                row_maxb = i;
                column_maxb = j;
            }
            else if (b[i][j] < minb)
            {
                minb = b[i][j];
                row_minb = i;
                column_minb = j;
            }
        }
    }

    cout << "\nМаксимальне значення матриці B: b[" << row_maxb << "][" << column_maxb << "] = " << maxb;
    cout << "\nМінімальне значення матриці B: b[" << row_minb << "][" << column_minb << "] = " << minb;

    cout << "\n\nМатриця Z (модифікована B): \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == row_maxb)
            {
                z[i][j] = b[row_minb][j];
            }
            else if (i == row_minb)
            {
                z[i][j] = b[row_maxb][j];
            }
            else
            {
                z[i][j] = b[i][j];
            }
            cout << z[i][j] << "\t";
        }
        cout << "\n";
    }
}

