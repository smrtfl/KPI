#pragma once
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <windows.h>
using namespace std;

class Goods
{
public:
	int sum_price()
	{
		return price * amount;
	}

protected:
	string name;
	string date;
	int price;
	int amount;

	virtual void output() = 0;
};