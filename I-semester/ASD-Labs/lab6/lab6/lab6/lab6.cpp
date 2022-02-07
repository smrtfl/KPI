#include <iostream> 
using namespace std;

/*Функція розрахування факторіалу*/
int fact(int i)
{
    if (i == 0)
    {
        return 1;
    }
    else
    {
        return i * fact(i - 1);
    }
}

/*Функція розрахування комбінацій*/
int comb(int n1, int m1)
{   
    if ((m1 == 0 && n1 > 0) || (m1 == n1 && n1 >= 0))
    {
        return 1;
    }
    else if (m1 > n1 && n1 >= 0)
    {
        return 0;
    }
    else
    {
        return fact(n1) / (fact(m1) * fact(n1 - m1));
    }
}

int main()
{
    int m, n, x;

    cout << "input m: ";
    cin >> m;
    cout << "input n: ";
    cin >> n;

    x = comb(n - 1, m - 1) + comb(n - 1, m);

    cout << x;
}


