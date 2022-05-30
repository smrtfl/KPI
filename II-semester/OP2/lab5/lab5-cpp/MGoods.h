#pragma once
#include "Goods.h"

class MGoods : public Goods
{
private:
	string transporting;
	string status;
public:
	MGoods(string c_name, string c_date, int c_price, int c_amount, string c_transporting, string c_status);
	void output();
	string get_status();
};