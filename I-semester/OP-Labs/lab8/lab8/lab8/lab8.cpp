#include <iostream>
#include "windows.h"
using namespace std;

void arr_start(float**);

void ext_c(float**);
void ext_b(float**);

void arr_y(float**, float**);
void arr_z(float**, float**);

int n, m;
int row_maxc, row_minc, column_maxc, column_minc;
int row_maxb, row_minb, column_maxb, column_minb;
float maxc, minc, maxb, minb;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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

    cout << "\nМатриця С" << endl;
    arr_start(c);

    ext_c(c);

    cout << "\n\nМатриця Y (модифікована C): \n";
    arr_y(y, c);

    cout << "\n--------------------------------------------------\n";
    
    cout << "\nМатриця B" << endl;
    arr_start(b);

    ext_b(b);

    cout << "\n\nМатриця Z (модифікована Z): \n";
    arr_z(z, b);
}

/*Задаємо масиви С та В*/
void arr_start(float** arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = (float)(rand() % 2000 - 1000) / 100;
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

/*Мінімум та максимум масиву С*/
void ext_c(float** arr)
{
    maxc = arr[0][0], minc = arr[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > maxc)
            {
                maxc = arr[i][j];
                row_maxc = i;
                column_maxc = j;
            }
            else if (arr[i][j] < minc)
            {
                minc = arr[i][j];
                row_minc = i;
                column_minc = j;            
            }
        }
    }
    cout << "\nМаксимальне значення матриці C: c[" << row_maxc << "][" << column_maxc << "] = " << maxc;
    cout << "\nМінімальне значення матриці C: c[" << row_minc << "][" << column_minc << "] = " << minc;
}

/*Мінімум та максимум масиву В*/
void ext_b(float** arr)
{
    maxb = arr[0][0], minb = arr[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > maxb)
            {
                maxb = arr[i][j];
                row_maxb = i;
                column_maxb = j;
            }
            else if (arr[i][j] < minb)
            {
                minb = arr[i][j];
                row_minb = i;
                column_minb = j;
            }
        }
    }
    cout << "\nМаксимальне значення матриці B: b[" << row_maxb << "][" << column_maxb << "] = " << maxb;
    cout << "\nМінімальне значення матриці B: b[" << row_minb << "][" << column_minb << "] = " << minb;
}

/*Знаходимо масив Y*/
void arr_y(float** arr1, float** arr2)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == row_maxc)
            {
                arr1[i][j] = arr2[row_minc][j];
            }
            else if (i == row_minc)
            {
                arr1[i][j] = arr2[row_maxc][j];
            }
            else
            {
                arr1[i][j] = arr2[i][j];
            }
            cout << arr1[i][j] << "\t";
        }
        cout << "\n";
    }
}

/*Знаходимо масив Z*/
void arr_z(float** arr1, float ** arr2)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == row_maxb)
            {
                arr1[i][j] = arr2[row_minb][j];
            }
            else if (i == row_minb)
            {
                arr1[i][j] = arr2[row_maxb][j];
            }
            else
            {
                arr1[i][j] = arr2[i][j];
            }
            cout << arr1[i][j] << "\t";
        }
        cout << "\n";
    }
}