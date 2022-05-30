#pragma once
#include "Goods.h"
using namespace std;

class FGoods : public Goods
{
private:
	string end_date;
public:
	FGoods(string c_name, string c_date, int c_price, int c_amount, string c_end_date);
	void output();
	int overdue_check();
};