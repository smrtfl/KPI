#include <iostream>
#include <cstring>
#include <vector>
#include "funcs.h"
using namespace std;

int main()
{
    vector<MGoods> manufacture_goods;
    vector<FGoods> food_goods;

    init_goods(manufacture_goods, food_goods);
    output_goods(manufacture_goods, food_goods);
    calculations(manufacture_goods, food_goods);

    cout << endl;
}